/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:28:58 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 19:29:41 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	set_commands(char *command_line, char *paths, char ***env)
{
	int			i;
	t_command	*list;
	char		**split;

	if (syntax_error(command_line) == 0)
		return ;
	while (ft_strchr(command_line, '~') && get_elem(*env, "HOME=") != NULL)
		command_line = strchange(command_line, '~', get_elem(*env, "HOME="));
	split = ft_strsplit(command_line, ';');
	i = 0;
	while (split[i])
	{
		list = init_list(paths, split[i]);
		run_commands(list, env);
		i++;
	}
}

void	run_commands(t_command *list, char ***env)
{
	int			s_stdin;
	t_command	*save;

	save = list;
	s_stdin = dup(STDIN_FILENO);
	while (list)
	{
		choose_command(list, env);
		list = list->next;
	}
	while (save)
	{
		wait(0);
		save = save->next;
	}
	dup2(s_stdin, 0);
}
