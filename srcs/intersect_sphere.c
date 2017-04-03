/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:14:06 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/03 17:56:55 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int			intersect_sphere(t_ray ray, float *t, t_sphere sphere)
{
	t_vector dist;
	double b;
	double c;
	float t0;
	float t1;

	dist =  vec_ope_min(sphere.c, ray.o);
	b = dot(ray.d, dist);
	c = (b * b) - dot(dist, dist) + (sphere.r * sphere.r);
	if (c < 0)
		return (0);
	t0 = b - sqrt(c);
	t1 = b + sqrt(c);
	if(t0 > 0)
		*t = t0;
	if(t1 > 0)
		*t = t1;
	if(*t >= 20000)
		return (0);
	return (1);
}
