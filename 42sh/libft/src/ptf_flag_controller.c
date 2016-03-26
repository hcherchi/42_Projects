/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:07:59 by jhoudan           #+#    #+#             */
/*   Updated: 2015/12/13 22:18:04 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_flag_minus(t_printf *ptr, int index)
{
	int i;

	i = 0;
	ptr->is_minus = 1;
	ptr->nbr_minus = ft_atoi(ptr->instr + index + 1);
	while (ptr->instr[index + i + 1] && ft_isdigit(ptr->instr[index + i + 1]))
		i++;
	return (i);
}

static int	get_flag_zero(t_printf *ptr, int index)
{
	int i;

	i = 0;
	ptr->is_zero = 1;
	ptr->nbr_zero = ft_atoi(ptr->instr + index + 1);
	while (ptr->instr[index + i + 1] &&
			ft_isdigit(ptr->instr[index + i + 1]))
		i++;
	return (i);
}

int			ptf_flag_control(t_printf *ptr, int i)
{
	if (ptr->instr[i] == '#')
		ptr->is_hash = 1;
	else if (ptr->instr[i] == '0')
		return (get_flag_zero(ptr, i));
	else if (ptr->instr[i] == '+')
		ptr->is_plus = 1;
	else if (ptr->instr[i] == '-')
		return (get_flag_minus(ptr, i));
	else if (ptr->instr[i] == ' ')
	{
		ptr->is_space = 1;
		return (0);
	}
	return (0);
}
