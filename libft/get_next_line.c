/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:10:54 by bbeldame          #+#    #+#             */
/*   Updated: 2017/05/01 21:16:27 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		cs(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' || !str[i])
			return (i);
		i++;
	}
	return (-1);
}

char	*dumpstr(char *str)
{
	char *new;

	new = (char *)malloc(sizeof(char) * (ft_strlen(str) - cs(str)));
	if (!new)
		return (0);
	new = ft_strncpy(new, str + cs(str) + 1, ft_strlen(str) - cs(str));
	ft_bzero(str, ft_strlen(str));
	free(str);
	str = NULL;
	return (new);
}

int		fullfillline(char ****line, char **newline)
{
	if (!(***line = (char *)malloc(sizeof(char) * (ft_strlen(*newline) + 1))))
		return (0);
	ft_strcpy(***line, *newline);
	free(*newline);
	return (1);
}

int		processline(int ret, char **str, char ***line)
{
	char *newline;

	if (!ret && cs(*str) == -1)
	{
		if (!ft_strlen(*str))
			return (0);
		if (!(newline = (char *)malloc(sizeof(char) * ft_strlen(*str) + 1)))
			return (-1);
		ft_strcpy(newline, *str);
		free(*str);
		*str = ft_strdup(*str + ft_strlen(*str));
		if (!fullfillline(&line, &newline))
			return (-1);
	}
	else
	{
		if (!(newline = (char *)malloc(sizeof(char) * cs(*str) + 1)))
			return (-1);
		ft_strncpy(newline, *str, cs(*str) + 1);
		newline[cs(*str)] = '\0';
		*str = dumpstr(*str);
		if (!fullfillline(&line, &newline))
			return (-1);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	int				ret;
	static char		*str[NBMAXFD];
	char			*swap;

	ret = 1;
	if (!line || fd > NBMAXFD || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	if (!str[fd])
	{
		if (!(str[fd] = (char *)malloc(sizeof(char) * BUFF_SIZE)))
			return (-1);
		ft_bzero(str[fd], BUFF_SIZE);
	}
	while (cs(str[fd]) == -1 && ret)
	{
		if ((ret = read(fd, buffer, BUFF_SIZE)) == -1)
			return (-1);
		buffer[ret] = '\0';
		swap = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
		str[fd] = ft_strjoin(swap, buffer);
		ft_strdel(&swap);
	}
	return (processline(ret, &str[fd], &line));
}
