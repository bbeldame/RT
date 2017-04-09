/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 16:31:59 by bbeldame          #+#    #+#             */
/*   Updated: 2017/04/09 20:14:42 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*semalloc(size_t size)
{
	void *new;

	if (!(new = malloc(size)))
		err_found("malloc failed");
	return (new);
}
