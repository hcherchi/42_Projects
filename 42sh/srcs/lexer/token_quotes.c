/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 20:45:52 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/15 11:18:32 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>
#include <parser.h>
#define F_NORME(e) (e->type == WORD && e->next && is_quote_sticky(e->next))

static int		parse_token_simple_quote(t_token **token_list,
	char *line, int i)
{
	int		*spaces_b;
	int		*spaces_a;
	int		j;

	spaces_b = malloc(sizeof(int));
	spaces_a = malloc(sizeof(int));
	if (i > 0 && ft_isspace(line[i - 1]))
		*spaces_b = 1;
	else
		*spaces_b = 0;
	j = i + 1;
	while (line[j] && line[j] != '\'')
		j++;
	if (!line[j] || (line[j] && !ft_isspace(line[j + 1])))
		*spaces_a = 0;
	else
		*spaces_a = 1;
	add_token(token_list, spaces_b, SIMPLE_QUOTE);
	add_token(token_list, ft_strsub(line, i + 1, j - i - 1), WORD);
	add_token(token_list, spaces_a, SIMPLE_QUOTE);
	return (j - i + 1);
}

static int		parse_token_double_quote(t_token **token_list, char *l, int i)
{
	int		*spaces_b;
	int		*spaces_a;
	int		j;

	spaces_b = malloc(sizeof(int));
	spaces_a = malloc(sizeof(int));
	if (i == 0 || (i > 0 && !ft_isspace(l[i - 1])))
		*spaces_b = 0;
	else
		*spaces_b = 1;
	j = i + 1;
	while (l[j] && l[j] != '"')
	{
		if (l[j] == '\\')
			j++;
		j++;
	}
	if (!l[j] || (l[j] && !ft_isspace(l[j + 1])) || (l[j] && !l[j + 1]))
		*spaces_a = 0;
	else
		*spaces_a = 1;
	add_token(token_list, spaces_b, DOUBLE_QUOTE);
	add_token(token_list, ft_strsub(l, i + 1, j - i - 1), WORD);
	add_token(token_list, spaces_a, DOUBLE_QUOTE);
	return (j - i + 1);
}

int				parse_token_quote(t_token **token_list, char *line, int i)
{
	if (line[i] == '\'')
		return (parse_token_simple_quote(token_list, line, i));
	else
		return (parse_token_double_quote(token_list, line, i));
}

static t_redir	*create_redir(t_token *elem)
{
	t_redir		*content;

	content = (t_redir *)malloc(sizeof(t_redir));
	content->type = ((t_redir *)(elem->content))->type;
	content->from = ((t_redir *)(elem->content))->from;
	return (content);
}

t_token			*rebuild_quotes(t_token *head)
{
	t_token		*new_list;
	t_token		*elem;

	new_list = NULL;
	elem = head;
	while (elem)
	{
		if (is_simp_doub_quote(elem) || F_NORME(elem))
			add_token(&new_list, quotes_concat(&elem), WORD);
		else
		{
			if (elem->type == REDIR)
				add_token(&new_list, create_redir(elem), elem->type);
			else if (elem->type == WORD)
				add_token(&new_list, ft_strdup(elem->content), WORD);
			else
				add_token(&new_list, NULL, elem->type);
		}
		elem = elem->next;
	}
	return (new_list);
}
