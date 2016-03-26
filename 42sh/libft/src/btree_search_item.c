/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/18 16:02:24 by jhoudan           #+#    #+#             */
/*   Updated: 2015/09/19 14:28:58 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_search_item(t_btree *root,
		void *data_ref, int (*cmpf)(void *, void*))
{
	if (root == NULL)
		return (0);
	else if (cmpf(data_ref, root->item) < 0)
		return (btree_search_item(root->left, data_ref, cmpf));
	else if (cmpf(data_ref, root->item) > 0)
		return (btree_search_item(root->right, data_ref, cmpf));
	else if (cmpf(data_ref, root->item) == 0)
		return (root->item);
	return (0);
}
