/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:18:29 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/20 12:48:33 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"
#include "libft.h"

int			look_for_semi(t_token **ptr)
{
	t_token *tmp;
	int		bquote;
	int		par;

	bquote = 0;
	par = 0;
	tmp = *ptr;
	while (tmp->prev != NULL)
	{
		if (tmp->type == SEMI && !bquote && !par)
			break ;
		if (tmp->type == BACK_QUOTE)
			bquote = (!bquote) ? 1 : 0;
		if (tmp->type == PARENT_O || tmp->type == PARENT_C)
			par = (tmp->type == PARENT_O) ? par + 1 : par - 1;
		tmp = tmp->prev;
	}
	if (tmp && tmp->type == SEMI)
	{
		*ptr = tmp;
		return (1);
	}
	return (0);
}

int			look_for_or_and(t_token **ptr)
{
	t_token *tmp;
	int		bquote;
	int		par;

	par = 0;
	bquote = 0;
	tmp = *ptr;
	while (tmp->prev != NULL)
	{
		if ((tmp->type == OR || tmp->type == AND) && !bquote && !par)
			break ;
		if (tmp->type == BACK_QUOTE)
			bquote = (!bquote) ? 1 : 0;
		if (tmp->type == PARENT_O || tmp->type == PARENT_C)
			par = (tmp->type == PARENT_O) ? par + 1 : par - 1;
		tmp = tmp->prev;
	}
	if (tmp && (tmp->type == OR || tmp->type == AND))
	{
		*ptr = tmp;
		return ((tmp->type == OR) ? 1 : 2);
	}
	return (0);
}

int			look_for_pipe(t_token **ptr)
{
	t_token *tmp;
	int		bquote;
	int		par;

	par = 0;
	bquote = 0;
	tmp = *ptr;
	while (tmp->prev != NULL)
	{
		if (tmp->type == PIPE && !bquote && !par)
			break ;
		if (tmp->type == BACK_QUOTE)
			bquote = (!bquote) ? 1 : 0;
		if (tmp->type == PARENT_O || tmp->type == PARENT_C)
			par = (tmp->type == PARENT_O) ? par + 1 : par - 1;
		tmp = tmp->prev;
	}
	if (tmp && tmp->type == PIPE)
	{
		*ptr = tmp;
		return (1);
	}
	return (0);
}

void		read_until_cmd(t_token **ptr, t_parser **new)
{
	t_token		*left;
	t_token		*right;
	t_connect	*connect_l;
	t_node_cmd	*cmd;

	left = NULL;
	right = NULL;
	connect_l = NULL;
	if (*new)
	{
		split_liste(ptr, &right, &left);
		(*new)->left = read_token(left);
		(*new)->right = read_token(right);
	}
	else
	{
		if ((*ptr)->type == PARENT_O)
			*new = parenthesis_controller(ptr);
		else
		{
			connect_l = new_connect_l(ptr);
			cmd = new_node_cmd(token_to_cmd(*ptr), connect_l);
			*new = new_node_parser(NODE_CMD, cmd);
		}
	}
}

t_parser	*read_token(t_token *ptr)
{
	t_parser	*new;

	new = NULL;
	if (!ptr || (ptr->type == ENDL && (!ptr->prev && !ptr->next)))
		return (NULL);
	if (look_for_semi(&ptr))
		new = new_node_parser(NODE_SEP_THEN, NULL);
	else if (look_for_or_and(&ptr))
		new = new_node_parser((ptr->type == OR) ?
				NODE_SEP_NOR : NODE_SEP_AND, NULL);
	else if (look_for_pipe(&ptr))
		new = new_node_parser(NODE_PIPE, NULL);
	if (!new)
		go_head(&ptr);
	read_until_cmd(&ptr, &new);
	if (new && new->type == NODE_CMD && !cmd_wiv_bquote((t_arg*)new->data))
	{
		go_head(&ptr);
		del_token_liste(ptr);
	}
	return (new);
}
