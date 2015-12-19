/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 10:17:37 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/19 14:56:32 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	basic_print(t_file *l_files)
{
	t_file *cur;

	cur = l_files;
	while (cur)
	{
		ft_putendl(cur->data->name);
		cur = cur->next;
	}
}

void	total_bits(t_file *l_files)
{
	long long	i;
	t_file		*cur;

	i = 0;
	cur = l_files;
	while (cur)
	{
		i += (cur->data->nb_blocks);
		cur = cur->next;
	}
	ft_putstr("total ");
	ft_putendl(ft_itoa(i));
}

void	extend_print(t_file *l_files)
{
	t_file *cur;

	cur = l_files;
	while (cur)
	{
		ft_putstrsp(cur->data->mod);
		ft_putstrsp(cur->data->nblink);
		ft_putstrsp(cur->data->uid);
		ft_putstrsp(cur->data->gid);
		ft_putstrsp(cur->data->nboct);
		ft_putstrsp(ft_strsub(ctime(&(cur->data->time)), 4, 12));
		ft_putstr(cur->data->name);
		if (cur->data->mod[0] == 'l')
		{
			ft_putstr(" -> ");
			ft_putstr(cur->data->namelk);
		}
		ft_putchar('\n');
		cur = cur->next;
	}
}

void	print_files(t_file *l_files, t_option *opt)
{
	if (opt->l)
		extend_print(l_files);
	else
		basic_print(l_files);
}

void	recursive(char *path, t_option *opt)
{
	t_file *cur;
	t_file *l_files;

	l_files = init_files(path, opt);
	cur = l_files;
	if (opt->l)
		total_bits(l_files);
	print_files(l_files, opt);
	if (opt->rmaj)
	{
		while (cur)
		{
			if (cur->data->mod[0] == 'd'
				&& ft_strequ(cur->data->name, "..") == 0
				&& ft_strequ(cur->data->name, ".") == 0)
			{
				ft_putchar('\n');
				ft_putstr(cur->data->path);
				ft_putstr(":\n");
				recursive(cur->data->path, opt);
			}
			cur = cur->next;
		}
		l_filesdel(l_files);
	}
}
