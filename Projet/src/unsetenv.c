/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:51:25 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 19:51:36 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	**remove_tab(char **tab, char *elem)
{
	int		i;
	int		j;
	char	**newenv;
	char	*name;

	newenv = (char **)malloc(sizeof(char *) * tablen(tab));
	i = 0;
	j = 0;
	while (tab[i])
	{
		name = get_name(tab[i]);
		if (ft_strcmp(name, elem) != 0)
		{
			newenv[j] = ft_strdup(tab[i]);
			j++;
			i++;
		}
		else
			i++;
		free(name);
	}
	newenv[j] = NULL;
	tabdel(&tab);
	return (newenv);
}

void	ft_unsetenv(char ***myenv, char *av1, char **av)
{
	int		i;
	char	*name;

	i = 0;
	if (av && tablen(av) != 2)
	{
		ft_putendl("One argument is needed for unsetenv");
		return ;
	}
	while ((*myenv)[i])
	{
		name = get_name((*myenv)[i]);
		if (!ft_strcmp(name, av1))
		{
			free(name);
			*myenv = remove_tab(*myenv, av1);
			return ;
		}
		i++;
		free(name);
	}
}
