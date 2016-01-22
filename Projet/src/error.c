/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:06:45 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 19:09:57 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		syntax_error(char *line)
{
	if (error1(line, ';') == 0)
	{
		ft_putendl("Syntax error near ';'");
		return (0);
	}
	else if (error3(line) == 0)
		return (0);
	else if (redir_error(line) == 0 || !error2(line))
	{
		ft_putendl("Syntax error near '>' or '<'");
		return (0);
	}
	return (1);
}

int		error1(char *line, char c)
{
	int i;

	i = 0;
	line = ft_strtrim(line);
	if (line[0] == c)
		return (0);
	while (line[i])
	{
		if (line[i] == c)
		{
			i++;
			while (line[i] == ' ' || line[i] == '\t')
				i++;
			if (line[i] == c)
				return (0);
		}
		else
			i++;
	}
	if (line[i - 1] == c)
		return (0);
	return (1);
}

int		error3(char *line)
{
	int		i;
	char	**split;

	i = 0;
	split = ft_strsplit(line, ';');
	while (split[i])
	{
		if (!error1(split[i], '|'))
		{
			ft_putendl("Syntax error near '|'");
			return (0);
		}
		i++;
	}
	return (1);
}

int		redir_error(char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i])
	{
		while (line[i + j] == '<')
		{
			if (line[i + j + 1] == '>')
				return (0);
			j++;
		}
		while (line[i + j] == '>')
		{
			if (line[i + j + 1] == '<')
				return (0);
			j++;
		}
		if (j > 2)
			return (0);
		i += j + 1;
		j = 0;
	}
	return (1);
}

int		error2(char *line)
{
	int		i;
	char	**split;
	char	**subsplit;
	int		j;

	i = 0;
	split = ft_supersplit(line, ';', '|');
	while (split[i])
	{
		j = 0;
		subsplit = ft_supersplit(split[i], '>', '<');
		if (subsplit[j] == NULL)
			return (0);
		while (subsplit[j])
		{
			if (!ft_strcmp(ft_strtrim(subsplit[j]), ""))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
