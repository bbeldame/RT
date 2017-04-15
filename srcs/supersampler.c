/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supersampler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 16:56:33 by bbeldame          #+#    #+#             */
/*   Updated: 2017/04/15 18:08:02 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

char			compute_r(t_env *e, int x, int y)
{
	int		red;
	int		pos;

	red = 0;
	pos = (x * SS * e->bpp_ss / 8) + (y * SS * e->sl_ss);
	red += e->data_ss[pos];
	pos = ((x * SS + 1) * e->bpp_ss / 8) + (y * SS * e->sl_ss);
	red += e->data_ss[pos];
	pos = (x * SS * e->bpp_ss / 8) + ((y * SS + 1) * e->sl_ss);
	red += e->data_ss[pos];
	pos = ((x * SS + 1) * e->bpp_ss / 8) + ((y * SS + 1) * e->sl_ss);
	red += e->data_ss[pos];
	red /= 4;
	return ((char)red);
}

char			compute_g(t_env *e, int x, int y)
{
	int		green;
	int		pos;

	green = 0;
	pos = (x * SS * e->bpp_ss / 8) + (y * SS * e->sl_ss);
	green += e->data_ss[pos + 1];
	pos = ((x * SS + 1) * e->bpp_ss / 8) + (y * SS * e->sl_ss);
	green += e->data_ss[pos + 1];
	pos = (x * SS * e->bpp_ss / 8) + ((y * SS + 1) * e->sl_ss);
	green += e->data_ss[pos + 1];
	pos = ((x * SS + 1) * e->bpp_ss / 8) + ((y * SS + 1) * e->sl_ss);
	green += e->data_ss[pos + 1];
	green /= 4;
	return ((char)green);
}

char			compute_b(t_env *e, int x, int y)
{
	int		blue;
	int		pos;

	blue = 0;
	pos = (x * SS * e->bpp_ss / 8) + (y * SS * e->sl_ss);
	blue += e->data_ss[pos + 2];
	pos = ((x * SS + 1) * e->bpp_ss / 8) + (y * SS * e->sl_ss);
	blue += e->data_ss[pos + 2];
	pos = (x * SS * e->bpp_ss / 8) + ((y * SS + 1) * e->sl_ss);
	blue += e->data_ss[pos + 2];
	pos = ((x * SS + 1) * e->bpp_ss / 8) + ((y * SS + 1) * e->sl_ss);
	blue += e->data_ss[pos + 2];
	blue /= 4;
	return ((char)blue);
}

void		super_sampler(t_env *e)
{
	int		x;
	int		y;
	int		pos;

	y = 0;
	while(y < H / SS)
	{
		x = 0;
		while(x < W / SS)
		{
			pos = (x * e->bpp / 8) + (y * e->sl);
			e->data[pos] = compute_r(e, x, y);
			e->data[pos + 1] = compute_g(e, x, y);
			e->data[pos + 2] = compute_b(e, x, y);
			x++;
		}
		y++;
	}
}