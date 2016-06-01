/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:51:58 by vnguyen           #+#    #+#             */
/*   Updated: 2016/06/01 10:42:04 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	texture_suite(t_double *deux, t_object *object)
{
	deux->tmp = deux->y / object->texture->height;
	deux->div = floor(deux->y / object->texture->height);
	deux->y = (deux->tmp - deux->div) * object->texture->height;
	deux->tmp = deux->x / object->texture->width;
	deux->div = floor(deux->tmp);
	deux->x = (deux->tmp - deux->div) * object->texture->height;
}

void	clean_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			if (tab[i])
			{
				free(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		if (tab)
		{
			free(tab);
			tab = NULL;
		}
	}
}
