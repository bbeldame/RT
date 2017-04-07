/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 20:08:17 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/04/07 14:13:46 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/rtv1.h"

int		intersect_plane(t_ray ray, double *t)
{
	t_vector	normal;
	t_vector	origin;
	t_vector	direction;
	float	vo;
	float	vd;
	float 	d;

	origin = c_vector(1, 1, 0);
	direction = c_vector(1, 0, 0);
	d = -1;
	normal = normalize(vec_ope_min(origin, direction));
	vd = dot(normal, ray.d);
	if(vd <= 0)
		return 0;
	vo = -1 * (dot(normal, ray.o) + d);
	*t = vd /vo;
	if(*t > 0)
		return 1;
	else
		return 0;;
}
