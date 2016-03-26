/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_ws.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 10:51:24 by jhoudan           #+#    #+#             */
/*   Updated: 2015/12/13 22:18:37 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calcul_preci_wsize(t_printf *ptr, wchar_t *str)
{
	int i;
	int length;

	length = 0;
	i = 0;
	while (str[i])
	{
		if (length + count_nb_octet(str[i]) > (int)ptr->nbr_preci)
			return (length);
		else
			length += count_nb_octet(str[i]);
		i++;
	}
	return (length);
}

static void	print_field_ws(t_printf *ptr, wchar_t *str)
{
	int	size;
	int	length;
	int	to_print;

	size = 0;
	length = strlen_wchar(str);
	if (ptr->is_zero)
		size = ptr->nbr_zero;
	if (ptr->is_preci)
		length = calcul_preci_wsize(ptr, str);
	to_print = (size > length) ? size : length;
	if (ptr->is_plus)
		to_print++;
	while (ptr->nbr_field > to_print)
	{
		ptr->print += ft_putchar(' ');
		ptr->nbr_field--;
	}
}

static void	print_flag_ws(t_printf *ptr, wchar_t *str)
{
	int size;
	int	length;

	size = 0;
	length = strlen_wchar(str);
	if (ptr->is_zero)
		size = ptr->nbr_zero;
	if (ptr->is_preci && ptr->nbr_preci < length)
		length = ptr->nbr_preci;
	while (size > length)
	{
		ptr->print += ft_putchar('0');
		size--;
	}
}

void		ptf_printfwstr(t_printf *ptr, wchar_t *str)
{
	unsigned int	i;
	int				length;

	i = -1;
	length = 0;
	if (str == NULL)
		return (void)(ptr->print += ft_putstr("(null)"));
	print_field_ws(ptr, str);
	print_flag_ws(ptr, str);
	if (ptr->is_preci == 0)
		while (str[++i])
			ptr->print += ft_putwchar(str[i]);
	else
	{
		while (str[++i])
		{
			length += count_nb_octet(str[i]);
			if (length > ptr->nbr_preci)
				return ;
			ptr->print += ft_putwchar(str[i]);
		}
	}
	ptf_pad_after(ptr, ptr->print);
}
