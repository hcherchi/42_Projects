/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 17:32:45 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/07 18:39:53 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	select_command(char **av, char ***myenv)
{
	if (!ft_strcmp(av[0], "exit"))
		exit(0);
	else if (!ft_strcmp(av[0], "env"))
		ft_puttab(*myenv);
	else if (!ft_strcmp(av[0], "setenv"))
	{
		if (tablen(av) == 3)
			ft_setenv(myenv, av[1], av[2]);
		else
			ft_putendl("2 arguments needed for setenv");
	}
	else if (!ft_strcmp(av[0], "unsetenv"))
		ft_unsetenv(myenv, av);
	else if (!ft_strcmp(av[0], "cd"))
		ft_cd(myenv, av);
	else
	{
		ft_putstr(av[0]);
		ft_putendl(" : Command not found");
	}
	tabdel(&av);
}

void	execute(char **myenv, char **av, char *good_path)
{
	if (access(good_path, X_OK) == 0)
	{
		execve(good_path, av, myenv);
		ft_putendl("Not an executable");
		exit(0);
	}
	else
	{
		ft_putendl("Permission denied");
		free(good_path);
		exit(0);
	}
}

void	run_command(char *command, char ***myenv, char **av)
{
	pid_t	pid;
	char	*good_path;

	command = ft_strtrim(command);
	av = ft_strsplit(command, ' ');
	if (command[0] == '\0')
		return ;
	if (!access(av[0], F_OK))
		good_path = av[0];
	else
		select_path(get_elem(*myenv, "PATH="), av[0], &good_path);
	if (!(access(good_path, F_OK) == 0)
	|| !ft_strcmp(av[0], "env") || !ft_strcmp(av[0], "cd"))
		select_command(av, myenv);
	else
	{
		pid = fork();
		if (pid == 0)
			execute(*myenv, av, good_path);
		else
			wait(&pid);
	}
}

void	set_commands(char ***myenv, char **av)
{
	char	*input;
	int		i;
	char	**commands;
	char	*home;

	home = get_elem(*myenv, "PWD=");
	prompt(home);
	while (get_next_line(0, &input))
	{
		while (ft_strchr(input, '~') && get_elem(*myenv, "HOME=") != NULL)
			input = strchange(input, '~', get_elem(*myenv, "HOME="));
		commands = ft_strsplit(input, ';');
		free(input);
		i = 0;
		while (commands[i])
		{
			run_command(commands[i], myenv, av);
			i++;
		}
		tabdel(&commands);
		home = get_elem(*myenv, "PWD=");
		prompt(home);
	}
}
