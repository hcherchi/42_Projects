/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:24:41 by exam              #+#    #+#             */
/*   Updated: 2016/01/04 11:22:16 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		g_base[] = "0123456789ABCDEF";

static int		get_length(long long int value, int base)
{
	int count;

	count = 0;
	if (value == 0)
		count = 1;
	else if (value < 0 && base == 10)
		count = 1;
	while (value)
	{
		value /= base;
		count++;
	}
	return (count);
}

static char		*ft_stralloc(int length)
{
	int		size;
	char	*ptr;

	size = length + 1;
	ptr = (char*)malloc(sizeof(char) * size);
	if (ptr)
	{
		while (size >= 0)
		{
			ptr[size] = '\0';
			size--;
		}
	}
	return (ptr);
}

char			*ft_itoa_base(long long int value, int base)
{
	char	*str;
	int		size;
	int		result;

	if (base < 2 || base > 16)
		value = 0;
	size = get_length(value, base);
	str = ft_stralloc(size);
	if (value == 0)
		str[0] = '0';
	else if (value < 0 && base == 10)
		str[0] = '-';
	while (value)
	{
		result = (value % base);
		result = (result < 0) ? -result : result;
		str[size - 1] = g_base[result];
		value /= base;
		size--;
	}
	return (str);
}
