/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 01:31:30 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/05 13:20:00 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	launch_gnl(int fd, t_input *save, char *buffer, int index)
{
	if (fd != save[index].fd)
	{
		save[index].fd = fd;
		ft_memset(save[index].str, 0, BUFF_SIZE);
	}
	ft_memset(buffer, '\0', BUFF_SIZE + 1);
}

static int	get_saved_string(char **line, char *saved)
{
	int		i;
	char	*tmp;

	i = 0;
	while (saved[i] && saved[i] != '\n')
		i++;
	*line = ft_strnew(i + 1);
	if (*line)
	{
		i = -1;
		while (saved[++i] && saved[i] != '\n' && saved[i] != EOF)
			(*line)[i] = saved[i];
		if (saved[i] == '\n')
		{
			tmp = ft_strdup(saved + i + 1);
			ft_memset(saved, 0, BUFF_SIZE + 1);
			ft_strcpy(saved, tmp);
			ft_strdel(&tmp);
			return (1);
		}
		else if (saved[i] == EOF)
			return (0);
	}
	ft_strclr(saved);
	return (-1);
}

static int	get_more_size(char **line, int lu)
{
	char	*tmp;
	int		size;

	size = 0;
	tmp = *line;
	if (tmp)
		size += ft_strlen(tmp);
	size += lu;
	*line = ft_strnew(size + 1);
	if (tmp && *line)
		*line = ft_strcpy(*line, tmp);
	if (tmp)
		ft_strdel(&tmp);
	if (*line == NULL)
		return (-1);
	return (1);
}

static int	cpy_buffer(char *line, char *buffer, char *saved)
{
	int i;

	i = 0;
	while (*line)
		line++;
	while (buffer[i] && buffer[i] != '\n' && buffer[i] != EOF)
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		ft_strcpy(saved, buffer + i + 1);
		return (1);
	}
	else if (buffer[i] == EOF)
		return (-1);
	ft_memset(buffer, 0, BUFF_SIZE);
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	int				check;
	static t_input	save[MAX_FD];
	int				index;

	index = (fd < 0) ? -fd % MAX_FD : fd % MAX_FD;
	launch_gnl(fd, save, buffer, index);
	if (line == NULL)
		return (-1);
	if ((check = get_saved_string(line, save[index].str)) >= 0)
		return (check);
	while ((check = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (get_more_size(line, check) == -1)
			return (-1);
		check = cpy_buffer(*line, buffer, save[index].str);
		if (check == 1 || check == -1)
			break ;
	}
	if (!check && *line && ft_strlen(*line))
		return (1);
	if (!check && *line)
		ft_strdel(line);
	return (check);
}
