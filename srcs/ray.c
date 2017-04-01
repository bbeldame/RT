/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:55:55 by tfaure            #+#    #+#             */
/*   Updated: 2017/03/28 16:52:13 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_ray	c_ray(t_vector i, t_vector j)
{
	t_ray ray;

	ray.o = c_vector(i.x, i.y, i.z);
	ray.d = c_vector(j.x, j.y, j.z);
	return (ray);
}
