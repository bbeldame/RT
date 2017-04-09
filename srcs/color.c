/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 20:14:59 by bbeldame          #+#    #+#             */
/*   Updated: 2017/04/09 20:15:00 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_color				*copy_color(t_color color)
{
	t_color		*newcolor;

	newcolor = (t_color *)semalloc(sizeof(t_color));
	newcolor->r = color.r;
	newcolor->g = color.g;
	newcolor->b = color.b;
	return (newcolor);
}

/*
** @param color rbg between 0 and 255
** We convert the number 0 - 255 to 0 - 0.5
** @todo : explain why
*/

t_color				c_color(double r, double g, double b)
{
	t_color color;

	color.r = ft_map(r, 255, 0, 0.5);
	color.g = ft_map(g, 255, 0, 0.5);
	color.b = ft_map(b, 255, 0, 0.5);
	return (color);
}

void				color_mult(t_color *color, double taux)
{
	color->r = color->r * taux;
	color->g = color->g * taux;
	color->b = color->b * taux;
	color->r = (color->r > 255) ? 255 : color->r;
	color->g = (color->g > 255) ? 255 : color->g;
	color->b = (color->b > 255) ? 255 : color->b;
	color->r = (color->r < 0) ? 0 : color->r;
	color->g = (color->g < 0) ? 0 : color->g;
	color->b = (color->b < 0) ? 0 : color->b;
}

unsigned int		ret_colors(t_color colo)
{
	unsigned int total;
	unsigned int temp;

	total = 0;
	if (colo.r > 0)
	{
		temp = (int)colo.r * 65536;
		total += temp;
	}
	if (colo.g > 0)
	{
		temp = (int)colo.g * 256;
		total += temp;
	}
	if (colo.b > 0)
	{
		temp = (int)colo.b;
		total += temp;
	}
	return (total);
}
