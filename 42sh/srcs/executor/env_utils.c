/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:26:36 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/19 20:26:38 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"
#include "ftsh.h"

void	print_env(t_node_cmd *node, t_env *env)
{
	int		out_fd;

	out_fd = get_stdout(node);
	while (env)
	{
		ft_putstr_fd(env->key, out_fd);
		ft_putchar_fd('=', out_fd);
		ft_putendl_fd(env->val, out_fd);
		env = env->next;
	}
}

void	print_env_usage(t_node_cmd *node)
{
	int		err_fd;

	err_fd = get_stderr(node);
	ft_putstr_fd("usage : env [--help] [-i] [-P path] [-u VAR]", err_fd);
	ft_putstr_fd(" [name=value ...] [command]\n", err_fd);
	ft_putendl_fd("--help: Print this message", err_fd);
	ft_putendl_fd("If no command is provided, the environnement is printed",
			err_fd);
	ft_putendl_fd("-i: Empty the environnement", err_fd);
	ft_putendl_fd("-P: Change the path for the command to launch",
			err_fd);
	ft_putendl_fd("-u: Unset the variable VAR", err_fd);
	ft_putendl_fd("name=value: Set the variable NAME to VALUE", err_fd);
}

t_env	*env_tab_to_lst(char **tabs)
{
	t_env	*env;
	char	*tmp_key;
	char	*tmp_val;

	env = NULL;
	if (tabs == NULL)
		return (NULL);
	while (*tabs)
	{
		tmp_key = ft_strsub(*tabs, 0, ft_get_index(*tabs, '='));
		tmp_val = ft_strdup(*tabs + ft_get_index(*tabs, '=') + 1);
		set_env(&env, tmp_key, tmp_val);
		free(tmp_key);
		tabs++;
	}
	return (env);
}

char	**env_lst_to_tab(t_env *env)
{
	char	**res;
	char	*tmp;
	t_env	*it;
	int		size;

	size = 0;
	it = env;
	if (!env)
		return (NULL);
	while (it && ++size)
		it = it->next;
	if (!(res = (char **)malloc(sizeof(*res) * (size + 1))))
		return (NULL);
	res[size] = NULL;
	size--;
	while (size >= 0)
	{
		tmp = ft_strjoin(env->key, "=");
		res[size] = ft_strjoin(tmp, env->val);
		free(tmp);
		size--;
		env = env->next;
	}
	return (res);
}

void	del_env(t_env **env)
{
	t_env	*tmp;
	t_env	*tmp2;

	tmp = *env;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->val);
		free(tmp->key);
		free(tmp);
		tmp = tmp2;
	}
	*env = NULL;
}
