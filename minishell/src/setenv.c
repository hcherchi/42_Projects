/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 17:32:29 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/07 17:32:30 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	ft_setenv(char ***myenv, char *av1, char *av2)
{
	int		i;
	char	*name;

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
