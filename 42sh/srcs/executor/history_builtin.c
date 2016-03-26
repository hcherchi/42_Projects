/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:10:11 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/05 14:55:24 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>
#include <ftsh.h>

static int	print_his_usage(void)
{
	ft_putstr_fd("history: usage: history [-c] [-d offset] [n]\n"
			, STDERR_FILENO);
	ft_putstr_fd("            or: history -arw [filename]\n", STDERR_FILENO);
	ft_putstr_fd("            or: history -s [args..]\n", STDERR_FILENO);
	return (1);
}

int			histo_ctrl(t_node_cmd *node, int c, int *i)
{
	int j;

	if (node->cmd[c][0] == '-')
	{
		j = 0;
		while (node->cmd[c][++j])
		{
			if (node->cmd[c][j] == 'c' && del_his())
				return (1);
			else if (node->cmd[c][j] == 'd'
			&& history_d(node->cmd[*i + 1]) && (*i += 2))
				return (1);
			else if (node->cmd[c][j] == 'a' && history_a(node->cmd + *i, i))
				return (1);
			else if (node->cmd[c][j] == 'r' && history_r(node, i))
				return (1);
			else if (node->cmd[c][j] == 'w' && history_w(node->cmd + *i, i))
				return (1);
			else if (node->cmd[c][j] == 's')
				return (history_s(node));
			else if (!ft_strchr("cdarws", node->cmd[c][j]))
				return (1);
		}
	}
	return (0);
}

int			history_builtin(t_node_cmd *node)
{
	int i;

	i = 1;
	if (node->ac == 1)
		print_history();
	else if (node->cmd[1][0] == '-' && !ft_isnumber(node->cmd[1]))
	{
		while (node->cmd[i])
		{
			if (histo_ctrl(node, i, &i))
				return (print_his_usage());
			i++;
		}
	}
	else if (ft_isnumber(node->cmd[1]))
		return (recu_print_his(ft_atoi(node->cmd[1]), g_shell->history->tail));
	else
		return (print_his_usage());
	return (0);
}
