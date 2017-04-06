/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <tfaure@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 17:18:21 by bbeldame          #+#    #+#             */
/*   Updated: 2017/04/06 17:04:08 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

int		key_hook(int keycode, t_screen *e)
{
	if (keycode == KEY_ESC)
		exit(1);
	(void)e;
	return (1);
}