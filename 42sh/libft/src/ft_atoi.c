/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:18:23 by jhoudan           #+#    #+#             */
/*   Updated: 2015/11/23 17:35:14 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int sign;
	int n;

	n = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (ft_strncmp(str, "-2147483648", 11) == 0)
			return (-2147483648);
		sign = (*str == '-') ? -1 : 1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			break ;
		n *= 10;
		n += *str - '0';
		str++;
	}
	return (n * sign);
}
