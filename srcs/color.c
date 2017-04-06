/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:10:16 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/06 17:02:24 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

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

t_color				color_mult(t_color color, double taux)
{
	t_color newcolor;

	newcolor.r = color.r * taux;
	newcolor.g = color.g * taux;
	newcolor.b = color.b * taux;
	newcolor.r = (newcolor.r > 255) ? 255 : newcolor.r;
	newcolor.g = (newcolor.g > 255) ? 255 : newcolor.g;
	newcolor.b = (newcolor.b > 255) ? 255 : newcolor.b;
	newcolor.r = (newcolor.r < 0) ? 0 : newcolor.r;
	newcolor.g = (newcolor.g < 0) ? 0 : newcolor.g;
	newcolor.b = (newcolor.b < 0) ? 0 : newcolor.b;
	return (newcolor);
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
