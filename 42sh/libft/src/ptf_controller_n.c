/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_controller_n.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 17:15:20 by jhoudan           #+#    #+#             */
/*   Updated: 2015/12/13 22:17:50 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ptf_controller_n(t_printf *ptr, va_list ap, int count)
{
	int		*tab;
	long	*tab2;
	short	*tab3;

	if (ptr->modifier == NULL)
	{
		tab = va_arg(ap, int*);
		*tab = count;
	}
	else if (ptr->modifier[0] == 'l')
	{
		tab2 = va_arg(ap, long*);
		*tab2 = (long)count;
	}
	else if (ptr->modifier[0] == 'h')
	{
		tab3 = va_arg(ap, short*);
		*tab3 = (short)count;
	}
}
