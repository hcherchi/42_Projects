/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_hour_controller.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 19:52:54 by jhoudan           #+#    #+#             */
/*   Updated: 2015/12/13 22:18:16 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recu_print_time2(unsigned long int time, int index, t_printf *ptr)
{
	if (time == 0)
		return ;
	if (index == 1)
	{
		recu_print_time2(time / 7, 2, ptr);
		ptr->print += ft_printf("%02dD ", time % 7);
	}
	else if (index == 2)
	{
		recu_print_time2(time / 52, 3, ptr);
		ptr->print += ft_printf("%02dW-", time % 52);
	}
	else if (index == 3)
		ptr->print += ft_printf("%3dY-", time);
}

void		recu_print_time(unsigned long int time, int index, t_printf *ptr)
{
	if (index == 1)
	{
		recu_print_time(time / 60, 2, ptr);
		ptr->print += ft_printf("%02d", time % 60);
	}
	else if (index == 2)
	{
		recu_print_time(time / 60, 3, ptr);
		ptr->print += ft_printf("%02d:", time % 60);
	}
	else if (index == 3)
	{
		recu_print_time2(time / 24, 1, ptr);
		ptr->print += ft_printf("T%02d:", time % 24);
	}
}
