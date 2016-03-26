/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller_di.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 19:45:08 by jhoudan           #+#    #+#             */
/*   Updated: 2015/12/13 22:17:36 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_field(t_printf *ptr, char *number, long long int nbr)
{
	int size;
	int length;
	int to_print;

	size = 0;
	length = ft_strlen(number);
	if (ptr->is_zero && ptr->is_minus == 0 &&
			ptr->is_preci != 0 && ptr->nbr_field == 0)
		ptr->nbr_field = ptr->nbr_zero;
	if (ptr->is_zero && ptr->is_minus == 0 && ptr->is_preci == 0)
		size = ptr->nbr_zero;
	else if (ptr->is_preci && ptr->nbr_preci)
		size = ptr->nbr_preci;
	to_print = (size > length) ? size : length;
	if (ptr->is_plus && number[0] != '-')
		to_print++;
	if (ptr->is_space && number[0] != '-')
		to_print++;
	if (number[0] == '-' && (int)ptr->nbr_preci + 1 > length)
		to_print++;
	if (nbr == 0 && ptr->is_preci && ptr->nbr_preci == 0)
		to_print--;
	while (ptr->nbr_field >= ++to_print)
		ptr->print += ft_putchar(' ');
}

static void	print_flag(t_printf *ptr, char *number)
{
	int size;
	int length;

	size = 0;
	length = ft_strlen(number);
	if (number[0] == '-')
	{
		if (ptr->nbr_preci)
			ptr->nbr_preci++;
		ptr->print += ft_putchar('-');
	}
	else if (ptr->is_plus)
		ptr->print += ft_putchar('+');
	if (ptr->is_zero && ptr->is_minus == 0 && ptr->is_preci == 0)
		size = (ptr->is_space) ? ptr->nbr_zero - 1 : ptr->nbr_zero;
	else if (ptr->is_preci && ptr->nbr_preci)
		size = ptr->nbr_preci;
	if (ptr->is_plus && number[0] != '-' && !ptr->is_preci)
		size--;
	while (size > length)
	{
		ptr->print += ft_putchar('0');
		size--;
	}
}

static int	print_di(long long int nbr, t_printf *ptr)
{
	int		length;
	int		total_length;
	char	*number;

	length = 0;
	if (!ptr->is_plus && ptr->is_space && nbr >= 0)
		length += ft_putchar(' ');
	ptr->print += length;
	if ((number = ft_itoa_base(nbr, 10)) == NULL)
	{
		ptr->print = -1;
		return (-1);
	}
	length += ft_strlen(number);
	print_field(ptr, number, nbr);
	print_flag(ptr, number);
	if (number[0] == '-')
		ptr->print += ft_putstr(number + 1);
	else if (!(ptr->is_preci && ptr->nbr_preci == 0 && nbr == 0))
		ptr->print += ft_putstr(number);
	total_length = ptr->print;
	ptf_pad_after(ptr, total_length);
	ft_strdel(&number);
	return (length);
}

void		ptf_controller_di(t_printf *ptr, va_list ap)
{
	if (ptr->modifier == NULL && ptr->conversion != 'D')
		print_di((int)va_arg(ap, int), ptr);
	else if (ptr->conversion == 'D' || ft_strcmp(ptr->modifier, "l") == 0)
		print_di(va_arg(ap, long int), ptr);
	else if (ft_strcmp(ptr->modifier, "ll") == 0)
		print_di(va_arg(ap, long long int), ptr);
	else if (ft_strcmp(ptr->modifier, "h") == 0)
		print_di((short)va_arg(ap, int), ptr);
	else if (ft_strcmp(ptr->modifier, "hh") == 0)
		print_di((char)va_arg(ap, int), ptr);
	else if (ft_strcmp(ptr->modifier, "j") == 0)
		print_di(va_arg(ap, long), ptr);
	else if (ft_strcmp(ptr->modifier, "z") == 0)
		print_di(va_arg(ap, size_t), ptr);
}
