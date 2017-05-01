/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 09:33:24 by bbeldame          #+#    #+#             */
/*   Updated: 2017/04/30 20:55:36 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

/*
** set first light to the lights struct
*/

void			set_first_light(t_env *e, t_light *light)
{
	t_light		*tmp;

	tmp = light;
	tmp->next = e->light;
	e->light = tmp;
}

/*
** set first obj to the objects struct
*/

void			set_first_obj(t_env *e, t_object *obj)
{
	t_object	*tmp;

	tmp = obj;
	tmp->next = e->obj;
	e->obj = tmp;
}

/*
** this function is only here to test that
** the color are between 0 and 255
*/

double			get_color_from_str(t_env *e, char *str)
{
	double		color;

	color = ft_atoi(str);
	if (color < 0 || color > 255)
		syntax_error(str, "RGB are from 0 and 255", e->nbline);
	return (color); 
}

/*
** create a vector from "30 0 120"
*/

t_vector		set_vector(t_env *e, char *arg)
{
    char		**coor;
    t_vector	vector;

    coor = ft_strsplit(arg, ' ');
    if (len_of_tab(coor) != 3)
        syntax_error(arg, "Vector must have 3 points", e->nbline);
	vector = c_vector(
		ft_atof(coor[0]),
		ft_atof(coor[1]),
		ft_atof(coor[2])
	);
	free_splited_str(coor);
	return (vector);
}

/*
** create a color from string
*/

t_color			set_color(t_env *e, char *arg)
{
	char		**rgb;
	t_color		color;

    rgb = ft_strsplit(arg, ' ');
	if (len_of_tab(rgb) != 3)
		syntax_error(arg, "Color must have R G and B", e->nbline);
	color = c_color(
		get_color_from_str(e, rgb[0]),
		get_color_from_str(e, rgb[1]),
		get_color_from_str(e, rgb[2])
	);
	free_splited_str(rgb);
	return (color);
}