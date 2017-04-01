/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 15:20:18 by tfaure            #+#    #+#             */
/*   Updated: 2017/03/29 19:28:40 by ocojeda-         ###   ########.fr       */
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
