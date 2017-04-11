/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:26:32 by myernaux          #+#    #+#             */
/*   Updated: 2017/04/11 09:21:08 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*t_color     *compute_color_cylinder(t_env *e, t_vector poi, t_object cylinder)
{
    t_color     *color;

    color = malloc(200);
    (void)poi;
	(void)cylinder;
	(void)e;
	color->r = 0;
	color->g = 0;
	color->b = 200;
	return (color);
}

double      intersect_cylinder(t_ray ray, t_object cylinder)
{
    t_vector        dist;
    double          a;
    double          b;
    double          c;
    double          d;
    double          t0;
    double          t1;
    double          distance;
    
    dist = vec_ope_min(cylinder.origin, ray.origin);
    a = dot(ray.direction, ray.direction) - ((dot(ray.direction, cylinder.direction)) * (dot(ray.direction, cylinder.direction)));
    b = (dot(ray.direction, dist) - dot(ray.direction, cylinder.direction) * dot(dist, cylinder.direction)) * 2;
    c = (dot(dist, dist) - (dot(dist, cylinder.direction) * dot(dist, cylinder.direction))) - (cylinder.radius * cylinder.radius); 
    d = b * b - 4 * a* c;
    if (d < 0)
        return (DIST_MAX);
    t0 = (-b - sqrt(d)) / (2 * a);
    t1 = (-b + sqrt(d)) / (2 * a);
    if (t0 > 0)
        distance = t0;
    if (t1 > 0)
        distance = t1;
    if (distance >= DIST_MAX)
        return (DIST_MAX);
    return (distance);
}*/