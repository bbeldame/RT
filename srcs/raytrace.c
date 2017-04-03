/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:26:32 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/03 18:15:22 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	raytrace(t_screen *fst)
{
	int			x;
	int			y;
	float		t;
	float		dt;
	double 		norme;
	t_vector 	distance;
	t_vector	origin;
	t_vector	dir;
	t_sphere	sphere;
	t_sphere	light;
	t_vector	poi;   //for point of impact//
	t_ray		ray;
	t_vector	n;
	t_vector	l;
	t_color		temp_color;

	sphere = c_sphere(c_vector(0, 0, 750), 100);
	sphere.p = color(ft_map(200, 255, 0, 0.5),
					ft_map(0, 255, 0, 0.5),
					ft_map(0, 255, 0, 0.5));
	light = c_sphere(c_vector(300, 200, 1500), 1);
	origin = c_vector(0, 0, -1);
	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
		{
			dir = normalize(c_vector(x - (W / 2), y - (H / 2), 
						(W / (2 * tan(FOV / 2))) * -1));
			dir = normalize(vec_ope_min(dir, origin));
			ray = c_ray(origin, dir);
			t = 20000;
			if(intersect_sphere(ray, &t, sphere))
			{
				poi = vec_ope_add(ray.o, vec_ope_mult(ray.d, t));
				distance = normalize(vec_ope_min(poi, sphere.c));
				norme = 1/dot(distance, distance);
				norme *= norme;
				if(norme > 0)
				{
					l = vec_ope_min(light.c, poi); //raylightdist
					n = vec_ope_div(l, norme);		//rayligthdir
					l = c_vector(distance.x * l.x, distance.y *l.y, 
						distance.z *l.z);//intensityligt
					dt = 0.5 * norme * (l.x + l.y + l.z);//intensite
					temp_color = sphere.p;
					temp_color = color_mult(temp_color, dt);
					((unsigned int *)fst->data)[x + y * W] =
						ret_colors(temp_color);
				}
			}
		}
	}
}
