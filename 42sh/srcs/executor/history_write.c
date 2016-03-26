/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:10:28 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/05 13:55:56 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <executor.h>

static int	write_his(int fd, t_his *ptr)
{
	while ((ptr = ptr->next) && ptr->next)
	{
		if (ptr->index != -1)
			ft_putendl_fd(ptr->cmd, fd);
	}
	return (1);
}

int			history_a(char **cmd, int *i)
{
	int		fd;
	t_his	*ptr;
	char	*history_filename;

	history_filename = cmd[1];
	if (!cmd[1] && !(history_filename = get_env(g_shell->env, "HISTFILE", 0)))
		return (ft_putstr_fd("history: can't open the file\n", STDERR_FILENO));
	fd = open(history_filename, O_CREAT | O_APPEND | O_WRONLY, 0644);
	if (fd == -1)
		return (ft_putstr_fd("history: can't open the file\n", STDERR_FILENO));
	if (!(ptr = g_shell->history->head))
		return (close(fd));
	while (ptr && ptr->index != -1)
		ptr = ptr->next;
	if (!ptr)
		return (close(fd));
	write_his(fd, ptr);
	close(fd);
	*i += (cmd[1]) ? 1 : 0;
	return (0);
}

int			history_w(char **cmd, int *i)
{
	int		fd;
	t_his	*ptr;
	char	*history_filename;

	history_filename = cmd[1];
	if (!cmd[1] && !(history_filename = get_env(g_shell->env, "HISTFILE", 0)))
		return (ft_putstr_fd("history: can't open the file\n", STDERR_FILENO));
	fd = open(history_filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
		return (ft_putstr_fd("history: can't open the file\n", STDERR_FILENO));
	if (!(ptr = g_shell->history->head))
		return (close(fd));
	while (ptr->prev)
		ptr = ptr->prev;
	write_his(fd, ptr);
	close(fd);
	*i += (cmd[1]) ? 1 : 0;
	return (0);
}
