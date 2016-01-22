/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:30:13 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 19:33:17 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	choose_command(t_command *list, char ***env)
{
	char	**tempenv;

	tempenv = tab_dup(*env);
	if (!ft_strcmp(list->args[0], "cd"))
		ft_cd(env, list->args);
	else if (!ft_strcmp(list->args[0], "setenv"))
		ft_setenv(env, list->args[1], list->args[2], list->args);
	else if (!ft_strcmp(list->args[0], "unsetenv"))
		ft_unsetenv(env, list->args[1], list->args);
	else if (!ft_strcmp(list->args[0], "exit"))
		exit(0);
	else if (!ft_strcmp(list->args[0], "quit"))
		kill(0, SIGTERM);
	else
		real_command(list, env, &tempenv);
}

void	real_command(t_command *list, char ***env, char ***tempenv)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (!ft_strcmp(list->args[0], "env"))
		i = ft_env(tempenv, list->args);
	if (i == -1)
		return ;
	if (list->args[i])
	{
		pid = fork();
		if (pid == 0)
		{
			if (!ft_strcmp(list->args[0], "env"))
			{
				run_env(list, i, *tempenv);
				return ;
			}
			else
				son_part(list, *env);
		}
		else
			father_part(list);
	}
}

void	run_env(t_command *list, int i, char **tempenv)
{
	char	*path;

	list->args = cuttab(list->args, i);
	select_path(get_elem(tempenv, "PATH="), list->args[0], &path);
	if (path)
		list->path = path;
	else
		list->path = list->args[0];
	son_part(list, tempenv);
}

void	father_part(t_command *list)
{
	if (list->piperight)
	{
		close(list->piperight[1]);
		dup2(list->piperight[0], 0);
	}
}
