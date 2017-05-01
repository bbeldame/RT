/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:26:32 by myernaux          #+#    #+#             */
/*   Updated: 2017/05/01 21:18:24 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double		intensity_cylinder(t_env *e, t_vector poi,
				t_object cylinder, t_light light)
{
	t_vector	dist_to_light;
	double		intensity;

	dist_to_light = vec_ope_min(light.origin, poi);
	intensity = 0.5 * ft_map(get_length(dist_to_light), 2000 * light.intensity, 500, 200);
	return (intensity > 0) ? intensity : 0;
}

double		intersect_cylinder(t_ray ray, t_object cylinder)
{
	double          a;
	double          b;
	double          c;
	double  	    det;
	double          t0;
	double          t1;
	t_vector        x;

	x = vec_ope_min(cylinder.origin, ray.origin);
	a = dot(ray.direction, ray.direction) - 
		dot(ray.direction, cylinder.normal);
	c = dot(x, x) - pow(dot(x, cylinder.normal), 2) - 
		pow(cylinder.radius, 2);
	b = 2 * (dot(ray.direction, x) - 
	(dot(ray.direction, cylinder.normal) * dot(x, cylinder.normal)));
	det = b * b - 4 * a * c;
	if (det >= 0)
	{
		det = sqrt(det);
		t0 = (-b - det) / (2 * a);
		t1 = (-b + det) / (2 * a);
		if (t0 > t1)
		return (t1);
		else
			return (t0);
	}
	return DIST_MAX;
}