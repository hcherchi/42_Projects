/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_process_conversion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:48:15 by jhoudan           #+#    #+#             */
/*   Updated: 2015/12/13 22:18:48 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_printf	*init_struct(int *count)
{
	t_printf	*ptr;

	ptr = (t_printf*)malloc(sizeof(t_printf));
	if (ptr != NULL)
	{
		ptr->is_zero = 0;
		ptr->nbr_zero = 0;
		ptr->is_minus = 0;
		ptr->nbr_minus = 0;
		ptr->is_plus = 0;
		ptr->is_space = 0;
		ptr->nbr_space = 0;
		ptr->is_hash = 0;
		ptr->is_preci = 0;
		ptr->nbr_preci = 0;
		ptr->is_field = 0;
		ptr->nbr_field = 0;
		ptr->modifier = NULL;
		ptr->conversion = 0;
		ptr->instr = NULL;
		ptr->print = 0;
		ptr->count = count;
	}
	return (ptr);
}

static void		destroy_struct(t_printf *ptr)
{
	if (ptr != NULL)
	{
		if (ptr->modifier != NULL)
			free(ptr->modifier);
		if (ptr->instr != NULL)
			free(ptr->instr);
		free(ptr);
	}
}

static int		advance_flag(char *inst)
{
	int i;

	i = 1;
	if (i == '-' || i == '0')
	{
		while (inst[i] && ft_isdigit(inst[i]))
			i++;
		return (i);
	}
	return (1);
}

static int		get_size(char *inst)
{
	int i;

	i = 0;
	while (inst[i] && ptf_is_flag(inst + i))
		i += advance_flag(inst + i);
	while (inst[i] && ft_isdigit(inst[i]))
		i++;
	if (inst[i] == '*')
		i++;
	while (inst[i] && ft_isdigit(inst[i]))
		i++;
	i += ptf_is_preci(inst + i);
	i += ptf_is_modifier(inst + i);
	while (inst[i] && ptf_is_modifier(inst + i))
		i++;
	while (inst[i] && !ft_isalpha(inst[i]) && inst[i] != '%' && inst[i] != '}')
		i++;
	return (i + 1);
}

int				ptf_process_conversion(char *str, va_list ap, int *count)
{
	t_printf	*ptr;
	int			forward;
	int			size;

	if (ap)
		size = 0;
	if ((ptr = init_struct(count)) == NULL)
		return (*count = -1);
	if (*str == '%')
	{
		*count += ft_putchar('%');
		return (1);
	}
	size = get_size(str);
	ptr->instr = ft_strsub(str, 0, size);
	ptr->conversion = ptr->instr[size - 1];
	if (ptr->conversion == 'n')
		ptf_controller_n(ptr, ap, *count);
	else
		ptf_process_instruction(ptr, ap);
	forward = ft_strlen(ptr->instr);
	*count += ptr->print;
	destroy_struct(ptr);
	return (forward);
}
