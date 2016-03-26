/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:10:18 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/05 15:32:17 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <executor.h>

static int	load_his_file(int fd)
{
	char	*line;
	int		index;

	if (g_shell->history->tail)
	{
		if (g_shell->history->tail->index != -1)
			index = g_shell->history->tail->index + 1;
		else if (g_shell->history->tail->prev)
			index = g_shell->history->tail->prev->index + 1;
		else
			index = 1;
	}
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (line)
		{
			add_his(new_his_node(index, line));
			index++;
		}
	}
	return (1);
}

int			history_r(t_node_cmd *node, int *i)
{
	int		fd;
	char	*history_filename;

	history_filename = node->cmd[*i + 1];
	if (!node->cmd[*i + 1] &&
		!(history_filename = get_env(g_shell->env, "HISTFILE", 0)))
	{
		return (ft_putstr_fd("history: can't open the file\n", STDERR_FILENO));
	}
	if ((fd = open(history_filename, O_RDONLY)) == -1)
		return (ft_putstr_fd("history: can't open the file\n", STDERR_FILENO));
	load_his_file(fd);
	close(fd);
	if (node->cmd[*i + 1])
		*i += 1;
	return (0);
}
