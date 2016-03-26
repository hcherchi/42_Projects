/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:44:04 by jhoudan           #+#    #+#             */
/*   Updated: 2016/01/04 11:22:03 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size_str(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	int		size;
	char	*ptr;
	int		i;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_size_str(n);
	if ((ptr = ft_strnew(size)) == NULL)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		ptr[0] = '-';
	}
	if (n == 0)
		ptr[0] = '0';
	while (n)
	{
		ptr[size - 1] = n % 10 + '0';
		n /= 10;
		size--;
	}
	return (ptr);
}
