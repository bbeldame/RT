/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:26:32 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/20 03:25:16 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

/*
 ** We test all the object to get the minimal z coordinate of point_of_impact
 ** We save the first hitten object in the closest variable
 */

static double		get_min_dist(t_env *e, t_ray ray, t_object **closest)
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
	if (obj && obj->type == SPHERE)
		color = compute_color_sphere(e, point_of_impact, *obj);
	if (obj && obj->type == PLANE)
		color = compute_color_sphere(e, point_of_impact, *obj);
	if (obj && obj->type == CYLINDER)
		color = compute_color_cylinder(e, point_of_impact, *obj);
	return (color);
}

int				raytrace(t_env *e)
{
	int			x;
	int			y;
	t_vector	dir;
	t_ray		ray;
	t_color		*color;
	unsigned int *img_temp;

	if (!(img_temp = (unsigned int *)malloc(sizeof(unsigned int) * (((W * H))))))
		return (-1);
	y = 0;
	y = 0;
	while (y < H )
	{
		x = 0;
		while (x < W )
		{
			dir = normalize(c_vector(x - (W / 2), y - (H / 2),
						(W / (2 * tan(FOV / 2))) * -1));
			dir = normalize(vec_ope_min(dir, e->camera));
			ray = c_ray(e->camera, dir);
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
	return (0);
}
