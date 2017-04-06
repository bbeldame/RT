/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:04:03 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/06 16:59:32 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_screen		*set_win_img(void)
{
	t_screen	*fst;

	if (!(fst = (t_screen *)malloc(sizeof(t_screen))))
		return (NULL);
	fst->mlx = mlx_init();
	fst->img = mlx_new_image(fst->mlx, W, H);
	fst->data = mlx_get_data_addr(
	fst->img,
	&fst->bpp,
	&fst->sizeline,
	&fst->endian);
	return (fst);
}
