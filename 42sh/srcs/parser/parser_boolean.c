/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_boolean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:15:55 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/24 10:57:04 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "lexer.h"

int		is_separator(int type)
{
	if (type == SEMI || type == OR || type == AND || type == PIPE)
		return (1);
	return (0);
}

int		parser_is_quote(int type)
{
	if (type == BACK_QUOTE || type == PARENT_O || type == PARENT_C
			|| type == SIMPLE_QUOTE || type == DOUBLE_QUOTE)
		return (1);
	return (0);
}

int		parser_is_parent(int type)
{
	if (type == PARENT_O || type == PARENT_C)
		return (1);
	return (0);
}

int		is_simp_doub_quote(t_token *x)
{
	if (x && (x->type == SIMPLE_QUOTE || x->type == DOUBLE_QUOTE))
		return (1);
	return (0);
}

int		is_quote_sticky(t_token *x)
{
	if (x && (x->type == SIMPLE_QUOTE
				|| x->type == DOUBLE_QUOTE) && *((int *)x->content) == 0)
		return (1);
	return (0);
}
