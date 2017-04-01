/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myernaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:24:46 by myernaux          #+#    #+#             */
/*   Updated: 2017/01/17 18:09:47 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*check_fd(t_list **file, int fd)
{
	t_list		*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

static int		read_to_buff(t_list *current)
{
	char	*buff;
	int		ret;
	char	*new_string;

	buff = ft_strnew(BUFF_SIZE + 1);
	ret = read(current->content_size, buff, BUFF_SIZE);
	if (ret > 0)
	{
		buff[ret] = '\0';
		new_string = ft_strjoin(current->content, buff);
		if (!new_string)
			return (-1);
		free(current->content);
		current->content = new_string;
	}
	new_string = NULL;
	free(buff);
	return (ret);
}

static int		ft_endgnl(t_list *curr, char *index)
{
	index = ft_strdup(index + 1);
	free(curr->content);
	curr->content = index;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list		*all;
	int					ret;
	t_list				*curr;
	char				*index;

	if (fd < 0 || line == NULL)
		return (-1);
	curr = check_fd(&all, fd);
	index = ft_strchr(curr->content, '\n');
	while (index == NULL)
	{
		if ((ret = read_to_buff(curr)) == 0)
		{
			if ((index = ft_strchr(curr->content, '\0')) == curr->content)
				return (0);
		}
		else if (ret < 0)
			return (-1);
		else
			index = ft_strchr(curr->content, '\n');
	}
	if (!(*line = ft_strsub(curr->content, 0, index - (char *)curr->content)))
		return (-1);
	return (ft_endgnl(curr, index));
}
