/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:26:18 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/19 20:26:20 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "ftsh.h"
#include "parser.h"
#include "libft.h"

int		handle_env_opt(t_node_cmd *node, int *it)
{
	if (ft_strequ("-i", node->cmd[*it]) && (*it)++)
		del_env(&node->env);
	else if (ft_strequ("-P", node->cmd[*it]) && node->cmd[*it + 1])
	{
		set_env(&node->env, "PATH", ft_strdup(node->cmd[*it + 1]));
		(*it) += 2;
	}
	else if (ft_strequ("-P", node->cmd[*it]))
		return (-1);
	else if (ft_strequ("-u", node->cmd[*it]) && node->cmd[*it + 1])
	{
		unset_env(&node->env, node->cmd[*it + 1]);
		(*it) += 2;
	}
	else if (ft_strequ("-u", node->cmd[*it]))
		return (-1);
	else if (ft_strchr(node->cmd[*it], '='))
	{
		set_env_keyval(&node->env, node->cmd[(*it)++]);
	}
	return (1);
}

int		env_builtin(t_parser *parser)
{
	int			i;
	t_node_cmd	*node;

	i = 1;
	node = (t_node_cmd *)parser->data;
	if (node->cmd[i] && ft_strcmp(node->cmd[i], "--help") == 0)
	{
		print_env_usage(node);
		return (SUCCESS);
	}
	while (node->cmd[i] && is_env_opt(node->cmd[i]))
		if (handle_env_opt(node, &i) < 0)
		{
			print_env_usage(node);
			return (FAILURE);
		}
	if (node->cmd[i] && ft_strequ(node->cmd[i], "--"))
		i++;
	if (node->cmd[i])
	{
		node->cmd = update_cmd(node->cmd, i);
		return (exec_fork(parser));
	}
	print_env(node, node->env);
	return (SUCCESS);
}

int		is_env_opt(char *arg)
{
	if (ft_strequ(arg, "-i") || ft_strequ(arg, "-P") ||
			ft_strequ(arg, "-u") || ft_strchr(arg, '='))
		return (1);
	return (0);
}

char	**update_cmd(char **old_cmd, int command_index)
{
	int		size;
	char	**res;
	int		it;

	size = 0;
	while (old_cmd[size + command_index])
		++size;
	if (!(res = (char **)malloc(sizeof(*res) * (size + 1))))
		return (NULL);
	it = 0;
	while (it < size)
	{
		res[it] = old_cmd[it + command_index];
		++it;
	}
	res[it] = NULL;
	free(old_cmd);
	return (res);
}

t_env	*dup_env(t_env *env)
{
	t_env	*beg;
	t_env	*tmp;

	beg = NULL;
	tmp = env;
	while (tmp)
	{
		set_env(&beg, tmp->key, ft_strdup(tmp->val));
		tmp = tmp->next;
	}
	return (beg);
}
