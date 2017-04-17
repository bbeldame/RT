/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:26:32 by myernaux          #+#    #+#             */
/*   Updated: 2017/04/17 16:24:18 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_color     *compute_color_cylinder(t_env *e, t_vector poi, t_object cylinder)
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
    double          a;
    double          b;
    double          c;
    double          d;
    double          t0;
    double          t1;
    double          distance;
    
    a = pow(ray.direction.y, 2) + pow(ray.direction.z, 2);
    b = 2 * (cylinder.origin.y * ray.direction.y) + 2 * (cylinder.origin.z * ray.direction.z);
    c = pow(cylinder.origin.y, 2) + pow(cylinder.origin.z, 2) - pow(cylinder.radius, 2);
    d = b * b - 4 * a * c;
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
}