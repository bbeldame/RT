/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:37:09 by tfaure            #+#    #+#             */
/*   Updated: 2017/03/26 21:38:32 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		main(int ac, char **av)
{
	t_screen *fst;

	if (ac == 2)
	{
		if (ft_strcmp(av[1], "sphere"))
			return (0);
		fst = set_win_img();
		raytrace(fst);
		fst->win = mlx_new_window(fst->mlx, W, H, "RTv1");
		mlx_put_image_to_window(fst->mlx, fst->win, fst->img, 0, 0);
		mlx_loop(fst->mlx);
	}
	return (0);
}
