/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_lights.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:54:08 by vnguyen           #+#    #+#             */
/*   Updated: 2016/05/31 20:58:10 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	modif_all_lights(t_tool *k, double value)
{
	t_light	*ptr;

	ptr = k->rt->l_lights;
	if (k->rt->l_lights == NULL)
		return ;
	while (ptr != NULL)
	{
		ptr->lumdiff += value;
		ptr = ptr->next;
	}
}

void	modif_lumamb(t_tool *k, double value)
{
	k->rt->lumamb += value;
}
