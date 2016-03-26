/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_controller_xp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 14:55:20 by jhoudan           #+#    #+#             */
/*   Updated: 2015/12/13 22:18:01 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lower_str(char *instr)
{
	int i;

	i = 0;
	while (instr[i])
	{
		if (instr[i] >= 65 && instr[i] <= 90)
			instr[i] += 32;
		i++;
	}
}

static void	print_field_xp(t_printf *ptr, char *number, unsigned long long nbr)
{
	int size;
	int length;
	int to_print;

	size = 0;
	length = ft_strlen(number);
	if (ptr->conversion == 'p' ||
			(ptr->is_hash && ptr->conversion == 'x' && nbr != 0))
		length += 2;
	else if (ptr->is_hash && ptr->conversion == 'X' && nbr != 0)
		length += 2;
	if (ptr->is_zero && ptr->is_minus == 0 && ptr->is_preci == 0)
		size = ptr->nbr_zero;
	else if (ptr->is_preci && ptr->nbr_preci)
		size = ptr->nbr_preci;
	to_print = (size > length) ? size : length;
	if (ptr->is_plus)
		to_print++;
	if (nbr == 0 && ptr->is_preci && ptr->nbr_preci == 0)
		to_print -= 1;
	while (ptr->nbr_field > to_print)
	{
		ptr->print += ft_putchar(' ');
		ptr->nbr_field--;
	}
}

static void	print_flag_xp(t_printf *ptr, char *number, unsigned long long nbr)
{
	int size;
	int length;

	size = 0;
	length = ft_strlen(number);
	if (ptr->conversion == 'p' ||
			(ptr->is_hash && ptr->conversion == 'x' && nbr != 0))
		ptr->print += ft_putstr("0x");
	else if (ptr->is_hash && ptr->conversion == 'X' && nbr != 0)
		ptr->print += ft_putstr("0X");
	if (ptr->is_zero && ptr->is_minus == 0 && ptr->is_preci == 0)
	{
		size = ptr->nbr_zero;
		if ((ptr->is_hash && nbr != 0) || ptr->conversion == 'p')
			length += 2;
	}
	else if (ptr->is_preci && ptr->nbr_preci)
		size = ptr->nbr_preci;
	while (size > length)
	{
		ptr->print += ft_putchar('0');
		size--;
	}
}

static int	print_xp(unsigned long long int nbr, t_printf *ptr)
{
	int		length;
	char	*number;
	int		total_length;

	length = 0;
	if (ptr->conversion == 'p' ||
			(nbr != 0 && ptr->is_hash && ptr->conversion == 'x'))
		length += 2;
	else if (ptr->is_hash && ptr->conversion == 'X' && nbr != 0)
		length += 2;
	if ((number = ft_uitoa_base(nbr, 16)) == NULL)
		return ((int)(ptr->print = -1));
	length += ft_strlen(number);
	if (ptr->conversion == 'p' || ptr->conversion == 'x')
		ft_lower_str(number);
	print_field_xp(ptr, number, nbr);
	print_flag_xp(ptr, number, nbr);
	if (!(ptr->is_preci && ptr->nbr_preci == 0 && nbr == 0))
		ptr->print += ft_putstr(number);
	total_length = ptr->print;
	ptf_pad_after(ptr, total_length);
	ft_strdel(&number);
	return (length);
}

void		ptf_controller_xp(t_printf *ptr, va_list ap)
{
	if (ptr->modifier == NULL && ptr->conversion != 'p')
		print_xp(va_arg(ap, unsigned int), ptr);
	else if (ptr->conversion == 'p' || ft_strcmp(ptr->modifier, "l") == 0)
		print_xp(va_arg(ap, unsigned long int), ptr);
	else if (ft_strcmp(ptr->modifier, "ll") == 0)
		print_xp(va_arg(ap, unsigned long long int), ptr);
	else if (ft_strcmp(ptr->modifier, "h") == 0)
		print_xp((unsigned short)va_arg(ap, int), ptr);
	else if (ft_strcmp(ptr->modifier, "hh") == 0)
		print_xp((unsigned char)va_arg(ap, int), ptr);
	else if (ft_strcmp(ptr->modifier, "j") == 0)
		print_xp(va_arg(ap, uintmax_t), ptr);
	else if (ft_strcmp(ptr->modifier, "z") == 0)
		print_xp(va_arg(ap, size_t), ptr);
}
