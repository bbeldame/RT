/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:04:18 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/05 20:19:31 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_sphere	c_sphere(t_vector center, double radius)
{
	t_sphere sphere;

	sphere.c = center;
	sphere.r = radius;
	return (sphere);
}

int			intersect_sphere(t_ray ray, double *t, t_sphere sphere)
{
	t_vector	dist;
	double		b;
	double		c;
	double		t0;
	double		t1;

	dist = vec_ope_min(sphere.c, ray.o);
	b = dot(ray.d, dist);
	c = (b * b) - dot(dist, dist) + (sphere.r * sphere.r);
	if (c < 0)
		return (0);
	t0 = b - sqrt(c);
	t1 = b + sqrt(c);
	if (t0 > 0)
		*t = t0;
	if (t1 > 0)
		*t = t1;
	if (*t >= DIST_MAX)
		return (0);
	return (1);
}
