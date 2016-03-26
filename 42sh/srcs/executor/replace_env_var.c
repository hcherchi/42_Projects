/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:29:55 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/24 18:51:39 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "lexer.h"
#include "executor.h"
#include "libft.h"

static int	is_valid_char(char ch)
{
	if (ft_isspace(ch))
		return (0);
	if (ch == '|' || ch == ';' || ch == '&' || ch == '$' || ch == -4)
		return (0);
	return (1);
}

static int	concat_key_str(char **str, char *key, int i, int j)
{
	int		size;
	char	*value;
	char	*l_value;
	char	*start;
	char	*end;

	start = *str;
	while (i < j)
		(*str)[i++] = 0;
	end = (*str) + i;
	value = get_env(g_shell->env, key, 0);
	l_value = get_env(g_shell->l_env, key, 0);
	if (!value)
		value = l_value;
	if (!value)
		value = ft_strdup("");
	*str = ft_strnew(ft_strlen(start) + ft_strlen(end) + ft_strlen(value));
	ft_strcat(*str, start);
	ft_strcat(*str, value);
	ft_strcat(*str, end);
	ft_strdel(&start);
	size = ft_strlen(value);
	return (ft_strlen(value) - 1);
}

int			replace_env_var(char **str)
{
	int		i;
	int		j;
	char	*key;

	i = -1;
	if (!*str)
		*str = ft_strdup("");
	while ((*str)[++i])
	{
		if ((*str)[i] == -4)
		{
			j = i + 1;
			while ((*str)[j] && is_valid_char((*str)[j]))
				j++;
			key = ft_strsub(*str, i + 1, j - i - 1);
			i += concat_key_str(str, key, i, j);
			ft_strdel(&key);
		}
	}
	return (1);
}
