/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 19:20:10 by bbeldame          #+#    #+#             */
/*   Updated: 2017/04/18 17:39:45 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

/*
** take : "origin: 3 0 -10"
** returns "origin" and put "3 0 -10" into arg
*/

char	*trim_option(t_env *e, char *option, char **arg)
{
	char	**line;
	char	*trimmed_option;

	line = ft_strsplit(option, ':');
	if (len_of_tab(line) != 2)
		syntax_error(option, "Multiple settings", e->nbline);
	trimmed_option = ft_strtrim(line[0]);
	*arg = ft_strdup(line[1]);
	free_splited_str(line);
	return (trimmed_option);
}

/*
** take : "camera:"
** returns "camera"
*/

char	*trim_setting(t_env *e, char *line)
{
	if (!line)
		return ("\0");
	line = ft_strtrim(line);
	if (line[0] == '#')
		return (line);
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
	line = trim_setting(e, line);
	if (!ft_strcmp(line, "camera"))
		set_camera(e);
	else if (!ft_strcmp(line, "light"))
		set_light(e);
	else if (!ft_strcmp(line, "sphere"))
		set_sphere(e);
	else if (!ft_strcmp(line, "plane"))
		set_plane(e);
	else if (!ft_strcmp(line, "cylinder"))
		set_cylinder(e);
	else if (!ft_strcmp(line, "cone"))
		set_cone(e);
	else if (line[0] == '\0' || line[0] == '#')
		return ;
	else
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
	e->obj = NULL;
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
