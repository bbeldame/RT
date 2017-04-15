/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 19:20:10 by bbeldame          #+#    #+#             */
/*   Updated: 2017/04/15 21:56:18 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

/*
** take : "camera:"
** returns "camera"
*/

char	*trim_setting(t_env *e, char *line)
{
	line = ft_strtrim(line);
	if (line[ft_strlen(line) - 1] != ':')
		syntax_error(line, "Missing ':'", e->nbline);
	line[ft_strlen(line) - 1] = '\0';
	return (line);
}

/*
** Library of function, dispatch lines to the right handler
*/

void	dispatch(t_env *e, char *line)
{
	int		isHandle;

	isHandle = 0;
	line = trim_setting(e, line);
	if (!ft_strcmp(line, "camera") && isHandle++)
		set_camera(e);
	if (!ft_strcmp(line, "light") && isHandle++)
		set_light(e);
	if (!ft_strcmp(line, "sphere") && isHandle++)
		set_sphere(e);
	if (!ft_strcmp(line, "plane") && isHandle++)
		set_plane(e);
	if (!ft_strcmp(line, "cylinder") && isHandle++)
		set_cylinder(e);
	if (!ft_strcmp(line, "cone") && isHandle++)
		set_cone(e);
	if (!isHandle)
		unknown_setting(line, e->nbline);
}

/*
** take a .rtv1 file as parameter and parse the content into the t_env
*/

t_env	*parse(char *scene)
{
	t_env		*e;
	char		*line;

	e = (t_env *)semalloc(sizeof(t_env));
	if ((e->fd = open(scene, O_RDONLY)) == -1)
		err_found("open failed");
	e->nbline = 0;
	while (get_next_line(e->fd, &line))
	{
		e->nbline += 1;
		dispatch(e, line);
		free(line);
	}
	if (close(e->fd) == -1)
		err_found("close failed");
	return (e);
}
