/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 17:46:57 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/07 18:42:22 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prompt(char *home)
{
	if (home)
	{
		ft_putstr(home);
		free(home);
	}
	ft_putstr("$>");
}

char	*get_elem(char **env, char *elem)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], elem, ft_strlen(elem)) == 0)
		{
			res = ft_strsub(env[i], ft_strlen(elem), ft_strlen(env[i]));
		}
		i++;
	}
	return (res);
}

void	lvlup(char ***myenv)
{
	char	*newlvl;
	char	*lvl;

	lvl = get_elem(*myenv, "SHLVL=");
	if (lvl == NULL)
	{
		ft_setenv(myenv, "SHLVL", "1");
		return ;
	}
	newlvl = ft_itoa(ft_atoi(lvl) + 1);
	ft_setenv(myenv, "SHLVL", newlvl);
	free(lvl);
	free(newlvl);
}

char	*strchange(char *str, char c, char *str2)
{
	char	*strnew;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str2)
		return (str);
	strnew = ft_strnew(ft_strlen(str) + ft_strlen(str2));
	while (str[i])
	{
		if (str[i] == c && j == 0)
		{
			ft_strcpy(strnew + i, str2);
			j = ft_strlen(str2) - 1;
		}
		else
		{
			strnew[i + j] = str[i];
		}
		i++;
	}
	free(str2);
	free(str);
	return (strnew);
}

char	*get_name(char *line)
{
	int		i;
	char	*name;

	i = 0;
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
