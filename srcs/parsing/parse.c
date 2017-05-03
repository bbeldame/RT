/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 19:20:10 by bbeldame          #+#    #+#             */
/*   Updated: 2017/05/03 17:48:21 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void	set_default(t_env *e)
{
	e->setup.supersampling = DEFAULT_SUPERSAMPLING;
}

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

char	*trim_setting(t_env *e, char *setting)
{
	char	*trimmed_setting;

	if (!setting || setting[0] == '\0')
		return ("\0");
	trimmed_setting = ft_strtrim(setting);
	if (trimmed_setting[0] == '#')
		return (trimmed_setting);
	if (trimmed_setting[ft_strlen(trimmed_setting) - 1] != ':' &&
		trimmed_setting[ft_strlen(trimmed_setting) - 1] != '1' &&
		trimmed_setting[ft_strlen(trimmed_setting) - 1] != '0')
		syntax_error(setting, "Missing ':'", e->nbline);
	trimmed_setting[ft_strlen(trimmed_setting) - 1] = '\0';
	return (trimmed_setting);
}

/*
** Library of function, dispatch lines to the right handler
*/

void	dispatch(t_env *e, char *line)
{
	char	*setting;

	setting = trim_setting(e, line);
	if (!ft_strcmp(setting, "supersampling: "))
		set_supersampling(e, line);
	else if (!ft_strcmp(setting, "light"))
		set_light(e);
	else if (!ft_strcmp(setting, "sphere"))
		set_sphere(e);
	else if (!ft_strcmp(setting, "plane"))
		set_plane(e);
	else if (!ft_strcmp(setting, "cylinder"))
		set_cylinder(e);
	else if (!ft_strcmp(setting, "cone"))
		set_cone(e);
	else if (!setting || setting[0] == '\0' || setting[0] == '#')
		return ;
	else
		unknown_setting(setting, e->nbline);
	free(setting);
}

/*
** take a .rtv1 file as parameter and parse the content into the t_env
*/

t_env	*parse(char *scene)
{
	t_env		*e;
	char		*line;

	e = (t_env *)semalloc(sizeof(t_env));
	set_default(e);
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
	e->setup.camera = c_vector(0, 0, 0);
	return (e);
}
