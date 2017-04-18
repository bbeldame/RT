/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:04:03 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/18 18:56:58 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

void		set_win_img(t_env *e)
{
	e->mlx = mlx_init();
	e->img = mlx_new_image(e->mlx, W / SS, H / SS);
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sl, &e->endian);
}
