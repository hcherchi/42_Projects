/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unalias_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:30:28 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/19 20:30:30 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <executor.h>

int		unalias_builtin(t_node_cmd *node)
{
	int		i;

	i = 1;
	while (node->cmd[i])
	{
		unset_env(&g_shell->aliases, node->cmd[i]);
		i++;
	}
	return (SUCCESS);
}
