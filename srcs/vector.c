/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:41:44 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/05 20:21:34 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	c_vector(double x, double y, double z)
{
	t_vector vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	return (vector);
}

/*
** Get the length of a vector
** A vector with length of 1 is called a unit vector,
** also known as a normalized vector
*/

double		get_length(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

/*
** If we want a vector to become a unit vector,
** we have to normalize it.
*/

t_vector	normalize(t_vector vector)
{
	double length;
	double inv;

	length = get_length(vector);
	if (length > 0)
	{
		inv = 1 / length;
		return (c_vector(vector.x * inv, vector.y * inv, vector.z * inv));
	}
	return (vector);
}

double		dot(t_vector v, t_vector b)
{
	return ((v.x * b.x) + (v.y * b.y) + (v.z * b.z));
}

t_vector	get_normal(t_sphere s, t_vector poi)
{
	return (vec_ope_div(vec_ope_min(s.c, poi), s.r));
}
