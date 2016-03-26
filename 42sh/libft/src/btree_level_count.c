/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/19 15:02:00 by jhoudan           #+#    #+#             */
/*   Updated: 2015/09/19 15:54:19 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		btree_level_count(t_btree *root)
{
	int test1;
	int test2;

	if (root == 0)
		return (0);
	else
	{
		test1 = 1 + btree_level_count(root->left);
		test2 = 1 + btree_level_count(root->right);
		if (test1 > test2)
			return (test1);
		else
			return (test2);
	}
	return (0);
}
