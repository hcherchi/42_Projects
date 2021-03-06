/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:31:15 by hcherchi          #+#    #+#             */
/*   Updated: 2017/02/15 14:47:31 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*itoa_10(ssize_t nb, t_format *format)
{
	size_t	unb;
	char	sign;
	int		len;
	char	*value;

	if (nb == 0 && format->accur == 0)
		return (ft_strdup(""));
	sign = get_sign(nb, format);
	unb = (nb < 0) ? -1 * nb : nb;
	len = get_len(unb, 10, ((sign) ? 1 : 0), format) + ((sign) ? 1 : 0);
	value = (char *)malloc(sizeof(*value) * len + 1);
	value[len] = '\0';
	len--;
	while (unb != 0)
	{
		value[len] = unb % 10 + '0';
		unb /= 10;
		len--;
	}
	while (len >= 0)
	{
		value[len] = (sign != 0 && len == 0) ? sign : '0';
		len--;
	}
	return (value);
}

char	*uitoa_base(size_t unb, int base, int maj, t_format *format)
{
	int		len;
	char	*value;
	int		prefix;

	if (unb == 0 && format->accur == 0
		&& format->type != 'o' && format->type != 'p')
		return (ft_strdup(""));
	prefix = get_prefix(unb, format);
	len = get_len(unb, base, prefix, format) + prefix;
	value = (char *)malloc(sizeof(*value) * len + 1);
	value[len] = '\0';
	len--;
	while (unb != 0)
	{
		if (unb % base <= 9)
			value[len] = unb % base + '0';
		else
			value[len] = (maj) ? unb % base + 'A' - 10 : unb % base + 'a' - 10;
		unb /= base;
		len--;
	}
	put_prefix(value, len, prefix, maj);
	return (value);
}
