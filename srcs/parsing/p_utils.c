/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 09:33:24 by bbeldame          #+#    #+#             */
/*   Updated: 2017/04/18 17:43:25 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rtv1.h"

/*
** set last obj to the objects struct
*/

void			set_last_obj(t_env *e, t_object *obj)
{
	t_object	*tmp;

	tmp = obj;
	tmp->next = e->obj;
	e->obj = tmp;
}

/*
** this function is only here to test that
** the color are between 0 and 255
** @todo : ft_atof
*/

double			get_color(t_env *e, char *str)
{
	double		color;

	color = ft_atoi(str);
	if (color < 0 || color > 255)
		syntax_error(str, "RGB are from 0 and 255", e->nbline);
	return (color); 
}

/*
** create a vector from "30 0 120"
** @todo : ft_atof
*/

t_vector		set_vector(t_env *e, char *arg)
{
    char		**coor;
    t_vector	vector;

    coor = ft_strsplit(arg, ' ');
    if (len_of_tab(coor) != 3)
        syntax_error(arg, "Vector must have 3 points", e->nbline);
	vector = c_vector(
		(double)ft_atoi(coor[0]),
		(double)ft_atoi(coor[1]),
		(double)ft_atoi(coor[2])
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
		get_color(e, rgb[0]),
		get_color(e, rgb[1]),
		get_color(e, rgb[2])
	);
	free_splited_str(rgb);
	return (color);
}