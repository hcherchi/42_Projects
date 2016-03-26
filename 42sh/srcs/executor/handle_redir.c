/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:27:34 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/14 11:42:40 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <errno.h>

int		is_aggr(char *word)
{
	int i;

	if (word[0] != '&')
		return (0);
	i = 1;
	while (ft_isdigit(word[i]))
		i++;
	if (word[i] == '\0')
		return (1);
	return (0);
}

void	handle_r_simple(t_connect *connect)
{
	int fd;

	if (!ft_strcmp(connect->label, "&-"))
		connect->to = -1;
	else if (is_aggr(connect->label))
		connect->to = ft_atoi(connect->label + 1);
	else
	{
		fd = open(connect->label, O_CREAT | O_WRONLY | O_TRUNC, 0666);
		if (fd == -1)
		{
			ft_putstr_fd("Error : cannot open : ", STDERR_FILENO);
			ft_putendl_fd(connect->label, STDERR_FILENO);
		}
		connect->to = fd;
	}
	connect->from = connect->fd;
}

void	handle_r_double(t_connect *connect)
{
	int fd;

	fd = open(connect->label, O_CREAT | O_WRONLY | O_APPEND, 0666);
	if (fd == -1)
	{
		ft_putstr_fd("Error : cannot open : ", STDERR_FILENO);
		ft_putendl_fd(connect->label, STDERR_FILENO);
	}
	connect->to = fd;
	connect->from = connect->fd;
}

void	handle_l_simple(t_connect *connect)
{
	int fd;

	fd = open(connect->label, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("42sh: ", STDERR_FILENO);
		ft_putstr_fd(connect->label, STDERR_FILENO);
		errno == ENOENT ? ft_putendl_fd(" No such file or directory", 2) : (0);
		errno == EACCES ? ft_putendl_fd(" Permission denied", 2) : (0);
		fd = -2;
	}
	connect->from = 0;
	connect->to = fd;
}

void	handle_closes(t_connect *connect)
{
	while (connect)
	{
		if (ft_strcmp(connect->label, "&-") && !is_aggr(connect->label))
			if (connect->to >= 3)
				close(connect->to);
		connect = connect->next;
	}
}
