/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:29:38 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/06 16:18:10 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

static int	second_pipe(t_parser *parser, int pipefd[2], pid_t left)
{
	pid_t	right;
	int		right_ret;

	right = fork();
	if (right == 0)
	{
		connect(pipefd, 1);
		exit((exec_node(parser->right) == 0) ? 0 : 1);
	}
	else
	{
		waitpid(left, NULL, 0);
		close(pipefd[1]);
		waitpid(right, &right_ret, 0);
		close(pipefd[0]);
	}
	return (right_ret);
}

int			exec_pipe(t_parser *parser)
{
	int		pipefd[2];
	pid_t	left;

	pipe(pipefd);
	left = fork();
	if (left == 0)
	{
		connect(pipefd, 0);
		exit(exec_node(parser->left));
	}
	else
		return (second_pipe(parser, pipefd, left));
}

void		connect(int pipefd[2], int father)
{
	if (father)
	{
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[1]);
	}
	else
	{
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
	}
}

int			err_cmd_not_found(t_node_cmd *node)
{
	ft_putstr_fd("42sh: command not found: ", STDERR_FILENO);
	ft_putendl_fd(node->cmd[0], STDERR_FILENO);
	return (FAILURE);
}
