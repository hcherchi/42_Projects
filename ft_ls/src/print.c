/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 11:51:07 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/06 14:07:05 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	basic_print(t_file *l_files, t_option *opt)
{
	t_file *cur;

	cur = l_files;
	while (cur)
	{
		ft_putstr(cur->data->name);
		if (cur->data->mod[0] == 'd' && opt->p == 1)
			ft_putendl("/");
		else
			ft_putchar('\n');
		cur = cur->next;
	}
}

void	total_bits(t_file *l_files)
{
	long long	i;
	t_file		*cur;
	char		*res;

	i = 0;
	cur = l_files;
	while (cur)
	{
		i += (cur->data->nb_blocks);
		cur = cur->next;
	}
	ft_putstr("total ");
	res = ft_itoa(i);
	ft_putendl(res);
	free(res);
}

void	extend_print(t_file *l_files, t_option *opt)
{
	t_file	*cur;
	char	*time;

	cur = l_files;
	while (cur)
	{
		if (cur->data->mod[0] == '?')
			return (ft_error3(cur->data->name));
		time = ft_strsub(ctime(&(cur->data->time)), 4, 12);
		ft_putstrsp(cur->data->mod);
		ft_putstrsp(cur->data->nblink);
		if (opt->g == 0)
			ft_putstrsp(cur->data->uid);
		ft_putstrsp(cur->data->gid);
		ft_putstrsp(cur->data->nboct);
		ft_putstrsp(time);
		ft_putstr(cur->data->name);
		if (cur->data->mod[0] == 'd' && opt->p == 1)
			ft_putchar('/');
		if (cur->data->mod[0] == 'l')
			putlink(cur);
		ft_putchar('\n');
		free(time);
		cur = cur->next;
	}
}

void	print_files(t_file *l_files, t_option *opt)
{
	if (opt->l || opt->g)
		extend_print(l_files, opt);
	else
		basic_print(l_files, opt);
}

void	recursive(char *path, t_option *opt)
{
	t_file *cur;
	t_file *l_files;

	l_files = init_files(path, opt);
	cur = l_files;
	if ((opt->l || opt->g) && l_files)
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
				putpath(cur);
				recursive(cur->data->path, opt);
			}
			cur = cur->next;
		}
		l_filesdel(l_files);
	}
	else
		l_filesdel(l_files);
}
