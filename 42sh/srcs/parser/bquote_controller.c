/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bquote_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:13:26 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/07 14:05:36 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		cut_liste(t_token **liste, t_token *ptr)
{
	if (*liste && (*liste)->prev)
		(*liste)->prev->next = NULL;
	if (*liste)
		(*liste)->prev = NULL;
	if (ptr && ptr->prev)
		ptr->prev->next = NULL;
	return (1);
}

static void		stick_token_liste(t_token **liste)
{
	t_token *ptr;

	ptr = (*liste)->next;
	ptr->prev = NULL;
	if ((*liste)->prev)
	{
		*liste = (*liste)->prev;
		while (ptr && ptr->type != BACK_QUOTE)
			ptr = ptr->next;
		del_one_token((*liste)->next);
		(*liste)->next = (ptr) ? ptr->next : NULL;
		(*liste) = (*liste)->next;
	}
	else
	{
		while (ptr && ptr->type != BACK_QUOTE)
			ptr = ptr->next;
		del_one_token(*liste);
		*liste = (ptr) ? ptr->next : NULL;
	}
	cut_liste(liste, ptr);
}

static t_token	*bquoted_liste(t_token **liste)
{
	t_token *start;

	start = (*liste)->next;
	stick_token_liste(liste);
	start->prev = NULL;
	return (start);
}

static int		pop_bquote_liste(t_token **liste)
{
	if ((*liste)->prev)
		(*liste)->prev->next = (*liste)->next->next;
	if ((*liste)->next->next)
		(*liste)->next->next->prev = (*liste)->prev;
	*liste = (*liste)->next;
	return (1);
}

t_arg			*bquote_controller(t_token **liste)
{
	t_arg		*new;
	t_parser	*tree;
	t_token		*bq_liste;

	if ((*liste)->next == NULL)
	{
		*liste = (*liste)->prev;
		while ((*liste)->type != BACK_QUOTE)
			*liste = (*liste)->prev;
	}
	new = NULL;
	if ((*liste)->next->type == BACK_QUOTE)
	{
		pop_bquote_liste(liste);
		return (new_arg(STRING, ft_strdup("")));
	}
	bq_liste = bquoted_liste(liste);
	go_tail(&bq_liste);
	tree = read_token(bq_liste);
	new = new_arg(B_QUOTE, tree);
	return (new);
}
