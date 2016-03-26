/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:10:20 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/19 20:28:22 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <executor.h>

static char	*join_cmd(char **cmd)
{
	int		i;
	char	*new;
	char	*tmp;

	i = 1;
	new = NULL;
	while (cmd[++i])
	{
		if (i == 2)
			new = ft_strdup(cmd[i]);
		else
		{
			tmp = new;
			new = ft_strjoin(new, " ");
			ft_strdel(&tmp);
			tmp = new;
			new = ft_strjoin(new, cmd[i]);
			ft_strdel(&tmp);
		}
	}
	return (new);
}

int			history_s(t_node_cmd *node)
{
	char	*new_cmd;
	int		index;

	new_cmd = join_cmd(node->cmd);
	if (!new_cmd)
		return (1);
	pop_his_node(g_shell->history->tail);
	if (g_shell->history->tail && g_shell->history->tail->index != -1)
		index = g_shell->history->tail->index + 1;
	else if (g_shell->history->tail && g_shell->history->tail->prev)
		index = g_shell->history->tail->prev->index + 1;
	else
		index = 1;
	add_his(new_his_node(index, new_cmd));
	return (0);
}
