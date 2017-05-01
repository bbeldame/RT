/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:20:18 by tfaure            #+#    #+#             */
/*   Updated: 2017/05/01 21:01:28 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	vec_ope_min(t_vector v1, t_vector v2)
{
	return (c_vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_vector	vec_ope_add(t_vector v1, t_vector v2)
{
	return (c_vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

t_vector	vec_ope_mult(t_vector v1, double d)
{
	return (c_vector(v1.x * d, v1.y * d, v1.z * d));
}

t_vector	vec_ope_div(t_vector v1, double d)
{
	return (c_vector(v1.x / d, v1.y / d, v1.z / d));
}

double		get_res_of_quadratic(double a, double b, double c)
{
	double		determinant;
	double		t0;
	double		t1;

	determinant = b * b - 4 * a * c;
	if (determinant < 0)
		return (DIST_MAX);
	if (determinant == 0)
		return (-b / (2 * a));
	t0 = (-b + sqrt(determinant)) / (2 * a);
	t1 = (-b - sqrt(determinant)) / (2 * a);
	return (t0 > t1) ? t1 : t0;
}