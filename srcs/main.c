/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:37:09 by tfaure            #+#    #+#             */
/*   Updated: 2017/04/23 03:12:15 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"
#include <time.h>

int		main(int ac, char **av)
{
	t_env		*e;
	clock_t		tic;

	if (ac != 2 || ft_strncmp(ft_strrev(av[1]), "1vtr.", 5) != 0)
		err_found("usage: rtv1 input_map.rtv1");
	tic = clock();
	e = parse(ft_strrev(av[1]));
	printf("Parsing over in %f seconds \n", (double)(clock() - tic) / CLOCKS_PER_SEC);
	set_win_img(e);
	tic = clock();
	raytrace(e);
	printf("Rendering over in %f seconds \n", (double)(clock() - tic) / CLOCKS_PER_SEC);
	tic = clock();
	super_sampler(e);
	printf("Super Sampler over in %f seconds \n", (double)(clock() - tic) / CLOCKS_PER_SEC);
	e->win = mlx_new_window(e->mlx, W / SS, H / SS, "RTv1");
	mlx_key_hook(e->win, key_hook, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_loop(e->mlx);
	return (0);
}
