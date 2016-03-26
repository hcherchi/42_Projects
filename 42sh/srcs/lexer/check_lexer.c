/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 20:46:12 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/15 12:55:05 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>
#include <parser.h>

int		syn_error(t_enum_token type)
{
	if (type == PIPE)
		ft_printf("parse error near '%s'\n", "|");
	else if (type == OR)
		ft_printf("parse error near '%s'\n", "||");
	else if (type == AND)
		ft_printf("parse error near '%s'\n", "&&");
	else if (type == ENDL)
		ft_printf("parse error near '%s'\n", "\\n");
	else if (type == SEMI)
		ft_printf("parse error near '%s'\n", ";");
	else if (type == PARENT_C || type == PARENT_O)
		ft_printf("parse error near '%s'\n", ")");
	else if (type == BACK_QUOTE)
		ft_printf("parse error near '%s'\n", "`");
	return (1);
}

int		syn_redir(t_token *token)
{
	int type;

	type = (token->type == REDIR) ? ((t_redir*)(token->content))->type : 0;
	if (type == 1)
		ft_printf("parse error near '%s'\n", ">");
	else if (type == 2)
		ft_printf("parse error near '%s'\n", ">>");
	else if (type == 3)
		ft_printf("parse error near '%s'\n", "<");
	else if (type == 4)
		ft_printf("parse error near '%s'\n", "<<");
	else
		ft_printf("parser error near redirection\n");
	return (1);
}

int		redir_ctrl(t_token *token)
{
	if (!token || token->type != WORD)
		return (0);
	return (1);
}

int		check_lexer(t_token *token_l)
{
	if (token_l->type == PIPE || token_l->type == OR
	|| token_l->type == AND || token_l->type == SEMI)
		return (syn_error(token_l->type));
	while (token_l->next)
	{
		if (token_l->type == SEMI && token_l->next->type == ENDL)
			return (syn_error(token_l->type));
		if (token_l->type == SEMI)
			return (check_lexer(token_l->next));
		if (parenthesis_ctrl(token_l) || backquote_ctrl(token_l))
			return (1);
		if ((token_l->type == PIPE || token_l->type == OR
		|| token_l->type == AND || token_l->type == REDIR)
		&& (token_l->next->type == PIPE || token_l->next->type == AND
		|| token_l->next->type == OR || token_l->next->type == SEMI
		|| token_l->next->type == ENDL || token_l->next->type == PARENT_C))
			return (syn_error(token_l->next->type));
		if ((token_l->type == PIPE || token_l->type == OR
		|| token_l->type == AND || token_l->type == REDIR)
		&& (!redir_ctrl(token_l->next)))
			return (syn_redir(token_l));
		token_l = token_l->next;
	}
	return (0);
}
