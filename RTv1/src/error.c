/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:53:45 by vnguyen           #+#    #+#             */
/*   Updated: 2016/05/31 22:45:53 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	ft_error(int i, t_tool *tools)
{
	if (i == 1)
	{
		ft_putstr("Error, bad argument in camera. ");
		ft_putendl("use just pos, res, vect, lumamb and skybox.");
	}
	if (i == 2)
		ft_putstr("Error, arguments need numbers.\n");
	if (i == 3)
	{
		ft_putstr("Error, bad argument in light. ");
		ft_putstr("use just pos color, h, type, lumdiff.\n");
	}
	if (i == 4)
	{
		ft_putstr("Error, bad argument in object, ");
		ft_putstr("use just type, pos, dir, rayon, color, h, ");
		ft_putendl("shiny, mirror, refract, texture.");
	}
	if (i == 5)
		ft_putstr("Error, bad type of object.\n");
	ft_error_suite(i, tools);
}

void	ft_error_suite(int i, t_tool *tools)
{
	if (i == 6)
		ft_putstr("Error, you need one and only one camera.\n");
	if (i == 7)
		ft_putstr("Error, bad numbers of argument.\n");
	if (i == 8)
		ft_putstr("Error, window can not be negative.\n");
	if (i == 9)
		ft_putstr("Error parser object.\n");
	if (i == 10)
		ft_putstr("Invalid File.\n");
	if (i == 11)
		ft_putendl("Invalid texture");
	if (i == 12)
		ft_putendl("Error, bad type of object.\n");
	if (i == 13)
		ft_putendl("Error, Resolution can't be superior at 2000 * 1300\n");
	if (i == 14)
		ft_putendl("Error, Number must be between 0 and 1\n");
	if (i == 15)
	{
		ft_putstr("Error, Mirror and reflect additionates ");
		ft_putendl("can't be beyond 1");
	}
	tools->error = 1;
}
