/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 09:36:10 by jhoudan           #+#    #+#             */
/*   Updated: 2015/09/18 12:54:49 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree		*btree_create_node(void *item)
{
	t_btree *new;

	new = malloc(sizeof(t_btree));
	if (new != NULL)
	{
		new->item = item;
		new->right = 0;
		new->left = 0;
	}
	return (new);
}
