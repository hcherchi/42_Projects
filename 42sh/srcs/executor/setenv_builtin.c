/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:30:02 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/19 20:30:04 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include "parser.h"
#include "executor.h"

int		print_setenv_usage(t_node_cmd *node)
{
	ft_putendl_fd("usage: setenv KEY VALUE [KEY2 VALUE2 ...]",
			get_stderr(node));
	return (FAILURE);
}

int		setenv_builtin(t_node_cmd *node_cmd)
{
	int		i;

	i = 1;
	if (!(node_cmd->ac & 1))
		return (print_setenv_usage(node_cmd));
	while (node_cmd->cmd[i])
	{
		export_var(node_cmd->cmd[i], node_cmd->cmd[i + 1]);
		i += 2;
	}
	return (SUCCESS);
}
