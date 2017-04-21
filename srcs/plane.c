/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 20:08:17 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/04/21 18:12:40 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
** NOT DONE
*/

t_vector set_normal(t_vector a, t_vector b)
{
	t_vector vp;
	vp = c_vector(a.y * b.z - a.z * b.y, 
				   a.z * b.x - a.x * b.z, 
				  a.x * b.y - a.y * b.x);
	return(normalize(vp));
}

void		set_plane_data(t_object *plane)
{
	plane->normal = set_normal(vec_ope_min(plane->direction, plane->origin), 
	vec_ope_min(plane->normal, plane->origin));
	plane->d = -(plane->normal.x * plane->extra.x + 
				plane->normal.y * plane->extra.y + 
				plane->normal.z * plane->extra.z);
}

t_color		*compute_color_plane(t_env *e, t_vector poi, t_object plane)
{
	t_color		*color;

	color = malloc(200);
	(void)poi;
	(void)plane;
	(void)e;
	color->r = 0;
	color->g = 250;
	color->b = 0;
	return (color);/*
	t_vector	dist_to_eyes;
	t_vector	dist_to_light;
	double		intensity;
	t_color		*color;

	color = copy_color(plane.color);
	dist_to_eyes = poi;
	dist_to_light = vec_ope_min(e->light, poi);
	intensity = 0.5 * dot(dist_to_eyes, dist_to_light);
	color_mult(color, intensity);
	return (color);*/
}

double		intersect_plane(t_ray ray, t_object plane)
{
	t_vector	normal;
	double		vo;
	double		vd;
	double 		t;

	vd = dot(plane.normal, ray.direction);
	if (vd == 0)
		return (DIST_MAX);
	if(vd < 0)
	{
		normal = c_vector(-plane.normal.x, 
		-plane.normal.y, -plane.normal.z);
		vo = -(dot(normal, ray.origin) - plane.d);
		t = vo/vd;
		if(t < 0)
		return (DIST_MAX);
		return t;
	}
	else 
	normal = plane.normal;
	vo = -(dot(normal, ray.origin) + plane.d);
	t = vo/vd;
	ft_putchar('\n');
	ft_putnbr((int)t);
	if(t < 0)
		return (DIST_MAX);
	return (t);
}
