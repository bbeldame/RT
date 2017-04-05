/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 16:04:03 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/05 20:06:31 by bbeldame         ###   ########.fr       */
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
