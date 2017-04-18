/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splited_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 13:44:18 by bbeldame          #+#    #+#             */
/*   Updated: 2017/04/17 13:44:34 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		free_splited_str(char **str)
{
	int i;

	i = 0;
	while (str[i])
		ft_memdel((void **)&str[i++]);
	ft_memdel((void **)&str);
}