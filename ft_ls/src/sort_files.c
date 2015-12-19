/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 19:45:54 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/19 14:47:57 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swap_files(t_file *f1, t_file *f2)
{
	t_data	*tmp;

	tmp = f1->data;
	f1->data = f2->data;
	f2->data = tmp;
}

void	sort_ascii(t_file *l_files)
{
	t_file	*cur;

	cur = l_files;
	if (cur == NULL)
		return ;
	while (cur->next != NULL)
	{
		if (ft_strcmp(cur->data->name, cur->next->data->name) > 0)
		{
			swap_files(cur, cur->next);
			cur = l_files;
		}
		else
			cur = cur->next;
	}
}

void	sort_time(t_file *l_files)
{
	t_file *cur;

	cur = l_files;
	if (cur == NULL)
		return ;
	while (cur->next != NULL)
	{
		if (cur->data->time < cur->next->data->time)
		{
			swap_files(cur, cur->next);
			cur = l_files;
		}
		else
			cur = cur->next;
	}
}

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
	sort_ascii(*l_files);
	if (opt->t)
		sort_time(*l_files);
	if (opt->r)
		reverse(l_files);
}
