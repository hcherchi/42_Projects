/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_liste.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:14:34 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/18 19:14:35 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "lexer.h"
#include "libft.h"

int		split_liste(t_token **head, t_token **right, t_token **left)
{
	*right = (*head)->next;
	*left = (*head)->prev;
	if (*right)
		(*right)->prev = NULL;
	if (*left)
		(*left)->next = NULL;
	go_tail(right);
	del_one_token(*head);
	*head = NULL;
	return (1);
}
