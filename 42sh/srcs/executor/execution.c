/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:26:57 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/06 16:44:44 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int		exec_node(t_parser *parser)
{
	int		left_child_ret;

	left_child_ret = SUCCESS;
	if (parser->type == NODE_CMD || parser->type == NODE_SUBSHELL)
		return (exec_fork(parser));
	else if (parser->type == NODE_PIPE)
		return (exec_pipe(parser));
	else if (parser->type == NODE_SEP_THEN)
	{
		left_child_ret = exec_node(parser->left);
		if (parser->right)
			return (exec_node(parser->right));
	}
	else if (parser->type == NODE_SEP_AND)
	{
		if ((left_child_ret = exec_node(parser->left)) == EXIT_SUCCESS)
			return (exec_node(parser->right));
	}
	else if (parser->type == NODE_SEP_NOR)
		if ((left_child_ret = exec_node(parser->left)) != EXIT_SUCCESS)
			return (exec_node(parser->right));
	return (SUCCESS);
}

int		exec_fork(t_parser *parser)
{
	int			child_ret;
	t_node_cmd	*cmd_node;
	pid_t		child;

	if (parser->type == NODE_CMD)
	{
		cmd_node = (t_node_cmd *)parser->data;
		rebuild_arglist(cmd_node);
		(cmd_node)->ac = tabsize(cmd_node->cmd);
	}
	if (parser->type == NODE_CMD && is_builtin(((t_node_cmd *)parser->data)))
		return (exec_builtin(parser));
	else if ((child = fork()) > 0)
	{
		waitpid(child, &child_ret, 0);
		handle_child_ret(child_ret);
	}
	else
	{
		if (parser->type != NODE_SUBSHELL)
			del_env(&g_shell->l_env);
		child_ret = exec_child(parser);
	}
	return (child_ret);
}

void	handle_connect(t_connect *connect)
{
	if (connect->type == R_SIMPLE)
		handle_r_simple(connect);
	else if (connect->type == R_DOUBLE)
		handle_r_double(connect);
	else if (connect->type == L_SIMPLE)
		handle_l_simple(connect);
}

int		redirections(t_connect *connect, int dup)
{
	while (connect)
	{
		handle_connect(connect);
		if (connect->to == -1 && dup == 1)
			close(connect->from);
		else if (dup)
			if (dup2(connect->to, connect->from) == -1)
				return (-1);
		connect = connect->next;
	}
	return (0);
}

int		exec_child(t_parser *parser)
{
	int			ret;
	char		*cmd_path;
	char		**env;
	t_node_cmd	*cmd_node;

	if (parser->type == NODE_SUBSHELL)
		exit(exec_node(parser->data));
	cmd_node = (t_node_cmd *)parser->data;
	if (redirections(cmd_node->connect, 1) == -1)
		exit(1);
	if (cmd_node->cmd == NULL)
	{
		rebuild_arglist(cmd_node);
		cmd_node->ac = tabsize(cmd_node->cmd);
	}
	if (is_builtin(cmd_node))
		ret = exec_builtin(parser);
	else if (!(cmd_path = get_path(cmd_node)))
		ret = err_cmd_not_found(cmd_node);
	else
	{
		env = env_lst_to_tab(cmd_node->env);
		ret = execve(cmd_path, cmd_node->cmd, env);
	}
	exit(ret);
}
