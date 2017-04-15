/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:37:09 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/09 21:01:36 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		main(int ac, char **av)
{
	t_env *e;

	if (ac == 2)
	{
		if (ft_strcmp(av[1], "sphere"))
			return (0);
		e = set_win_img();
		e = parse(e);
		raytrace(e);
		e->win = mlx_new_window(e->mlx, W, H, "RTv1");
		mlx_key_hook(e->win, key_hook, e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
		mlx_loop(e->mlx);
	}
	return (0);
}
