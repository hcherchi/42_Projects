/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:15:53 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 19:20:02 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*find_type(char *subcmdr, int i)
{
	int j;

	j = 0;
	while (subcmdr[i] == '>' || subcmdr[i] == '<')
	{
		i++;
		j++;
	}
	if (j == 1)
		return (ft_strsub(subcmdr, i - j, 1));
	return (ft_strsub(subcmdr, i - j, 2));
}

int		find_fd(char *subcmdr, int i)
{
	if (i > 2 && (subcmdr[i - 1] == '1' || subcmdr[i - 1] == '2')
	&& (subcmdr[i - 2] == ' ' || subcmdr[i - 2] == '\t'))
		return (subcmdr[i - 1] - 48);
	else if (subcmdr[i - 1] == '1' || subcmdr[i - 1] == '2')
		return (subcmdr[i - 1] - 48);
	return (1);
}

char	*find_name(char *subcmdr, int i)
{
	int j;

	j = 0;
	while (subcmdr[i] == '>' || subcmdr[i] == '<' || subcmdr[i] == ' '
	|| subcmdr[i] == '\t')
		i++;
	while (subcmdr[i] != '>' && subcmdr[i] != '<'
	&& subcmdr[i] != ' ' && subcmdr[i] != '\t')
	{
		j++;
		i++;
	}
	return (ft_strsub(subcmdr, i - j, j));
}

void	fill_input(t_command *new, char *subcmdr)
{
	t_input		*input;
	char		*type;
	char		*name;
	int			i;

	i = 0;
	input = NULL;
	while (subcmdr[i])
	{
		if (subcmdr[i] == '<')
		{
			type = find_type(subcmdr, i);
			name = find_name(subcmdr, i);
			if (!(name[0] == '&' && name[1] == '-'))
				add_input(&input, type, name);
			i += ft_strlen(type);
		}
		else
			i++;
	}
	new->input = input;
}

void	fill_output(t_command *new, char *subcmdr)
{
	t_output	*output;
	int			fd;
	char		*type;
	char		*name;
	int			i;

	i = 0;
	output = NULL;
	while (subcmdr[i])
	{
		if (subcmdr[i] == '>')
		{
			fd = find_fd(subcmdr, i);
			type = find_type(subcmdr, i);
			name = find_name(subcmdr, i);
			if (!(name[0] == '&' && name[1] == '-')
				&& !(name[0] == '&' && (name[1] == '1' || name[1] == '2')))
				add_output(&output, type, name, fd);
			i += ft_strlen(type);
		}
		else
			i++;
	}
	new->output = output;
}
