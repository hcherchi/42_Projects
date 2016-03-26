/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv_builtin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:30:38 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/21 02:49:04 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include "executor.h"
#include "parser.h"

int		unsetenv_builtin(t_node_cmd *node_cmd)
{
	int		i;

	i = 1;
	while (node_cmd->cmd[i])
	{
		unset_env(&g_shell->env, node_cmd->cmd[i]);
		++i;
	}
	return (SUCCESS);
}

int		unset_builtin(t_node_cmd *node)
{
	int		i;

	i = 1;
	while (node->cmd[i])
	{
		unset_env(&g_shell->env, node->cmd[i]);
		unset_env(&g_shell->l_env, node->cmd[i]);
		i++;
	}
	return (1);
}

int		is_special(char c)
{
	return (c == '\\' ||
			c == '|' ||
			c == '&' ||
			c == '(' ||
			c == ')' ||
			c == '$' ||
			c == '"' ||
			c == '\'' ||
			c == '{' ||
			c == ';' ||
			c == '`' ||
			c == '}');
}

int		export_var(char *var, char *val)
{
	char	*env_val;

	env_val = NULL;
	if (!val)
	{
		env_val = get_env(g_shell->l_env, var, 1);
		if (!env_val)
			env_val = ft_strdup("");
		set_env(&g_shell->env, var, env_val);
		unset_env(&g_shell->l_env, var);
	}
	else
	{
		set_env(&g_shell->env, var, ft_strdup(val));
		unset_env(&g_shell->l_env, var);
	}
	return (SUCCESS);
}
