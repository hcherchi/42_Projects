/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_concat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:15:38 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/14 10:51:25 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <parser.h>
#include <lexer.h>

static int	look_for_var(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == '$' && (!i || str[i - 1] != '\\'))
			str[i] = -4;
	return (1);
}

static char	*quotes_append_word(char **str, char *word)
{
	char	*tmp;

	if (!*str)
	{
		*str = ft_strdup(word);
		return (*str);
	}
	tmp = *str;
	*str = ft_strjoin(*str, word);
	ft_strdel(&tmp);
	return (*str);
}

static char	*quotes_append(char **str, char *word, int type)
{
	if (type == DOUBLE_QUOTE)
		look_for_var(word);
	escape_char_in_quote(word);
	quotes_append_word(str, word);
	return (*str);
}

char		*quotes_concat(t_token **liste)
{
	char	*str;
	t_token	*ptr;

	str = NULL;
	ptr = *liste;
	while (ptr && (ptr->type == WORD || is_simp_doub_quote(ptr)))
	{
		if (is_simp_doub_quote(ptr))
		{
			quotes_append(&str, ptr->next->content, ptr->type);
			ptr = ptr->next->next;
			if (!is_quote_sticky(ptr) || (ptr->next &&
				!is_quote_sticky(ptr->next) && ptr->next->type != WORD))
				break ;
		}
		if (ptr->type == WORD)
		{
			quotes_append_word(&str, ptr->content);
			if (!is_quote_sticky(ptr->next))
				break ;
		}
		ptr = ptr->next;
	}
	*liste = ptr;
	return (str);
}
