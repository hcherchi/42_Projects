/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tolist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 18:54:59 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 18:58:46 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	add_line(t_line **historic, char *line)
{
	t_line	*new;

	new = malloc(sizeof(*new));
	new->line = ft_strdup(line);
	new->prev = *historic;
	new->next = (*historic)->next;
	if (new->next)
		new->next->prev = new;
	(*historic)->next = new;
}

void	add_endline(t_line **l_line, char *line)
{
	t_line	*cur;
	t_line	*new;

	new = malloc(sizeof(*new));
	new->line = ft_strdup(line);
	new->next = NULL;
	cur = *l_line;
	if (cur == NULL)
	{
		new->prev = cur;
		*l_line = new;
	}
	else
	{
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
		new->prev = cur;
	}
}

void	add_input(t_input **input, char *type, char *file)
{
	t_input	*cur;
	t_input	*new;

	new = malloc(sizeof(*new));
	new->type = type;
	new->file = file;
	new->next = NULL;
	cur = *input;
	if (cur == NULL)
		*input = new;
	else
	{
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
}

void	add_output(t_output **output, char *type, char *file, int fd)
{
	t_output	*cur;
	t_output	*new;

	new = malloc(sizeof(*new));
	new->type = type;
	new->file = file;
	new->fd = fd;
	new->next = NULL;
	cur = *output;
	if (cur == NULL)
		*output = new;
	else
	{
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
}

void	add_command(t_command **list, char *subcommand, char *paths)
{
	t_command	*new;
	t_command	*cur;

	cur = *list;
	new = malloc(sizeof(*new));
	new->next = NULL;
	fill_struct(new, subcommand, paths);
	if (cur == NULL)
		*list = new;
	else
	{
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
}
