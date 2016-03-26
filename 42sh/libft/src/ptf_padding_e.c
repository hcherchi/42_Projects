/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_padding_e.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 14:14:13 by jhoudan           #+#    #+#             */
/*   Updated: 2015/12/13 22:18:29 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ptf_print_field_e(t_printf *ptr, double nbr)
{
	int length;

	if (ptr->is_field == 0)
		return ;
	length = ptr->print;
	if (nbr < 0 || ptr->is_space || ptr->is_plus)
		length++;
	length += 6 + ptr->nbr_preci;
	while (ptr->nbr_field > length)
	{
		ptr->print += ft_putchar(' ');
		ptr->nbr_field--;
	}
}

void	ptf_print_flag_e(t_printf *ptr, int *check)
{
	int length;

	if (ptr->is_plus && ptr->print == 0)
		ptr->print += ft_putchar('+');
	else if (ptr->is_space && check == 0)
		ptr->print += ft_putchar(' ');
	length = ptr->print + 6 + ptr->nbr_preci;
	while (ptr->nbr_zero > (size_t)length)
	{
		ptr->print += ft_putchar('0');
		ptr->nbr_zero--;
	}
}
