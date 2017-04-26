/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:26:32 by myernaux          #+#    #+#             */
/*   Updated: 2017/04/26 17:50:51 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_color     *compute_color_cylinder(t_env *e, t_vector poi, t_object cylinder)
{
    t_vector	dist_to_light;
	double		intensity;
	t_color		*color;

	color = copy_color(cylinder.color);
	dist_to_light = vec_ope_min(e->light->origin, poi);
	intensity = 0.5 * ft_map(get_length(dist_to_light), 2000 * e->light->intensity, 500, 200);
	color_mult(color, intensity);
	return (color);
}

double      intersect_cylinder(t_ray ray, t_object cylinder)
{
    double          a;
    double          b;
    double          c;
    float		    det;
    float           t0;
    float           t1;
    a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
    b = 2 * (cylinder.origin.x * ray.direction.x) + 2 * (cylinder.origin.z * ray.direction.z);
   c = ray.origin.x * ray.origin.x + ray.origin.y * ray.origin.y + 
        cylinder.origin.x * cylinder.origin.x +
        cylinder.origin.y * cylinder.origin.y - 
        cylinder.radius * cylinder.radius - 
        2 * (ray.origin.x * cylinder.origin.x
			+ ray.origin.y * cylinder.origin.y);
    det = b * b - 4 * a * c;
    t0 = 0;t1 = 0;
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