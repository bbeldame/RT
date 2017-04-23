/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_setup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 21:47:21 by bbeldame          #+#    #+#             */
/*   Updated: 2017/04/24 01:02:14 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void		set_camera(t_env *e)
{
	char	*option;
	char	*option_arg;

	e->nbline++;
	if (get_next_line(e->fd, &option) == 1 && option[0] == ' ')
	{
		option = trim_option(e, option, &option_arg);
		if (!ft_strcmp("origin", option))
			e->camera = set_vector(e, option_arg);
		else if (!ft_strcmp("fov", option))
			e->fov = ft_atoi(option_arg);
		free(option);
		set_camera(e);
	}
	else
		dispatch(e, option);
}

void		set_light(t_env *e)
{
	static t_light	*light;
	char			*option;
	char			*option_arg;

	if (!light)
		light = (t_light *)semalloc(sizeof(t_light));
	e->nbline++;
	if (get_next_line(e->fd, &option) == 1 && option[0] == ' ')
	{
		option = trim_option(e, option, &option_arg);
		if (!ft_strcmp("origin", option))
			light->origin = set_vector(e, option_arg);
		else if (!ft_strcmp("intensity", option))
			light->intensity = ft_atof(option_arg);
		else
			unknown_option(option, e->nbline, "sphere");
		free(option);
		set_light(e);
	}
	else
	{
		set_first_light(e, light);
		light = NULL;
		dispatch(e, option);
	}
}