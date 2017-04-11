/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 20:08:17 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/04/11 13:02:44 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
** NOT DONE
*/

t_color		*compute_color_plane(t_env *e, t_vector poi, t_object plane)
{
	t_color		*color;

	color = malloc(200);
	(void)poi;
	(void)plane;
	(void)e;
	color->r = 0;
	color->g = 250;
	color->b = 0;
	return (color);
}

double		intersect_plane(t_ray ray, t_object plane)
{
	t_vector	dist;
	t_vector	normal;
	double		vo;
	double		vd;
	double		distance;

	normal = normalize(vec_ope_min(plane.origin, plane.direction));
	dist = vec_ope_min(plane.origin, ray.origin);
	vd = dot(normal, dist);
	vo = dot(normal, ray.direction);
	if (vd <= 0)
		return (DIST_MAX);
	distance = vd / vo;
	if (distance > 0)
		return (distance);
	else
		return (DIST_MAX);
}
