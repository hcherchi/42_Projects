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

int		get_len(size_t unb, int base, int prefix, t_format *format)
{
	int	c;
	int	len;

	c = 0;
	if (unb == 0)
		c = (format->accur == 0) ? 0 : 1;
	while (unb != 0)
	{
		unb /= base;
		c++;
	}
	if (format->zero && format->width > format->accur && format->width > c)
		len = format->width - prefix;
	else if (format->accur > c)
		len = format->accur;
	else
		len = c;
	return (len);
}

char	get_sign(ssize_t nb, t_format *format)
{
	if (nb >= 0)
	{
		if (format->space)
			return (' ');
		else if (format->plus)
			return ('+');
	}
	else
		return ('-');
	return (0);
}

int		get_prefix(size_t unb, t_format *format)
{
	int	prefix;

	prefix = 0;
	if (format->hash)
	{
		if (((format->type == 'x' || format->type == 'X') && unb != 0)
			|| format->type == 'p')
			prefix = 2;
		else if (format->type == 'o'
			&& ((unb == 0 && format->accur == 0) || unb != 0))
			prefix = 1;
	}
	return (prefix);
}

void	put_prefix(char *value, int len, int prefix, int maj)
{
	while (len >= 0)
	{
		if (len == 1 && prefix == 2)
		{
			value[len] = (maj) ? 'X' : 'x';
			prefix--;
		}
		else
			value[len] = '0';
		len--;
	}
}
