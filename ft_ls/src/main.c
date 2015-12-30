/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 11:50:55 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/30 17:36:26 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls_files(t_args *args)
{
	if (!args->files && !args->dirs && args->error == 0)
		recursive(".", args->opt);
	if (args->files)
	{
		args->nofile = 0;
		choose_sort(&(args->files), args->opt);
		print_files(args->files, args->opt);
		if (args->dirs)
			ft_putchar('\n');
	}
}

void	ft_ls_dirs(t_args *args)
{
	if (args->dirs)
	{
		if (args->dirs->next == NULL)
			args->onlyonedir = 1;
		choose_sort(&(args->dirs), args->opt);
		while (args->dirs)
		{
			if (!(args->onlyonedir && args->nofile) || args->error)
			{
				ft_putstr(args->dirs->data->path);
				ft_putendl(":");
			}
			recursive(args->dirs->data->path, args->opt);
			args->dirs = args->dirs->next;
			if (args->dirs != NULL)
				ft_putchar('\n');
		}
	}
}

int		main(int ac, char **av)
{
	int		i;
	t_args	*args;

	args = malloc(sizeof(*args));
	i = 1;
	init_args(args);
	while (i < ac && av[i][0] == '-')
	{
		check_options(av[i], args);
		i++;
	}
	if (args->opt->h)
	{
		hoption();
		return (0);
	}
	while (i < ac)
	{
		check_file(av[i], args);
		i++;
	}
	ft_ls_files(args);
	ft_ls_dirs(args);
	argsdel(args);
	return (0);
}
