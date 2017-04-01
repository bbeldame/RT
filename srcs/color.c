/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:10:16 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/01 12:44:46 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_color		color(double i, double j, double k)
{
	t_color col;

	col.r = i;
	col.g = j;
	col.b = k;
	return (col);
}

unsigned int		ret_colors(t_color colo)
{
	unsigned int total;
	unsigned int temp;

	total = 0;
	if(colo.r > 0)
	{
	temp = (int)colo.r * 65536;
	total += temp;
	}
	if(colo.g > 0)
	{
	temp = (int)colo.g * 256;
	total += temp;
	}
	if(colo.b > 0)
	{
	temp = (int)colo.b;
	total += temp;
	}
	return (total);
}
