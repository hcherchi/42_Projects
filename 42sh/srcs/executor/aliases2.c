/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aliases2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:25:10 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/21 11:31:38 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>
#include <stdlib.h>
#include <stdio.h>

int			expand_aliases(char **str, int i)
{
	char	*word;

	while ((*str)[i])
	{
		while ((*str)[i] == ' ')
			i++;
		if ((*str)[i])
		{
			word = get_next_word(*str, i);
			i += expand_alias(str, i, word);
			if ((*str)[i])
				move_to_next_cmd(*str, &i);
			free(word);
		}
	}
	return (SUCCESS);
}

char		*get_next_word(char *str, int beg)
{
	int		i;

	i = 0;
	while (str[beg + i] && str[beg + i] != ' ')
	{
		if (is_special(str[beg + i]))
			break ;
		i++;
	}
	return (ft_strsub(str, beg, i));
}

static int	fuck_norme(char *w)
{
	int		j;

	j = ft_strlen(w);
	free(w);
	return (j);
}

int			expand_alias(char **str, int i, char *expanded)
{
	char	*w;
	char	*alias;
	char	*recur;
	int		j;

	if ((j = 0) == 0 && (*str)[i] == '\0')
		return (0);
	w = get_next_word(*str, i);
	if ((alias = get_alias(w)) == w)
		return (fuck_norme(w));
	while (alias[j])
	{
		recur = get_next_word(alias, j);
		if (recur[0] && ft_strcmp(recur, w) != 0 &&
				ft_strcmp(recur, expanded) != 0)
			j += expand_alias(&alias, j, expanded);
		free(recur);
		move_to_next_cmd(alias, &j);
	}
	insert_string(str, i, i + ft_strlen(w) - 1, alias);
	free(alias);
	free(w);
	return (j);
}

void		move_to_next_cmd(char *str, int *i)
{
	int		quote;
	char	quotechar;

	quote = 0;
	while (str[*i] && ((str[*i] != ';' && str[*i] != '`') || quote))
	{
		if (quote == 0 && (str[*i] == '\'' || str[*i] == '"'))
		{
			quote = 1;
			quotechar = str[*i];
		}
		else if (quote == 1 && str[*i] == quotechar)
			quote = 0;
		(*i)++;
	}
	if (str[*i] && (str[*i] == ';' || str[*i] == '`') && !quote)
		(*i)++;
	while (str[*i] && str[*i] == ' ')
		(*i)++;
}
