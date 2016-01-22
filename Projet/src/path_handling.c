/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:23:27 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 19:23:48 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	select_path(char *paths, char *elem, char **good_path)
{
	int		i;
	char	**tab_paths;

	i = 0;
	if (paths == NULL)
	{
		*good_path = NULL;
		return ;
	}
	tab_paths = ft_strsplit(paths, ':');
	while (tab_paths[i])
	{
		*good_path = add_path(tab_paths[i], elem, '/');
		if (access(*good_path, F_OK) == 0)
			return ;
		i++;
	}
	*good_path = NULL;
}

char	*add_path(char *p, char *n, char c)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(*new) * (ft_strlen(p) + ft_strlen(n) + 2));
	if (new == NULL)
		return (NULL);
	while (*p)
	{
		new[i] = *p++;
		i++;
	}
	if (new[i - 1] != c)
	{
		new[i] = c;
		i++;
	}
	while (*n)
	{
		new[i] = *n++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*del_path(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	while (s[i] != '/')
	{
		if (s[i] != '\0')
			s[i] = '\0';
		i--;
	}
	if (s[i] == '/' && ft_strlen(s) > 1)
		s[i] = '\0';
	return (s);
}
