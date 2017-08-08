/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 20:08:17 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/08/08 16:55:42 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double		intensity_plane(t_env *e, t_vector poi,
				t_object plane, t_light light)
{
	t_vector	dist_to_light;
	double		intensity;

	dist_to_light = vec_ope_min(light.origin, poi);
	intensity = 0.5 * ft_map(get_length(dist_to_light), 2000 * light.intensity, 500, 200);
	if (obj_in_shadow(e, poi, light))
		intensity -= AMBIENT_LIGHT;
	return (intensity > AMBIENT_LIGHT) ? intensity : AMBIENT_LIGHT;
}

/*
** Implementation of 
** http://stackoverflow.com/questions/23975555/how-to-do-ray-plane-intersection
*/

double		intersect_plane(t_ray ray, t_object plane)
{
	double		d;
	double		dist;
	t_vector	vector_distance;

	d = dot(plane.normal, ray.direction);
	if (fabs(d) > 0.0001)
	{
		vector_distance = vec_ope_min(plane.origin, ray.origin);
		dist = dot(vector_distance, plane.normal) / d;
		return (dist);
	}
	return (DIST_MAX);
}
