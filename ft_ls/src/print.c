/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 10:17:37 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/14 12:16:21 by bgantelm         ###   ########.fr       */
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
	total_bits(cur);
	while (cur)
	{
		ft_putstrsp(cur->data->mod);
		ft_putstrsp(cur->data->nblink);
		ft_putstrsp(cur->data->uid);
		ft_putstrsp(cur->data->gid);
		ft_putstrsp(cur->data->nboct);
		ft_putstrsp(cur->data->time);
		ft_putstrsp(cur->data->name);
		if (cur->data->mod[0] == 'l')
		{
			ft_putstr(" -> ");
			ft_putstr(cur->data->namelk);
		}
		ft_putchar('\n');
		cur = cur->next;
	}
}

void	print_files(t_file *l_files, char *options)
{
	if (instr(options, 'l') == 1)
		extend_print(l_files);
	else
		basic_print(l_files);
}

void	ft_ls(char *path, char *options)
{
	t_file *l_files;
	t_file *cur;

	l_files = init_files(path, options);
	cur = l_files;
	print_files(l_files, options);
	if (instr(options, 'R') == 1)
	{
		while (cur)
		{
			if (cur->data->mod[0] == 'd' && cur->data->mod[1] == 'r' && ft_strequ(cur->data->name, "..") == 0 && ft_strequ(cur->data->name, ".") == 0)
			{
				ft_putchar('\n');
				ft_putstr(cur->data->path);
				ft_putchar(':');
				ft_putchar('\n');
				ft_ls(cur->data->path, options);
			}
			cur = cur->next;
		}
		l_filesdel(l_files);
	}
}
