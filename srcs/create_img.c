/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:04:03 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/14 14:55:43 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		super_sampler(t_env *e)
{
	long long temp;
	int x;
	int y;
	int x1;
	int y1;

	y = 0;
	y1 = 0;
	while(y < H / 2)
	{
		x = 0;
		x1 = 0;
		while(x < W / 2)
		{ 
			temp = e->img_temp[x1 + y1 * W] / 4;
			temp += e->img_temp[x1 + 1 + y1 * W] / 4;
			temp += e->img_temp[x1 + (y1 + 1) * W] / 4;
			temp += e->img_temp[x1 + 1  + (y1 + 1) * W] / 4; 
			((unsigned int *)e->data)[x + y * W / 2] = (unsigned int)temp;	
			x1 += 2;
			x++;
		}
		y++;
		y1 += 2;
	}
}
t_env		*set_win_img(void)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->mlx = mlx_init();
	e->img = mlx_new_image(e->mlx, W / SS, H / SS);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sl, &e->endian);
	return (e);
}
