/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:01:14 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 21:01:53 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_env(char ***env, char **args)
{
	int		i;
	int		i_opt;

	i = 1;
	i_opt = 0;
	while (args[i] && args[i][0] == '-')
	{
		if (!opt_env(&i, env, args))
			return (-1);
		i++;
	}
	while (args[i] && ft_strchr(args[i], '='))
	{
		if (!opt_env2(&i, env, args))
			return (-1);
		i++;
	}
	if (!args[i])
		ft_puttab(*env);
	return (i);
}

int		opt_env(int *i, char ***env, char **args)
{
	if (!ft_strcmp(args[*i], "-i"))
		*env = newtab();
	else if (!ft_strcmp(args[*i], "-u"))
	{
		if (args[*i + 1] && args[*i + 1][0] != '-')
		{
			ft_unsetenv(env, args[*i + 1], NULL);
			(*i)++;
		}
	}
	else
	{
		ft_putendl("Illegal option. please use -i or -u");
		return (0);
	}
	return (1);
}

int		opt_env2(int *i, char ***env, char **args)
{
	char	**split;

	split = ft_strsplit(args[*i], '=');
	if (tablen(split) > 2)
	{
		ft_putendl("Syntax error : use key=value");
		return (0);
	}
	else
		ft_setenv(env, split[0], split[1], NULL);
	return (1);
}
