/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 11:12:35 by bgantelm          #+#    #+#             */
/*   Updated: 2016/03/21 12:00:45 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Rtv1.h>

void	ft_error(int i)
{
	if (i == 1)
		ft_putstr("Error, bad argument in camera. use just pos and res.\n");
	else if (i == 2)
		ft_putstr("Error, arguments need numbers.\n");
	else if (i == 3)
	{
		ft_putstr("Error, bad argument in light. ");
		ft_putstr("use just pos color and dist.\n");
	}
	else if (i == 4)
	{
		ft_putstr("Error, bad argument in object, ");
		ft_putstr("use just type, pos, dir, rayon, color, h et shiny.\n");
	}
	else if (i == 5)
		ft_putstr("Error, bad type of object.\n");
	else if (i == 6)
		ft_putstr("Error, you need one and only one camera.\n");
	else if (i == 7)
		ft_putstr("Error, bad numbers of argument.\n");
	else if (i == 8)
		ft_putstr("Error, window can not be negative.\n");
	exit(0);
}
