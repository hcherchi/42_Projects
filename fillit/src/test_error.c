/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:50:29 by bgantelm          #+#    #+#             */
/*   Updated: 2015/12/09 15:33:45 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		test_char(char *pieces)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (pieces[i])
	{
		if (pieces[i] != '.' && pieces[i] != '#' && pieces[i] != '\n')
			return (1);
		if (pieces[i] == '#')
			count++;
		if ((pieces[i] == '\n' && pieces[i + 1] == '\n') ||
			(pieces[i] == '\n' && pieces[i + 1] == '\0'))
		{
			if (count != 4)
				return (1);
			count = 0;
		}
		i++;
	}
	return (0);
}

int		countdieze(char *pieces, int i)
{
	int c;

	c = 0;
	if (pieces[i + 1] == '#')
		c++;
	if (pieces[i + 5] == '#')
		c++;
	if (pieces[i - 1] == '#')
		c++;
	if (pieces[i - 5] == '#')
		c++;
	return (c);
}

int		test_forme(char *pieces)
{
	int i;

	i = 0;
	while (pieces[i] != '\0')
	{
		if (pieces[i] == '#')
		{
			if (countdieze(pieces, i) == 0)
				return (1);
			if (countdieze(pieces, i) == 1)
			{
				if (pieces[i + 1] == '#' && countdieze(pieces, i + 1) <= 1)
					return (1);
				if (pieces[i + 5] == '#' && countdieze(pieces, i + 5) <= 1)
					return (1);
			}
		}
		i++;
	}
	return (0);
}

char	*test_file(char *str)
{
	int		fd;
	int		ret;
	char	*buf;

	buf = malloc(sizeof(char) * (BUF_SIZE + 1));
	ret = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (NULL);
	else
	{
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		close(fd);
	}
	return (buf);
}

int		test_general(char *pieces)
{
	if (test_struct(pieces) == 1
		|| test_char(pieces) == 1 || test_forme(pieces) == 1)
	{
		ft_putstr("error\n");
		return (1);
	}
	return (0);
}
