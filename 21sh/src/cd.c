/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 18:54:29 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 21:47:51 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_cd(char ***myenv, char **args)
{
	char	**split;
	int		i;
	char	*direction;

	i = 0;
	if (tablen(args) == 1)
		direction = get_elem(*myenv, "HOME=");
	else
	{
		if (args[1][0] == '/')
			direction = "/";
		else
			direction = get_elem(*myenv, "PWD=");
		split = ft_strsplit(args[1], '/');
		while (split[i] && direction != NULL)
		{
			direction = cdsplit(split[i], direction);
			i++;
		}
	}
	if (direction)
	{
		chdir(direction);
		ft_setenv(myenv, "PWD", direction, NULL);
	}
}

char	*cdsplit(char *split, char *direction)
{
	char		*newpath;
	struct stat	*stats;

	stats = malloc(sizeof(*stats));
	newpath = add_path(direction, split, '/');
	lstat(newpath, stats);
	if (!ft_strcmp(split, ".."))
		direction = del_path(direction);
	else if (S_ISDIR(stats->st_mode) && !access(newpath, X_OK))
	{
		if (!(ft_strcmp(split, ".") == 0))
			direction = newpath;
	}
	else
		cd_error(newpath, &direction);
	return (direction);
}

void	cd_error(char *newpath, char **direction)
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
	*direction = NULL;
	free(stats);
}
