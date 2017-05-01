/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:04:18 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/30 21:29:21 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double		intensity_sphere(t_env *e, t_vector poi,
				t_object sphere, t_light light)
{
	double		dist_to_light;
	t_vector	vec_to_eyes;
	t_vector	vec_to_light;
	double		intensity;

	vec_to_eyes = normalize(vec_ope_min(poi, sphere.origin));
	vec_to_light = vec_ope_min(light.origin, poi);
	dist_to_light = get_length(vec_to_light);
	intensity = (dot(vec_to_eyes, normalize(vec_to_light)) *
		ft_map(dist_to_light, 2000 * light.intensity, 500, 200));
	return (intensity);
}

/*
** Implementation of :
** http://www.dreamincode.net/forums/topic/124203-ray-sphere-intersection/
*/

double		intersect_sphere(t_ray ray, t_object sphere)
{
	t_vector	dist;
	double		a;
	double		b;
	double		x;

	dist = vec_ope_min(sphere.origin, ray.origin);
	a = get_length(dist);
	b = dot(dist, ray.direction);
	x = (sphere.radius * sphere.radius) - (a * a - b * b);
	if (x < 0)
		return (DIST_MAX);
	return (b - sqrt(x));
}
