/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_boolean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 16:16:18 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/07 11:46:32 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

static int	is_token_separator(t_token *token)
{
	if (token->type == SEMI || token->type == OR || token->type == AND)
		return (1);
	return (0);
}

static int	count_backquote(t_token *ptr)
{
	int count;

	count = 0;
	while (ptr)
	{
		if (ptr->type == BACK_QUOTE)
			count++;
		ptr = ptr->next;
	}
	return (count);
}

static int	only_redir(t_token *token, int type)
{
	if (token->type != REDIR)
		return (0);
	if (token->type == REDIR && (!token->next ||
		is_token_separator(token->next) || token->next->type == type
		|| (token->next->type == WORD && token->next->next
		&& token->next->next->type == type)))
		return (1);
	return (0);
}

int			backquote_ctrl(t_token *token)
{
	int count;

	if (token->type != BACK_QUOTE)
		return (0);
	count = count_backquote(token->next);
	if (count % 2 == 0)
	{
		if (token->prev && (is_token_separator(token->prev)
					|| token->prev->type == PIPE
					|| token->prev->type == BACK_QUOTE))
			return (ft_putstr_fd("parse error near '`'\n", STDERR_FILENO));
	}
	else
	{
		if (!token->next || is_token_separator(token->next)
		|| only_redir(token->next, BACK_QUOTE))
			return (ft_putstr_fd("parse error near '`'\n", STDERR_FILENO));
	}
	return (0);
}

int			parenthesis_ctrl(t_token *token)
{
	if (token->type != PARENT_O && token->type != PARENT_C)
		return (0);
	if (token->type == PARENT_C && !token->next)
		return (0);
	if (token->type == PARENT_O && token->next->type == PARENT_C)
		return (ft_putstr_fd("parse error near '('\n", STDERR_FILENO));
	if (token->type == PARENT_O && token->prev
			&& !is_token_separator(token->prev) && token->prev->type != PIPE)
		return (ft_putstr_fd("parse error near '('\n", STDERR_FILENO));
	if (token->type == PARENT_O
			&& (is_token_separator(token->next) || token->next->type == PIPE
			|| only_redir(token->next, PARENT_C)))
		return (ft_putstr_fd("parse error near '('\n", STDERR_FILENO));
	if (token->type == PARENT_C && (token->next
				&& !is_token_separator(token->next)
				&& token->next->type != ENDL && token->next->type != PIPE))
		return (ft_putstr_fd("parse error near ')'\n", STDERR_FILENO));
	return (0);
}
