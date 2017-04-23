/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 20:08:17 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/04/24 01:00:09 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_color		*compute_color_plane(t_env *e, t_vector poi, t_object plane)
{
	t_vector	dist_to_light;
	double		intensity;
	t_color		*color;

	color = copy_color(plane.color);
	dist_to_light = vec_ope_min(e->light->origin, poi);
	//printf("Dist_to_light = %f\n", get_length(dist_to_light));
	intensity = 0.5 * ft_map(get_length(dist_to_light), 2000 * e->light->intensity, 500, 200);
	// printf("Intensity for plane = %f\n", intensity);
	color_mult(color, intensity);
	return (color);
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