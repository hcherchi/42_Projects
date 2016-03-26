/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_controller_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 21:04:20 by jhoudan           #+#    #+#             */
/*   Updated: 2015/12/13 22:17:46 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ptf_get_deci(double nbr)
{
	int		count;
	int		test;
	double	temp;

	count = 0;
	while (nbr - (long long int)nbr != 0)
	{
		count++;
		nbr *= 10;
	}
	test = 0;
	temp = nbr;
	while (test < 6)
	{
		temp *= 10;
		if ((long long int)temp % 10 != 0)
			count = test + 1;
		test++;
	}
	return (count);
}

static int		pow(int nbr, int exp)
{
	int tmp;

	if (exp == 0)
		return (1);
	tmp = nbr;
	while (--exp > 0)
		nbr *= tmp;
	return (nbr);
}

void			ptf_print_float(float nbr, t_printf *ptr)
{
	unsigned long long int	tmp;
	char					*str;
	int						position;
	int						i;

	i = -1;
	tmp = nbr * pow(10, ptf_get_deci(nbr));
	str = ft_itoa_base(tmp, 10);
	position = ft_strlen(str) - ptf_get_deci(nbr);
	if (ptr->is_preci == 0)
		ptr->nbr_preci = 6;
	while (str[++i] && i < position)
		ptr->print += ft_putchar(str[i]);
	ptr->print += ft_putchar('.');
	while (str[i] && ptr->nbr_preci)
	{
		ptr->print += ft_putchar(str[i]);
		ptr->nbr_preci--;
		i++;
	}
	while (ptr->nbr_preci)
	{
		ptr->print += ft_putchar('0');
		ptr->nbr_preci--;
	}
}

void			ptf_print_f(double nbr, t_printf *ptr)
{
	unsigned long int	tmp;
	char				*str;
	int					i;
	int					temp;

	i = 0;
	tmp = (long int)nbr;
	if ((str = ft_itoa_base(tmp, 10)) == NULL)
		return ((void)(ptr->print = -1));
	if (ptr->is_preci == 0)
		ptr->nbr_preci = 6;
	ptr->print += ft_putstr(str);
	if (ptr->nbr_preci != 0)
		ptr->print += ft_putchar('.');
	nbr = nbr - (long int)tmp;
	while (ptr->nbr_preci != 0)
	{
		nbr *= 10;
		temp = (int)nbr;
		temp = (temp < 0) ? -temp : temp;
		ptr->print += ft_printf("%d", temp);
		ptr->nbr_preci--;
		nbr = nbr - (long int)nbr;
	}
}

void			ptf_controller_f(t_printf *ptr, va_list ap)
{
	double			test;
	union u_double	tut;

	test = va_arg(ap, double);
	tut.d = test;
	ptf_print_field_f(ptr, test);
	test = ptf_print_flag_f(ptr, test);
	if ((test >= (float)test || test < 0) && tut.parts.exponent <= 1023)
		ptf_print_float((float)test, ptr);
	else
		ptf_print_f(test, ptr);
	ptf_pad_after(ptr, ptr->print);
}
