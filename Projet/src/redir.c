/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:24:51 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 19:52:46 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	redir_left(t_command *list)
{
	int	fd;

	while (list->input)
	{
		if (!ft_strcmp(list->input->type, "<<"))
			dredir_left(list);
		else
		{
			fd = open(list->input->file, O_RDONLY);
			if (fd == -1)
			{
				ft_putendl("No such file or Directory.");
				exit(0);
			}
			dup2(fd, 0);
		}
		list->input = list->input->next;
	}
}

void	dredir_left(t_command *list)
{
	int		pipefd[2];
	int		s_stdout;
	char	*line;

	line = ft_strdup("");
	s_stdout = dup(1);
	pipe(pipefd);
	dup2(pipefd[1], 1);
	while (ft_strcmp(line, list->input->file))
	{
		ft_putstr_fd("~> ", s_stdout);
		get_next_line(0, &line);
		if (ft_strcmp(line, list->input->file))
			ft_putendl(line);
	}
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	dup2(s_stdout, 1);
}

void	redir_right(t_command *list)
{
	int		fd;
	char	*file;

	while (list->output)
	{
		if (!ft_strcmp(list->output->type, ">"))
		{
			file = ft_strdup(list->output->file);
			fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
		}
		else if (!ft_strcmp(list->output->type, ">>"))
		{
			file = ft_strdup(list->output->file);
			fd = open(file, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
		}
		dup2(fd, list->output->fd);
		list->output = list->output->next;
	}
	if (list->fdredir[0] == 2)
		dup2(1, 2);
	else if (list->fdredir[0] == 1)
		dup2(2, 1);
}

void	son_part(t_command *list, char **env)
{
	if (list->piperight)
	{
		close(list->piperight[0]);
		dup2(list->piperight[1], 1);
	}
	redir_left(list);
	redir_right(list);
	if (list->close[0])
		close(1);
	if (list->close[1])
		close(2);
	if (list->close_stand == 1)
	{
		close(0);
	}
	execute(env, list->args, list->path);
}

void	execute(char **env, char **av, char *path)
{
	if (access(path, F_OK) == 0)
	{
		if (access(path, X_OK) == 0)
		{
			execve(path, av, env);
			ft_putendl("Not an executable");
			exit(0);
		}
		else
		{
			ft_putendl("Permission denied");
			free(path);
			exit(0);
		}
	}
	else
	{
		ft_putendl("Command not found");
		exit(0);
	}
}
