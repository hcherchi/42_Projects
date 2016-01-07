/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 17:29:57 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/07 17:32:18 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	ft_unsetenv(char ***myenv, char **av)
{
	int		i;
	char	*name;

	i = 0;
	if (tablen(av) != 2)
	{
		ft_putendl("One argument is needed for unsetenv");
		return ;
	}
	while ((*myenv)[i])
	{
		name = get_name((*myenv)[i]);
		if (!ft_strcmp(name, av[1]))
		{
			free(name);
			*myenv = remove_tab(*myenv, av[1]);
			return ;
		}
		i++;
		free(name);
	}
}
