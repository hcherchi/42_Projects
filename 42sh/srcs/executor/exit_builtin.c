/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:27:06 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/19 20:27:07 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "executor.h"
#include "readline.h"

int		is_number(char *s)
{
	if (*s == '-' || *s == '+')
		s++;
	while (ft_isdigit(*s))
		s++;
	if (*s)
		return (0);
	return (1);
}

int		exit_builtin(t_node_cmd *node)
{
	if (node->ac > 2)
	{
		ft_putendl_fd("exit: too many arguments", get_stderr(node));
		return (FAILURE);
	}
	if (node->ac == 2)
	{
		if (is_number(node->cmd[1]))
		{
			g_shell->running = 0;
			g_shell->exit_value = ft_atoi(node->cmd[1]);
			return (SUCCESS);
		}
		ft_putendl_fd("exit: numeric argument required", get_stderr(node));
		return (FAILURE);
	}
	else
		g_shell->running = 0;
	return (SUCCESS);
}
