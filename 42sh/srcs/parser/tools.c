/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:14:39 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/19 17:21:35 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "lexer.h"

int			go_tail(t_token **ptr)
{
	while ((*ptr)->next)
		*ptr = (*ptr)->next;
	return (1);
}

int			go_head(t_token **ptr)
{
	while ((*ptr)->prev)
		*ptr = (*ptr)->prev;
	return (1);
}

int			cmd_wiv_bquote(t_arg *ptr)
{
	while (ptr)
	{
		if (ptr->type == B_QUOTE)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

t_parser	*parenthesis_controller(t_token **liste)
{
	t_token		*ptr;
	t_parser	*new;

	ptr = *liste;
	if (ptr->next->type == PARENT_C)
		return (NULL);
	go_tail(liste);
	ptr->next->prev = NULL;
	free(ptr);
	ptr = *liste;
	if (ptr->type == ENDL)
	{
		*liste = (*liste)->prev;
		(*liste)->next = NULL;
		free(ptr);
	}
	ptr = *liste;
	*liste = (*liste)->prev;
	(*liste)->next = NULL;
	free(ptr);
	new = new_node_parser(NODE_SUBSHELL, read_token(*liste));
	return (new);
}
