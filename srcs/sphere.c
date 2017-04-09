/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:04:18 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/09 21:00:57 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_color		*compute_color_sphere(t_env *e, t_vector poi, t_object sphere)
{
	t_vector	dist_to_eyes;
	t_vector	dist_to_light;
	double		intensity;
	t_color		*color;

	color = copy_color(sphere.color);
	dist_to_eyes = normalize(vec_ope_min(poi, sphere.origin));
	dist_to_light = vec_ope_min(e->light, poi);
	intensity = 0.5 * dot(dist_to_eyes, dist_to_light);
	color_mult(color, intensity);
	return (color);
}

/*
** Returns the z coordinate of the first collision with the sphere
** @todo : lose one variable, without taking away the lisibility
*/

double		intersect_sphere(t_ray ray, t_object sphere)
{
	t_vector	dist;
	double		b;
	double		c;
	double		t0;
	double		t1;
	double		distance;

	dist = vec_ope_min(sphere.origin, ray.origin);
	b = dot(ray.direction, dist);
	c = (b * b) - dot(dist, dist) + (sphere.radius * sphere.radius);
	if (c < 0)
		return (DIST_MAX);
	t0 = b - sqrt(c);
	t1 = b + sqrt(c);
	if (t0 > 0)
		distance = t0;
	if (t1 > 0)
		distance = t1;
	if (distance >= DIST_MAX)
		return (DIST_MAX);
	return (distance);
}
