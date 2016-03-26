/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_controller_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:24:07 by jhoudan           #+#    #+#             */
/*   Updated: 2015/12/13 22:16:55 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_field_a(t_printf *ptr, int length, union u_double nbr)
{
	char *tmp;

	if (ptr->is_preci)
		length = (ptr->nbr_preci < length) ? ptr->nbr_preci : length;
	length += 4;
	if (nbr.parts.sign == 1)
		length += 1;
	tmp = ft_itoa_base(nbr.parts.exponent, 10);
	length += ft_strlen(tmp);
	ft_strdel(&tmp);
	while (ptr->nbr_field > length)
	{
		ptr->nbr_field--;
		ptr->print += ft_putchar(' ');
	}
}

static void	print_a(t_printf *ptr, char *str)
{
	int i;

	i = -1;
	if (ptr->conversion == 'a')
	{
		while (str[++i])
			if (str[i] >= 65 && str[i] <= 90)
				str[i] += 32;
	}
	if (ptr->is_preci == 0)
		ptr->print += ft_putstr(str);
	else
	{
		while (ptr->nbr_preci != 0 && *str)
		{
			ptr->print += ft_putchar(*str);
			ptr->nbr_preci--;
			str++;
		}
	}
}

void		ptf_controller_a(t_printf *ptr, va_list ap)
{
	union u_double	nbr;
	char			*tmp;

	nbr.d = va_arg(ap, double);
	if ((tmp = ft_uitoa_base(nbr.parts.mantisa, 16)) == NULL)
	{
		ptr->print = -1;
		return ;
	}
	print_field_a(ptr, ft_strlen(tmp), nbr);
	if (nbr.parts.sign == 1)
		ptr->print += ft_putchar('-');
	if (ptr->conversion == 'A')
		ptr->print += ft_putstr("0X1.");
	else
		ptr->print += ft_putstr("0x1.");
	print_a(ptr, tmp);
	ft_strdel(&tmp);
	if (ptr->conversion == 'A')
		ptr->print += ft_putchar('P');
	else
		ptr->print += ft_putchar('p');
	ptr->print += ft_printf("%+d", (int)nbr.parts.exponent - 1023);
	ptf_pad_after(ptr, ptr->print);
}
