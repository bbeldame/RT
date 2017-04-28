/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <myernaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:18:47 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/04/28 13:42:28 by myernaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/rtv1.h"

t_color     *compute_color_cone(t_env *e, t_vector poi, t_object cone)
{
    t_vector	dist_to_light;
	double		intensity;
	t_color		*color;

	color = copy_color(cone.color);
	dist_to_light = vec_ope_min(e->light->origin, poi);
	intensity = 0.5 * ft_map(get_length(dist_to_light), 2000 * e->light->intensity, 500, 200);
	color_mult(color, intensity);
	return (color);
}

double      intersect_cone(t_ray ray, t_object cone)
{
    double          a;
    double          b;
    double          c;
    double		    det;
    double          t0;
    double          t1;
    t_vector        x;

    x = vec_ope_min(cone.origin, ray.origin);
    a = dot(ray.direction, ray.direction) - 
        dot(ray.direction, cone.normal);
    c = dot(x, x) - pow(dot(x, cone.normal), 2) - 
        pow(cone.radius, 2);
    b = 2 * (dot(ray.direction, x) - 
    (dot(ray.direction, cone.normal) * dot(x, cone.normal)));
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