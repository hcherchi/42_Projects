/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opening.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjean-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 22:54:26 by wjean-ma          #+#    #+#             */
/*   Updated: 2015/12/21 18:50:10 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

char		*read_file(ssize_t buf_size, char *av)
{
	char	*buf;
	int		fd;

	if ((fd = open(av, O_RDONLY)) == -1)
		return (NULL);
	buf = (char *)malloc(sizeof(*buf) * (buf_size + 1));
	if (!buf)
		return (NULL);
	if ((read(fd, buf, buf_size)) < 1)
	{
		return (NULL);
	}
	else
		buf[buf_size] = '\0';
	return (buf);
}

ssize_t		get_ssize_file(char *av)
{
	char	buf[1];
	int		fd;
	ssize_t	ret;
	ssize_t	buf_size;

	*buf = '\0';
	buf_size = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		return (-1);
	while ((ret = read(fd, buf, 1)) == 1)
		buf_size++;
	if (ret == -1 || close(fd) == -1)
		return (-1);
	return (buf_size);
}

char		*standard_input(void)
{
	char *buf;
	char *sbuf;

	if (!(buf = (char *)malloc(sizeof(*buf) * BUF_SIZE)))
		return (NULL);
	sbuf = buf;
	while (((read(0, buf, BUF_SIZE)) > 0))
	{
		if (buf[0] == '\n')
		{
			buf[0] = '\0';
			return (sbuf);
		}
		buf += ft_lenline(buf) + 1;
	}
	return (sbuf);
}
