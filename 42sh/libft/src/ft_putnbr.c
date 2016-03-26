/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:06:59 by jhoudan           #+#    #+#             */
/*   Updated: 2015/11/23 12:08:31 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print_number(int n)
{
	if (n <= 0)
		return ;
	ft_print_number(n / 10);
	ft_putchar(n % 10 + '0');
}

void		ft_putnbr(int n)
{
	if (n == 0)
		ft_putchar('0');
	else if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	ft_print_number(n);
}
