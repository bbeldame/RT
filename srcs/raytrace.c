/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:26:32 by tfaure            #+#    #+#             */
/*   Updated: 2017/08/08 16:52:46 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int				obj_in_shadow(t_env *e, t_vector poi, t_light light)
{
	t_ray		ray;
	t_object	*dummyobj;
	double		dist_to_light;
	double		dist;

	dist_to_light = get_length(vec_ope_min(light.origin, poi));
	ray = c_ray(vec_ope_add(poi, normalize(vec_ope_min(light.origin, poi))),
	normalize(vec_ope_min(light.origin, poi)));
	dist = get_min_dist(e, ray, &dummyobj, 1);
	if (dist > 0 && dist < dist_to_light)
	{
		return (1);
	}
	else
		return (0);
}

static t_color	*get_color(t_env *e, t_object *obj, t_vector poi)
{
	double		intensity;
	t_light		*tmp;

	intensity = 0;
	tmp = e->light;
	while (tmp)
	{
		if (obj && obj->type == SPHERE)
			intensity += intensity_sphere(e, poi, *obj, *tmp);
		if (obj && obj->type == PLANE)
			intensity += intensity_plane(e, poi, *obj, *tmp);
		if (obj && obj->type == CYLINDER)
			intensity += intensity_cylinder(e, poi, *obj, *tmp);
		if (obj && obj->type == CONE)
			intensity += intensity_cone(e, poi, *obj, *tmp);
		tmp = tmp->next;
	}
	return (obj && intensity >= 0) ? color_mult(obj->color, intensity) : NULL;
}

/*
 ** We test all the object to get the minimal z coordinate of point_of_impact
 ** We save the first hitten object in the closest variable
 ** cangoneg is here to know if we compute the object in the negative distance or not
 */

double			get_min_dist(t_env *e, t_ray ray,
					t_object **closest, int cangoneg)
{
	t_object	*tmp;
	double		min_dist;
	double		dist;

	tmp = e->obj;
	min_dist = DIST_MAX;
	dist = DIST_MAX;
	while (tmp)
	{
		dist = (tmp->type == SPHERE) ? intersect_sphere(ray, *tmp) : dist;
		dist = (tmp->type == PLANE) ? intersect_plane(ray, *tmp) : dist;
		dist = (tmp->type == CYLINDER) ? intersect_cylinder(ray, *tmp) : dist;
		dist = (tmp->type == CONE) ? intersect_cone(ray, *tmp) : dist;
		if (dist < min_dist)
		{
			min_dist = (cangoneg && dist < 0) ? min_dist : dist;
			*closest = tmp;
		}
		tmp = tmp->next;
	}
	return (min_dist < DIST_MAX) ? min_dist : -1;
}

/*
 ** From the minimal z, we calculate the point_of_impact
 ** and send it to the compute method to return a color
 */

static t_color	*get_pxl_color(t_env *e, t_ray ray)
{
	double		min_dist;
	t_object	*obj;
	t_vector	point_of_impact;
	t_color		*color;

	color = NULL;
	obj = NULL;
	if ((min_dist = get_min_dist(e, ray, &obj, 0)) == -1)
		return (NULL);
	point_of_impact = vec_ope_add(ray.origin,
			vec_ope_mult(ray.direction, min_dist));
	color = get_color(e, obj, point_of_impact);
	return (color);
}

/*
** The camera is always pointing towards z only
** The camera is set to x y 0 for simplicity
*/

int				raytrace(t_env *e)
{
	int			x;
	int			y;
	t_ray		ray;
	t_vector	pov;
	t_color		*color;
	unsigned int *img_temp;

	img_temp = (unsigned int *)semalloc(sizeof(unsigned int) * (W * H));
	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			pov = c_vector((double)(x + e->setup.camera.x) / SS, 
			(double)(y + e->setup.camera.y) / SS, 1);
			ray = c_ray(pov, c_vector(0, 0, 1));
			color = get_pxl_color(e, ray);
			if (color != NULL)
				img_temp[x + y * W] = ret_colors(*color);
			else 
				img_temp[x + y * W] = 0;
			x++;
		}
		y++;
	}
	e->img_temp = img_temp;
	return (1);
}