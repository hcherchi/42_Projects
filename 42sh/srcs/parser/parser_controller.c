/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:15:47 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/23 16:58:03 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "lexer.h"

t_parser	*parser_controller(t_token *tail)
{
	t_parser *head;

	if (!tail || tail->type == ENDL)
		return (NULL);
	head = NULL;
	go_tail(&tail);
	head = read_token(tail);
	return (head);
}
