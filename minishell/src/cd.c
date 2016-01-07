/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 17:07:52 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/07 17:56:29 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char ***myenv, char **av)
{
	char	**split;
	int		i;
	char	*home;

	i = 0;
	if (tablen(av) == 1)
		home = get_elem(*myenv, "HOME=");
	else
	{
		if (av[1][0] == '/')
			home = "/";
		else
			home = get_elem(*myenv, "PWD=");
		split = ft_strsplit(av[1], '/');
		while (split[i] && home != NULL)
		{
			home = cdsplit(split[i], home);
			i++;
		}
	}
	if (home)
	{
		chdir(home);
		ft_setenv(myenv, "PWD", home);
	}
}

char	*cdsplit(char *split, char *home)
{
	char	*newpath;

	newpath = add_path(home, split, '/');
	if (!ft_strcmp(split, ".."))
		home = del_path(home);
	else if (!chdir(newpath))
	{
		if (!(ft_strcmp(split, ".") == 0))
			home = newpath;
	}
	else
		cd_error(newpath, &home);
	return (home);
}

void	cd_error(char *newpath, char **home)
{
	struct stat	*stats;

	stats = malloc(sizeof(*stats));
	lstat(newpath, stats);
	if (access(newpath, F_OK) == 0)
	{
		if (!(S_ISREG(stats->st_mode)))
			ft_putendl("cd : permission denied");
		else
			ft_putendl("cd : not a directory");
	}
	else
		ft_putendl("cd: no such file or directory");
	*home = NULL;
	free(stats);
}
