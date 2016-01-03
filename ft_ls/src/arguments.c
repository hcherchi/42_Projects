/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 11:50:11 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/30 17:35:41 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_args(t_args *args)
{
	t_option	*opt;
	t_file		*dirs;
	t_file		*files;

	opt = malloc(sizeof(*opt));
	dirs = NULL;
	files = NULL;
	args->opt = opt;
	args->dirs = dirs;
	args->files = files;
	args->nofile = 1;
	args->opt->p = 0;
	args->onlyonedir = 0;
	args->opt->rmaj = 0;
	args->opt->l = 0;
	args->opt->a = 0;
	args->opt->t = 0;
	args->opt->r = 0;
	args->opt->f = 0;
	args->opt->g = 0;
	args->opt->h = 0;
	args->dirs = NULL;
	args->files = NULL;
	args->error = 0;
}

void	check_options(char *av, t_args *args)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (av[i] != 'R' && av[i] != 'l' &&
		av[i] != 'a' && av[i] != 'r' &&
		av[i] != 't' && av[i] != 'p' && av[i] != 'f' && av[i] != 'g' &&
		av[i] != 'h')
			ft_error(av[i]);
		i++;
	}
	if (i == 1)
	{
		ft_error2(av);
		args->error = 1;
	}
	modif_options(av, args);
}

void	modif_options(char *av, t_args *args)
{
	int i;

	i = 0;
	while (av[i])
	{
		if (av[i] == 'R' && args->opt->rmaj == 0)
			args->opt->rmaj = 1;
		if (av[i] == 'l' && args->opt->l == 0)
			args->opt->l = 1;
		if (av[i] == 'a' && args->opt->a == 0)
			args->opt->a = 1;
		if (av[i] == 'r' && args->opt->r == 0)
			args->opt->r = 1;
		if (av[i] == 't' && args->opt->t == 0)
			args->opt->t = 1;
		if (av[i] == 'p' && args->opt->p == 0)
			args->opt->p = 1;
		if (av[i] == 'f' && args->opt->f == 0)
			args->opt->f = 1;
		if (av[i] == 'g' && args->opt->g == 0)
			args->opt->g = 1;
		if (av[i] == 'h' && args->opt->h == 0)
			args->opt->h = 1;
		i++;
	}
}

void	check_file(char *av, t_args *args)
{
	struct stat	*stats;

	stats = malloc(sizeof(*stats));
	if (!lstat(av, stats))
	{
		if (S_ISDIR(stats->st_mode))
			add_file(&(args->dirs), new_file(ft_strdup(av)));
		else if (S_ISREG(stats->st_mode))
			add_file(&(args->files), new_file(ft_strdup(av)));
		else if (S_ISLNK(stats->st_mode))
		{
			if (args->opt->l)
				add_file(&(args->files), new_file(ft_strdup(av)));
			else
				add_file(&(args->dirs), new_file(ft_strdup(av)));
		}
	}
	else
	{
		ft_error2(av);
		args->error = 1;
	}
	free(stats);
}
