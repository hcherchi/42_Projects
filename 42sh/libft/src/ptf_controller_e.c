/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_controller_e.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 11:49:00 by jhoudan           #+#    #+#             */
/*   Updated: 2015/12/13 22:17:41 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		print_with_preci(t_printf *ptr, double nbr)
{
	if (ptr->nbr_preci == 1)
		ptr->print += ft_printf("%.1F", (float)nbr);
	else if (ptr->nbr_preci == 2)
		ptr->print += ft_printf("%.2F", (float)nbr);
	else if (ptr->nbr_preci == 3)
		ptr->print += ft_printf("%.3F", (float)nbr);
	else if (ptr->nbr_preci == 4)
		ptr->print += ft_printf("%.4F", (float)nbr);
	else if (ptr->nbr_preci == 5)
		ptr->print += ft_printf("%.5F", (float)nbr);
	else if (ptr->nbr_preci == 6)
		ptr->print += ft_printf("%.6F", (float)nbr);
	else if (ptr->nbr_preci == 7)
		ptr->print += ft_printf("%.7F", (float)nbr);
	else if (ptr->nbr_preci == 8)
		ptr->print += ft_printf("%.8F", (float)nbr);
	else if (ptr->nbr_preci == 9)
		ptr->print += ft_printf("%.9F", (float)nbr);
	else if (ptr->nbr_preci == 10)
		ptr->print += ft_printf("%.10F", (float)nbr);
	else if (ptr->nbr_preci == 11)
		ptr->print += ft_printf("%.11F", (float)nbr);
	else if (ptr->nbr_preci == 12)
		ptr->print += ft_printf("%.12F", (float)nbr);
}

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

static void		print_e(t_printf *ptr, double nbr)
{
	int plus;
	int check;

	check = 0;
	plus = 0;
	if (ptr->is_preci == 0)
		ptr->nbr_preci = 6;
	ptf_print_field_e(ptr, nbr);
	nbr = handle_sign(ptr, nbr, &check);
	ptf_print_flag_e(ptr, &check);
	while (nbr > 10)
	{
		nbr /= 10;
		plus++;
	}
	while (nbr < 1.0)
	{
		nbr *= 10;
		plus--;
	}
	print_with_preci(ptr, nbr);
	ptr->print += (ptr->conversion == 'e') ? ft_printf("e%+03d", plus)
		: ft_printf("E%+03d", plus);
	ptf_pad_after(ptr, ptr->print);
}

void			ptf_controller_e(t_printf *ptr, va_list ap)
{
	double tmp;

	tmp = va_arg(ap, double);
	if (tmp == 0.0)
	{
		if (ptr->is_preci == 0)
			ptr->nbr_preci = 6;
		ptf_print_field_e(ptr, tmp);
		ptf_print_flag_e(ptr, 0);
		ptr->print += ft_printf("0.");
		while (--ptr->nbr_preci >= 0)
			ptr->print += ft_putchar('0');
		ptr->print += (ptr->conversion == 'e') ? ft_printf("e+00")
			: ft_printf("E+00");
		ptf_pad_after(ptr, ptr->print);
	}
	else
		print_e(ptr, tmp);
}
