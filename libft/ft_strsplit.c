/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfaure <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:45:11 by tfaure            #+#    #+#             */
/*   Updated: 2016/11/17 13:03:30 by tfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordsnbr(const char *s, char c)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (*s != '\0')
	{
		if (j == 1 && *s == c)
			j = 0;
		if (j == 0 && *s != c)
		{
			j = 1;
			i++;
		}
		s++;
	}
	return (i);
}

static int	wordslen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		words;
	int		i;

	if (!c || !s)
		return (NULL);
	i = 0;
	words = wordsnbr((const char*)s, c);
	str = (char **)malloc(sizeof(*str) * (wordsnbr((const char *)s, c) + 1));
	if (!str)
		return (NULL);
	while (words--)
	{
		while (*s == c && *s != '\0')
			s++;
		str[i] = ft_strsub((const char*)s, 0, wordslen((const char *)s, c));
		if (str[i] == NULL)
			return (NULL);
		s = s + wordslen((const char *)s, c);
		i++;
	}
	str[i] = NULL;
	return (str);
}
