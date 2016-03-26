/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:15:15 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/18 19:15:16 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <ftsh.h>

t_arg	*new_arg(int type, void *content)
{
	t_arg *new;

	if ((new = (t_arg*)malloc(sizeof(t_arg))) == NULL)
		return (NULL);
	new->type = type;
	new->data = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	add_arg(t_arg **head, t_arg *new)
{
	t_arg *ptr;

	if (!*head)
		return ((void)(*head = new));
	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	new->prev = ptr;
}
