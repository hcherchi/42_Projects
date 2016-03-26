/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:13:58 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/19 13:05:07 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"
#include "libft.h"

int		del_token_liste(t_token *head)
{
	t_token *ptr;

	while (head)
	{
		ptr = head;
		head = head->next;
		if (ptr->content)
			free(ptr->content);
		free(ptr);
	}
	return (1);
}

int		del_one_token(t_token *node)
{
	if (!node)
		return (0);
	if (node->content)
		free(node->content);
	free(node);
	return (1);
}
