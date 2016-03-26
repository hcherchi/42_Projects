/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 20:46:02 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/14 14:37:54 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

void	add_token(t_token **t, void *content, t_enum_token type)
{
	t_token	*new;
	t_token	*cur;

	cur = *t;
	new = malloc(sizeof(*new));
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	new->type = type;
	if (!(*t))
		*t = new;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = new;
		new->prev = cur;
	}
}

void	push_valid_token(t_token **head, t_token *new_token)
{
	t_token		*cur;

	cur = *head;
	new_token->next = NULL;
	new_token->prev = NULL;
	if (!cur)
		*head = new_token;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = new_token;
		new_token->prev = cur;
	}
}

t_redir	*new_redir(int from, t_enum_redir type)
{
	t_redir	*new;

	if (!(new = malloc(sizeof(*new))))
		return (NULL);
	new->type = type;
	new->from = from;
	return (new);
}

t_redir	*parse_new_redir(char *str)
{
	int				from;

	if (!ft_isdigit(*str))
		from = 1;
	else
		from = ft_atoi(str);
	if (is_r_double(str))
		return (new_redir(from, R_DOUBLE));
	else if (is_l_double(str))
		return (new_redir(from, L_DOUBLE));
	else if (is_r_simple(str))
		return (new_redir(from, R_SIMPLE));
	else if (is_l_simple(str))
		return (new_redir(from, L_SIMPLE));
	return (NULL);
}
