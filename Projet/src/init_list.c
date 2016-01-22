/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:13:25 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 20:25:58 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_command	*init_list(char *paths, char *command)
{
	t_command	*list;
	char		**split;
	int			i;

	list = NULL;
	split = ft_strsplit(command, '|');
	i = 0;
	while (split[i])
	{
		add_command(&list, split[i], paths);
		i++;
	}
	endofpipe(list);
	return (list);
}

void		endofpipe(t_command *list)
{
	while (list->next)
	{
		list = list->next;
	}
	free(list->piperight);
	list->piperight = NULL;
}
