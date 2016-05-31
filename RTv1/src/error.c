/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:53:45 by vnguyen           #+#    #+#             */
/*   Updated: 2016/05/31 22:22:56 by vnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	ft_error_suite(int i, t_tool *tools)
{
	if (i == 6)
		ft_putstr("Error, you need one and only one camera.\n");
	else if (i == 7)
		ft_putstr("Error, bad numbers of argument.\n");
	else if (i == 8)
		ft_putstr("Error, window can not be negative.\n");
	else if (i == 9)
		ft_putstr("Error parser object.\n");
	else if (i == 10)
		ft_putstr("Invalid File.\n");
	else if (i == 11)
		ft_putendl("Invalid texture");
	else if (i == 12)
		ft_putendl("Error, bad type of object.\n");
	else if (i == 13)
		ft_putendl("Error, Resolution can't be superior at 2000*1300\n");
	else if (i == 14)
		ft_putendl("Error, Number must be between 0 and 1\n");
	else if (i == 15)
		ft_putendl("Error, Mirror and reflect
				additionates cant be superior at 1 \n");
	tools->error = 1;
}

void	ft_error(int i, t_tool *tools)
{
	if (i == 1)
		ft_putstr("Error, bad argument in camera. use just
				pos, res, vect, lumamb and skybox.\n");
	else if (i == 2)
		ft_putstr("Error, arguments need numbers.\n");
	else if (i == 3)
	{
		ft_putstr("Error, bad argument in light. ");
		ft_putstr("use just pos color, h, type, lumdiff.\n");
	}
	else if (i == 4)
	{
		ft_putstr("Error, bad argument in object, ");
		ft_putstr("use just type, pos, dir, rayon, color,
				h, shiny, mirror, refract, texture.\n");
	}
	else if (i == 5)
		ft_putstr("Error, bad type of object.\n");
	ft_error_suite(i, tools);
}
