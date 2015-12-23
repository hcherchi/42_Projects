/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_second.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 11:11:45 by bgantelm          #+#    #+#             */
/*   Updated: 2015/12/23 11:44:28 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	reverse(t_file **l_files)
{
	t_file	*inv;
	t_file	*cur;

	cur = *l_files;
	inv = NULL;
	if (!*l_files)
		return ;
	else
	{
		while ((*l_files)->next)
		{
			while (cur->next->next)
			{
				cur = cur->next;
			}
			add_file(&inv, cur->next);
			cur->next = NULL;
			cur = *l_files;
		}
		add_file(&inv, *l_files);
	}
	*l_files = inv;
}

void	choose_sort(t_file **l_files, t_option *opt)
{
	if (opt->f == 0)
	{
		sort_ascii(l_files);
		if (opt->t)
			sort_time(l_files);
		if (opt->r)
			reverse(l_files);
	}
}

void	putpath(t_file *l_files)
{
	t_file	*cur;

	cur = l_files;
	ft_putchar('\n');
	ft_putstr(cur->data->path);
	ft_putstr(":\n");
}

void	putlink(t_file *l_files)
{
	t_file	*cur;

	cur = l_files;
	ft_putstr(" -> ");
	ft_putstr(cur->data->namelk);
}
