/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_padding_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 15:11:22 by jhoudan           #+#    #+#             */
/*   Updated: 2015/12/13 22:18:33 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	handle_sign(t_printf *ptr, double nbr, int *check)
{
	union u_double tut;

	tut.d = nbr;
	if (nbr < 0)
	{
		tut.parts.sign = 0;
		ptr->print += ft_putchar('-');
		*check = 1;
	}
	return (tut.d);
}

void			ptf_print_field_f(t_printf *ptr, double nbr)
{
	int length;

	length = 1;
	if (nbr < 0 || ptr->is_space || ptr->is_plus)
		length++;
	while ((long)nbr != 0)
	{
		nbr /= 10;
		length++;
	}
	if (ptr->is_preci == 0)
		length += 6;
	else
		length += ptr->nbr_preci;
	while (ptr->nbr_field > length)
	{
		ptr->nbr_field--;
		ptr->print += ft_putchar(' ');
	}
}

double			ptf_print_flag_f(t_printf *ptr, double nbr)
{
	int		length;
	double	tmp;

	length = 0;
	nbr = handle_sign(ptr, nbr, &length);
	if (length != 1 && ptr->is_plus)
		ptr->print += ft_putchar('+');
	else if (length != 1 && ptr->is_space)
		ptr->print += ft_putchar(' ');
	tmp = nbr;
	while ((long)tmp != 0)
	{
		tmp /= 10;
		length++;
	}
	if (ptr->is_preci == 0)
		length += 6;
	else
		length += ptr->nbr_preci;
	while (ptr->nbr_zero > (size_t)length)
	{
		ptr->nbr_zero--;
		ptr->print += ft_putchar('0');
	}
	return (nbr);
}
