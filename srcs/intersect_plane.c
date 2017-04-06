/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 20:08:17 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/04/06 23:04:49 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/rtv1.h"

int		intersec_plane(t_ray ray, float *t)
{
	t_vector	normal;
	float	vo;
	float	vd;
	float	a;
	float	b;
	float	c;
	float	d;

	a = W/2;
	b = H/2;
	c = 0;
	d = -H/2;
	normal = normalize(c_vector(a, b ,c));
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
