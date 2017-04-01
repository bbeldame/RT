/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:41:44 by tfaure            #+#    #+#             */
/*   Updated: 2017/03/29 14:23:40 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_vector	c_vector(double a, double b, double c)
{
	t_vector vector;

	vector.x = a;
	vector.y = b;
	vector.z = c;
	return (vector);
}

t_vector	normalize(t_vector vector)
{
	double	mg;
	
	mg = 1 / sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
	return (c_vector((vector.x * mg), (vector.y * mg), (vector.z * mg)));
}

t_vector	get_normal(t_sphere s, t_vector poi)
{
	return (vec_ope_div(vec_ope_min(s.c, poi),s.r));
}
