/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:27:41 by tfaure            #+#    #+#             */
/*   Updated: 2017/03/28 18:16:06 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

double	dot(t_vector v, t_vector b)
{
	return ((v.x * b.x) + (v.y * b.y) + (v.z * b.z));
}
