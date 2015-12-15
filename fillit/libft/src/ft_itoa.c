/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:47:10 by bgantelm          #+#    #+#             */
/*   Updated: 2015/11/30 12:22:37 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_neg(int n)
{
	int	neg;

	neg = 0;
	if (n < 0)
		neg = 1;
	else
		neg = 0;
	return (neg);
}

static	int		ft_lennbr(int n)
{
	int	count;
	int	nb;

	count = 0;
	if (n < 0)
	{
		nb = -n;
		count++;
	}
	else
		nb = n;
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static	char	*ft_itoa2(int n, char *res, int len, int neg)
{
	while (neg == 0 && n > 0)
	{
		res[len] = (n % 10) + '0';
		n = (n / 10);
		len--;
	}
	if (neg == 1)
	{
		n = -n;
		while (neg == 1 && n > 0)
		{
			res[len] = (n % 10) + '0';
			n = (n / 10);
			len--;
		}
		res[len] = '-';
	}
	return (res);
}

char			*ft_itoa(int n)
{
	int		neg;
	char	*res;
	int		len;

	len = ft_lennbr(n);
	neg = ft_neg(n);
	res = NULL;
	res = (char *)malloc(sizeof(char) * (len + neg + 1));
	if (n <= -2147483648)
	{
		res = ft_strcpy(res, "-2147483648");
		return (res);
	}
	res[len] = '\0';
	len--;
	if (n == 0)
		res[0] = 0 + '0';
	ft_itoa2(n, res, len, neg);
	return (res);
}
