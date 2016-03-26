/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 16:26:16 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/17 18:30:06 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

t_buffline	*new_buff(int const fd, t_buffline *next)
{
	t_buffline	*new;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->buff = NULL;
		if (next == NULL)
			new->next = new;
		else
			new->next = next;
		new->fd = fd;
	}
	return (new);
}

void		get_buffer(int const fd, t_buffline **first)
{
	t_buffline	*it;

	it = *first;
	if (*first == NULL)
	{
		*first = new_buff(fd, NULL);
		return ;
	}
	if (it->fd == fd)
		return ;
	while (it->next != *first && (it = it->next))
	{
		if (it->fd == fd)
		{
			*first = it;
			return ;
		}
	}
	if (it->fd != fd)
	{
		it->next = new_buff(fd, it->next);
		*first = it->next;
		return ;
	}
	*first = it;
}

int			handle_backslash(char **line, t_buffline *b,
		int backslash, char *buff)
{
	char	*tmp;

	b->buff = ft_strsub(buff, 0, backslash);
	tmp = ft_strjoin(*line ? *line : "", b->buff);
	ft_memdel((void *)&b->buff);
	ft_memdel((void *)line);
	*line = tmp;
	b->buff = ft_strdup(buff + backslash + 1);
	return (1);
}

int			read_next_line(int const fd, char **line, char sep)
{
	static t_buffline	*b = NULL;
	int					backslash;
	char				*tmp;

	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	get_buffer(fd, &b);
	if ((backslash = ft_get_index(b->buff, sep)) != -1)
	{
		*line = ft_strsub(b->buff, 0, backslash);
		tmp = ft_strdup(b->buff + backslash + 1);
		free(b->buff);
		b->buff = tmp;
		return (1);
	}
	if (b->buff && b->buff[0])
		*line = ft_strdup(b->buff);
	else
		*line = NULL;
	ft_memdel((void *)&b->buff);
	return (gnl(fd, line, b, sep));
}

int			gnl(int const fd, char **line, t_buffline *b, char sep)
{
	char	*tmp;
	char	buff[BUFF_SIZE + 1];
	int		backslash;
	int		rd;

	ft_bzero(buff, BUFF_SIZE + 1);
	while ((rd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if ((backslash = ft_get_index(buff, sep)) != -1)
			return (handle_backslash(line, b, backslash, buff));
		tmp = ft_strjoin(*line ? *line : "", buff);
		ft_memdel((void *)line);
		*line = tmp;
		ft_bzero(buff, BUFF_SIZE + 1);
	}
	if (rd < 0)
		return (-1);
	if (b->buff == NULL && *line == NULL)
		return (0);
	return (1);
}
