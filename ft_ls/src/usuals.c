/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usuals.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 12:10:25 by bgantelm          #+#    #+#             */
/*   Updated: 2015/12/14 12:13:33 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putstrsp(char *str)
{
	ft_putstr(str);
	ft_putstr("  ");
}

void	delone(t_file **l_files)
{
	t_file	*todel;

	todel = *l_files;
	*l_files = (*l_files)->next;
	free(todel->data->name);
	free(todel->data->path);
	free(todel->data->mod);
	free(todel->data->nblink);
	free(todel->data->uid);
	free(todel->data->nboct);
	free(todel->data->gid);
	free(todel->data->time);
	if (todel->data->namelk)
		free(todel->data->namelk);
	free(todel);
}

void	l_filesdel(t_file *l_files)
{
	while (l_files)
	{
		delone(&l_files);
	}
}

int		instr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
