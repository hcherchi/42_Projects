/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 17:17:56 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/14 17:52:32 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_and_replace(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (0);
	if (line[i] == '\n')
	{
		line[i] = '\0';
		if (line[i + 1] == '\0')
			return (0);
	}
	return (1);
}

static void	*ft_realloc(void *buf, size_t count)
{
	void *newbuf;

	newbuf = ft_memalloc((count + 1) * BUF_SIZE + 1);
	if (buf)
	{
		if (newbuf)
			ft_memcpy(newbuf, buf, count * BUF_SIZE);
		ft_memdel(&buf);
	}
	return (newbuf);
}

static int	return_value(char ***line, char **buf, int *i)
{
	if (*i == 2)
	{
		ft_memdel((void **)buf);
		return (0);
	}
	if (*i == 0)
	{
		**line = ft_strdup(*buf);
		*i = 1;
	}
	else
		**line += ft_strlen(**line) + 1;
	if (find_and_replace(**line) == 0)
		*i = 2;
	ft_memdel((void **)buf);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	char		*buf;
	int			count;
	int			ret;
	static int	i = 0;

	count = 0;
	buf = (char *)malloc(sizeof(*buf) * BUF_SIZE + 1);
	if (buf == NULL)
		return (-1);
	while ((ret = read(fd, buf + BUF_SIZE * count, BUF_SIZE)) != 0)
	{
		if (ret == -1)
			return (-1);
		i = 0;
		if (ret == BUF_SIZE)
		{
			count++;
			buf = ft_realloc(buf, count);
		}
		buf[BUF_SIZE * count + ret] = '\0';
		if (fd == 0 && ret < BUF_SIZE)
			return (return_value(&line, &buf, &i));
	}
	return (return_value(&line, &buf, &i));
}
