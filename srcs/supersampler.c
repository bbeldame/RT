/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supersampler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 09:45:23 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/04/24 20:32:38 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void	anti_supersampler(t_env *e)
{
	int x;
	int x1;

	x = 0;
	x1 = W * H;
	while (x < x1)
	{
		((unsigned int *)e->data)[x] = e->img_temp[x];
		x++;
	}
}

void	super_sampler(t_env *e)
{
	int x;
	int y;
	int x1;
	int y1;

	y = 0;
	y1 = 0;
	while (y < H / 2)
	{
		x = 0;
		x1 = 0;
		while (x < W / 2)
		{
			((unsigned int *)e->data)[x + y * W / 2] = AVERAGE(
				AVERAGE(e->img_temp[x1 + y1 * W],
						e->img_temp[(x1 + 1) + (y1 * W)]),
				AVERAGE(e->img_temp[x1 + (y1 + 1) * W],
						e->img_temp[(x1 + 1) + (y1 + 1) * W]));
			x1 += 2;
			x++;
		}
		y++;
		y1 += 2;
	}
}
