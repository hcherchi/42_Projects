/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locals.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:28:44 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/19 20:28:46 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <executor.h>

int		set_local_var(char *var, char *val, int dup)
{
	t_env	**target;

	if (get_env(g_shell->env, var, 0))
		target = &g_shell->env;
	else
		target = &g_shell->l_env;
	if (dup && val)
		set_env(target, var, ft_strdup(val));
	else if (dup)
		set_env(target, var, ft_strdup(""));
	else
		set_env(target, var, val);
	return (SUCCESS);
}

int		unset_var(char *key)
{
	unset_env(&g_shell->l_env, key);
	unset_env(&g_shell->env, key);
	return (SUCCESS);
}

int		print_vars(t_node_cmd *node)
{
	print_env(node, g_shell->l_env);
	print_env(node, g_shell->env);
	return (SUCCESS);
}

int		localvar_builtin(t_parser *parser)
{
	int			i;
	t_node_cmd	*node;
	char		**split;

	i = 0;
	node = (t_node_cmd *)parser->data;
	while (node->cmd[i])
	{
		if (ft_strchr(node->cmd[i], '=') && node->cmd[i][0] != '=')
		{
			split = ft_strsplit(node->cmd[i], '=');
			set_local_var(split[0], split[1], 1);
			ft_tabdel((void***)&split);
		}
		else if (node->cmd[i][0] == '=')
			return (bad_delim(node, i));
		else
		{
			node->cmd = update_cmd(node->cmd, i);
			return (exec_fork(parser));
		}
		i++;
	}
	return (SUCCESS);
}

int		bad_delim(t_node_cmd *cmd, int i)
{
	int		err_fd;

	err_fd = get_stderr(cmd);
	ft_putstr_fd("42sh: bad delim: ", err_fd);
	ft_putendl_fd(cmd->cmd[i], err_fd);
	return (FAILURE);
}
