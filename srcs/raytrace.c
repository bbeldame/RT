/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:26:32 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/30 21:23:42 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

static t_color		*get_color(t_env *e, t_object *obj, t_vector poi)
{
	double		intensity;
	t_light		*tmp;
	t_color		*color;

	intensity = 0;
	tmp = e->light;
	while (tmp)
	{
		if (obj && obj->type == SPHERE)
			intensity += intensity_sphere(e, point_of_impact, *obj, *tmp);
		if (obj && obj->type == PLANE)
			intensity += intensity_plane(e, point_of_impact, *obj, *tmp);
		if (obj && obj->type == CYLINDER)
			intensity += intensity_cylinder(e, point_of_impact, *obj, *tmp);
		if (obj && obj->type == CONE)
			intensity += intensity_cone(e, point_of_impact, *obj, *tmp);
		tmp = tmp->next;
	}
	return (obj && intensity > 0) ? color_mult(obj->color, intensity) : NULL;
}

/*
 ** We test all the object to get the minimal z coordinate of point_of_impact
 ** We save the first hitten object in the closest variable
 */

double				get_min_dist(t_env *e, t_ray ray, t_object **closest)
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
			min_dist = dist;
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

static t_color		*get_pxl_color(t_env *e, t_ray ray)
{
	double		min_dist;
	t_object	*obj;
	t_vector	point_of_impact;
	t_color		*color;

	color = NULL;
	obj = NULL;
	if ((min_dist = get_min_dist(e, ray, &obj)) == -1)
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
			pov = c_vector((double)x / SS, (double)y / SS, 0);
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