/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:37:09 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/15 20:07:17 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		main(int ac, char **av)
{
	t_env *e;

	if (ac != 2 || ft_strncmp(ft_strrev(av[1]), "1vtr.", 5) != 0)
		err_found("usage: rtv1 input_map.rtv1");
	e = parse(ft_strrev(av[1]));
	set_win_img(e);
	raytrace(e);
	e->win = mlx_new_window(e->mlx, W, H, "RTv1");
	mlx_key_hook(e->win, key_hook, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_loop(e->mlx);
	return (0);
}
