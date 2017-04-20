/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 20:08:17 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/04/20 03:30:51 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
** NOT DONE
*/
t_vector	set_plane_nw_point(t_object plane)
{
	int x;
	int y;
	int z;
	if(plane.origin.x == plane.direction.x)
		x = plane.direction.x;
	else
		x = plane.origin.x + 1;
	if(plane.origin.y == plane.direction.y)
		y = plane.direction.y;
	else
		y = plane.origin.y + 1;
	if(plane.origin.z == plane.direction.z)
		z = plane.direction.z;
	else
		z = plane.origin.z + 1;
	return (c_vector(x, y , z));	
}

t_vector set_normal(t_vector a, t_vector b)
{
	t_vector vp;
	double mag;

	vp = c_vector(a.y * b.z - a.z * b.y, 
				  a.x * b.z - a.z * b.x, 
				  a.x * b.y - a.y * b.z);
	mag = sqrt(vp.x * vp.x + vp.y * vp.y + vp.z * vp.z);
	return(normalize(vec_ope_div(vp, mag)));
}

void		set_plane_data(t_object *plane)
{
	plane->normal = set_normal(vec_ope_min(plane->direction, 
	plane->origin), set_plane_nw_point(*plane));
	plane->d = -(plane->normal.x * plane->origin.x + 
				plane->normal.y * plane->origin.y + 
				plane->normal.z * plane->origin.z);
}

t_color		*compute_color_plane(t_env *e, t_vector poi, t_object plane)
{
/*	t_color		*color;

	color = malloc(200);
	(void)poi;
	(void)plane;
	(void)e;
	color->r = 0;
	color->g = 250;
	color->b = 0;
	return (color);*/

	t_vector	dist_to_eyes;
	t_vector	dist_to_light;
	double		intensity;
	t_color		*color;

	color = copy_color(plane.color);
	dist_to_eyes = poi;
	dist_to_light = vec_ope_min(e->light, poi);
	intensity = 0.5 * dot(dist_to_eyes, dist_to_light);
	color_mult(color, intensity);
	return (color);
}

double		intersect_plane(t_ray ray, t_object plane)
{
	t_vector	normal;
	double		vo;
	double		vd;

	vd = dot(plane.normal, ray.direction);
	if (vd >= 0)
		return (DIST_MAX);
	if(vd > 0)
		normal = c_vector(-plane.normal.x, 
		-plane.normal.y, -plane.normal.z);
	else 
		normal = plane.normal;
	vo = -(dot(normal, ray.origin) + plane.d);
	return (vo/vd);
}
