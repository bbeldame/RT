/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 19:43:49 by bbeldame          #+#    #+#             */
/*   Updated: 2017/04/22 23:07:23 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static double	zero_dot(int nbr)
{
	int		digits;
	int		diviser;
	int		tmpnbr;

	digits = 0;
	diviser = 10;
	tmpnbr = nbr;
    while (tmpnbr > 0)
    {
        tmpnbr /= 10;
        digits++;
    }
	while (digits-- > 1)
		diviser *= 10;
	return ((double)nbr / (double)diviser);
}

double			ft_atof(const char *str)
{
	double		res;
	int			after_comma;
	int			i;

	res = (double)ft_atoi(str);
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i++] == '.')
	{
		after_comma = ft_atoi(str + i);
		res += (res >= 0) ? zero_dot(after_comma) : -zero_dot(after_comma);
	}
	return (res);
}