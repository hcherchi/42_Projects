/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:25:33 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/05 19:19:55 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "executor.h"
#include <stdio.h>

int			is_builtin(t_node_cmd *node)
{
	if (node->cmd == NULL || node->cmd[0] == NULL)
		return (1);
	if (ft_strequ(node->cmd[0], "cd") ||
			ft_strequ(node->cmd[0], "echo") ||
			ft_strequ(node->cmd[0], "exit") ||
			ft_strequ(node->cmd[0], "env") ||
			ft_strequ(node->cmd[0], "setenv") ||
			ft_strequ(node->cmd[0], "unsetenv") ||
			ft_strequ(node->cmd[0], "export") ||
			ft_strequ(node->cmd[0], "history") ||
			ft_strequ(node->cmd[0], "unset") ||
			ft_strequ(node->cmd[0], "alias") ||
			ft_strequ(node->cmd[0], "unalias") ||
			ft_strchr(node->cmd[0], '=') ||
			ft_strequ(node->cmd[0], "read"))
		return (1);
	return (0);
}

static int	exec_builtin3(t_parser *parser)
{
	if (ft_strequ(((t_node_cmd *)parser->data)->cmd[0], "history"))
		return (history_builtin(((t_node_cmd *)parser->data)));
	if (ft_strequ(((t_node_cmd *)parser->data)->cmd[0], "alias"))
		return (alias_builtin(((t_node_cmd *)parser->data)));
	if (ft_strequ(((t_node_cmd *)parser->data)->cmd[0], "unalias"))
		return (unalias_builtin(((t_node_cmd *)parser->data)));
	if (ft_strchr(((t_node_cmd *)parser->data)->cmd[0], '='))
		return (localvar_builtin(parser));
	if (ft_strequ(((t_node_cmd *)parser->data)->cmd[0], "read"))
		return (read_builtin((t_node_cmd *)parser->data));
	return (FAILURE);
}

static int	exec_builtin2(t_parser *parser)
{
	if (ft_strequ(((t_node_cmd *)parser->data)->cmd[0], "unsetenv"))
		return (unsetenv_builtin(((t_node_cmd *)parser->data)));
	if (ft_strequ(((t_node_cmd *)parser->data)->cmd[0], "unset"))
		return (unset_builtin(((t_node_cmd *)parser->data)));
	if (ft_strequ(((t_node_cmd *)parser->data)->cmd[0], "echo"))
		return (echo_builtin(((t_node_cmd *)parser->data)));
	if (ft_strequ(((t_node_cmd *)parser->data)->cmd[0], "exit"))
		return (exit_builtin(((t_node_cmd *)parser->data)));
	if (ft_strequ(((t_node_cmd *)parser->data)->cmd[0], "env"))
		return (env_builtin(parser));
	if (ft_strequ(((t_node_cmd *)parser->data)->cmd[0], "setenv"))
		return (setenv_builtin(((t_node_cmd *)parser->data)));
	return (exec_builtin3(parser));
}

int			exec_builtin(t_parser *parser)
{
	int		ret;

	redirections(((t_node_cmd *)parser->data)->connect, 0);
	if (((t_node_cmd *)parser->data)->cmd == NULL ||
			((t_node_cmd *)parser->data)->cmd[0] == NULL)
		ret = 0;
	else if (ft_strequ(((t_node_cmd *)parser->data)->cmd[0], "cd"))
		ret = cd_builtin(((t_node_cmd *)parser->data));
	else if (ft_strequ(((t_node_cmd *)parser->data)->cmd[0], "export"))
		ret = export_builtin((t_node_cmd *)parser->data);
	else
		ret = exec_builtin2(parser);
	handle_closes(((t_node_cmd *)parser->data)->connect);
	return (ret);
}
