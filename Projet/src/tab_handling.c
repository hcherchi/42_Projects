/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:38:02 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 21:02:48 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			tablen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void		tabdel(char ***tab)
{
	int		i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
	free(*tab);
	*tab = NULL;
}

char		**tab_dup(char **env)
{
	int		i;
	char	**dup;

	dup = (char **)malloc(sizeof(char *) * (tablen(env) + 1));
	i = 0;
	while (env[i])
	{
		dup[i] = ft_strdup(env[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}

char		**cuttab(char **tab, int i)
{
	char	**newtab;
	int		j;

	j = 0;
	newtab = (char **)malloc(sizeof(*newtab) * (tablen(tab) - i + 1));
	while (tab[i])
	{
		newtab[j] = ft_strdup(tab[i]);
		j++;
		i++;
	}
	newtab[j] = NULL;
	return (newtab);
}

char		**newtab(void)
{
	char	**newtab;

	newtab = (char **)malloc(sizeof(*newtab) * 1);
	newtab[0] = NULL;
	return (newtab);
}
