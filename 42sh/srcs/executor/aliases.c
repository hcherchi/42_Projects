/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aliases.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:25:02 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/21 02:37:08 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <executor.h>
#include <parser.h>
#include <libft.h>

int		set_alias(char *arg)
{
	char	**split;

	if (arg && arg[0] && arg[0] != '=')
	{
		split = ft_strsplit(arg, '=');
		update_alias(split[0], split[1]);
		ft_tabdel((void ***)&split);
		return (SUCCESS);
	}
	return (FAILURE);
}

int		update_alias(char *key, char *val)
{
	if (ft_strchr(key, ' '))
	{
		ft_putstr_fd("42sh: alias: invalid key: ", STDERR_FILENO);
		ft_putendl_fd(key, STDERR_FILENO);
		return (FAILURE);
	}
	if (val)
		set_env(&g_shell->aliases, key, ft_strdup(val));
	else
		set_env(&g_shell->aliases, key, val);
	return (SUCCESS);
}

int		print_aliases(void)
{
	t_env	*al;

	al = g_shell->aliases;
	while (al)
	{
		ft_printf("alias %s='%s'\n", al->key, al->val);
		al = al->next;
	}
	return (SUCCESS);
}

int		alias_builtin(t_node_cmd *node)
{
	int		i;

	i = 1;
	while (node->cmd[i])
	{
		if (ft_strchr(node->cmd[i], '='))
			set_alias(node->cmd[i]);
		else if (node->cmd[i][0])
			print_alias(node->cmd[i]);
		else
			ft_putendl_fd("42sh: alias: invalid argument: \"\"", STDERR_FILENO);
		++i;
	}
	if (i == 1)
		print_aliases();
	return (SUCCESS);
}
