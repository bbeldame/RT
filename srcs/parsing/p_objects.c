/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_objects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 21:47:24 by bbeldame          #+#    #+#             */
/*   Updated: 2017/04/18 17:43:15 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

void		set_sphere(t_env *e)
{
	static t_object		*sphere;
	char				*option;
	char				*option_arg;

	if (!sphere)
		sphere = (t_object *)semalloc(sizeof(t_object));
	sphere->type = SPHERE;
	e->nbline++;
	if (get_next_line(e->fd, &option) == 1 && option[0] == ' ')
	{
		option = trim_option(e, option, &option_arg);
		if (!ft_strcmp("origin", option))
			sphere->origin = set_vector(e, option_arg);
		else if (!ft_strcmp("radius", option))
			sphere->radius = ft_atoi(option_arg);
		else if (!ft_strcmp("color", option))
			sphere->color = set_color(e, option_arg);
		else
			unknown_option(option, e->nbline, "sphere");
		free(option);
		set_sphere(e);
	}
	else
	{
		set_last_obj(e, sphere);
		sphere = NULL;
		dispatch(e, option);
	}
}

void		set_plane(t_env *e)
{
	ft_putstr("Cool plane");
}

void		set_cylinder(t_env *e)
{
	ft_putstr("Cool cylinder");
}

void		set_cone(t_env *e)
{
	ft_putstr("Cool cone");
}