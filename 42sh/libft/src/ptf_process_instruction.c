/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_process_instruction.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:47:23 by jhoudan           #+#    #+#             */
/*   Updated: 2015/12/13 22:18:53 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	controller_invalid(t_printf *ptr)
{
	ptf_print_field_c(ptr);
	ptf_print_flag_c(ptr);
	if (ptr->conversion != 0)
		ptr->print += ft_putchar(ptr->conversion);
	ptf_pad_after(ptr, 1);
}

static void	conversion_controller(t_printf *ptr, va_list ap)
{
	char ch;

	ch = ptr->conversion;
	if (ch == 'c' || ch == 'C' || ch == 's' || ch == 'S')
		ptf_controller_cs(ptr, ap);
	else if (ch == 'p' || ch == 'x' || ch == 'X')
		ptf_controller_xp(ptr, ap);
	else if (ch == 'd' || ch == 'D' || ch == 'i')
		ptf_controller_di(ptr, ap);
	else if (ch == 'o' || ch == 'O')
		ptf_controller_o(ptr, ap);
	else if (ch == 'u' || ch == 'U')
		ptf_controller_u(ptr, ap);
	else if (ch == 'b')
		ptf_controller_b(ptr, ap);
	else if (ch == 'k')
		recu_print_time(va_arg(ap, unsigned long long int), 1, ptr);
	else if (ch == 'f' || ch == 'F')
		ptf_controller_f(ptr, ap);
	else if (ch == 'a' || ch == 'A')
		ptf_controller_a(ptr, ap);
	else if (ch == 'e' || ch == 'E')
		ptf_controller_e(ptr, ap);
	else
		controller_invalid(ptr);
}

static int	is_preci_field(char ch)
{
	if (ch == '.' || ch == '*' || ft_isdigit(ch))
		return (1);
	return (0);
}

void		ptf_pad_after(t_printf *ptr, int length)
{
	int size;

	size = 0;
	if (ptr->is_minus)
		size = ptr->nbr_minus;
	while (size > length)
	{
		ptr->print += ft_putchar(' ');
		size--;
	}
}

void		ptf_process_instruction(t_printf *ptr, va_list ap)
{
	int		i;
	int		length;
	char	*temp;

	i = 0;
	while (ptr->instr[i])
	{
		if (ptf_is_flag(ptr->instr + i))
			i += ptf_flag_control(ptr, i);
		else if ((length = ptf_is_modifier(ptr->instr + i)))
		{
			temp = ft_strsub(ptr->instr, i, length);
			ptf_modifier_controller(ptr, temp);
			i += (length == 2) ? i + 1 : i;
		}
		else if (is_preci_field(ptr->instr[i]))
			i += ptf_preci_field_controller(ptr, i, ap);
		i++;
	}
	if (ptr->is_minus && ptr->is_field)
	{
		ptr->nbr_minus = ptr->nbr_field;
		ptr->nbr_field = 0;
	}
	conversion_controller(ptr, ap);
}
