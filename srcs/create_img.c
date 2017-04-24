/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:04:03 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/24 19:36:49 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		set_win_img(t_env *e)
{
	e->mlx = mlx_init();
	e->img = mlx_new_image(e->mlx, W / SS, H / SS);
	e->data = mlx_get_data_addr(
		e->img,
		&e->setup.bpp, 
		&e->setup.sl,
		&e->setup.endian
	);
}
