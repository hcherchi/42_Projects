/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:34:07 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 19:57:57 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**add_tab(char **tab, char *elem)
{
	int		i;
	char	**newenv;

	newenv = (char **)malloc(sizeof(char *) * (tablen(tab) + 2));
	i = 0;
	while (tab[i])
	{
		newenv[i] = ft_strdup(tab[i]);
		i++;
	}
	newenv[i] = ft_strdup(elem);
	newenv[i + 1] = NULL;
	tabdel(&tab);
	return (newenv);
}

void	ft_setenv(char ***myenv, char *av1, char *av2, char **av)
{
	int		i;
	char	*name;

	if (av && tablen(av) != 3)
	{
		ft_putendl("Invalid number of args.");
		return ;
	}
	i = 0;
	while ((*myenv)[i])
	{
		name = get_name((*myenv)[i]);
		if (!ft_strcmp(name, av1))
		{
			free(name);
			(*myenv)[i] = add_path(av1, av2, '=');
			return ;
		}
		free(name);
		i++;
	}
	*myenv = add_tab(*myenv, add_path(av1, av2, '='));
}

char	*get_name(char *line)
{
	int		i;
	char	*name;

	i = 0;
	if (!ft_strcmp(line, ""))
		return (ft_strdup(""));
	while (line[i] != '=')
		i++;
	name = (char *)malloc(sizeof(*name) * i + 1);
	i = 0;
	while (line[i] != '=')
	{
		name[i] = line[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}
