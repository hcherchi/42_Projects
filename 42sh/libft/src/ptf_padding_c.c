/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_padding_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 16:14:18 by jhoudan           #+#    #+#             */
/*   Updated: 2015/12/13 22:18:25 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ptf_print_field_c(t_printf *ptr)
{
	unsigned int	size;

	if (ptr->is_minus)
		return ;
	size = 1;
	if (ptr->is_zero)
		size += ptr->nbr_zero;
	while (ptr->nbr_field > (int)size)
	{
		ptr->print += ft_putchar(' ');
		ptr->nbr_field--;
	}
}

void	ptf_print_flag_c(t_printf *ptr)
{
	unsigned int size;

	size = 0;
	if (ptr->is_zero)
		size += ptr->nbr_zero;
	while (size > 1)
	{
		ptr->print += ft_putchar('0');
		size--;
	}
}
