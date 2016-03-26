/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 15:34:24 by jhoudan           #+#    #+#             */
/*   Updated: 2015/09/19 11:10:00 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmp)(void*, void*))
{
	if (!(*root))
	{
		*root = btree_create_node(item);
		return ;
	}
	if (cmp(item, (*root)->item) >= 0)
		btree_insert_data(&(*root)->right, item, cmp);
	else
		btree_insert_data(&(*root)->left, item, cmp);
}
