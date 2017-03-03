/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:16:39 by hcherchi          #+#    #+#             */
/*   Updated: 2017/02/15 14:27:09 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*choose_convertion(t_format *format, va_list ap)
{
	if (format->type == '%')
		return (ft_strdup("%"));
	if (!format->type)
		return (ft_strdup(""));
	if (format->type == 'p')
		return (uitoa_base((size_t)va_arg(ap, void *), 16, 0, format));
	if (format->flag == '\0' || (format->type == 's' || format->type == 'c'))
		return (convert(format, ap));
	else if (format->flag == 'l')
		return (l_convert(format, ap));
	else if (format->flag == 'L')
		return (ll_convert(format, ap));
	else if (format->flag == 'h')
		return (h_convert(format, ap));
	else if (format->flag == 'H')
		return (hh_convert(format, ap));
	else if (format->flag == 'j')
		return (j_convert(format, ap));
	else if (format->flag == 'z')
		return (z_convert(format, ap));
	else
		return (ft_strdup("cas non gere"));
}

char	*convert(t_format *format, va_list ap)
{
	char	*converted;

	if (format->type == 's')
		converted = ft_strdup(va_arg(ap, char*));
	else if (format->type == 'c')
		converted = ft_strnew((unsigned char)va_arg(ap, int), 1);
	else if (format->type == 'd' || format->type == 'i')
		converted = itoa_10(va_arg(ap, int), format);
	else if (format->type == 'o')
		converted = uitoa_base(va_arg(ap, unsigned int), 8, 0, format);
	else if (format->type == 'u')
		converted = uitoa_base(va_arg(ap, unsigned int), 10, 0, format);
	else if (format->type == 'x')
		converted = uitoa_base(va_arg(ap, unsigned int), 16, 0, format);
	else if (format->type == 'X')
		converted = uitoa_base(va_arg(ap, unsigned int), 16, 1, format);
	else
		converted = ft_strdup("cas non gere");
	return (converted ? converted : ft_strdup("(null)"));
}

char	*hh_convert(t_format *format, va_list ap)
{
	char	*converted;

	if (format->type == 'd' || format->type == 'i')
		converted = itoa_10((char)va_arg(ap, int), format);
	else if (format->type == 'o')
		converted = uitoa_base((unsigned char)va_arg(ap, int), 8, 0, format);
	else if (format->type == 'u')
		converted = uitoa_base((unsigned char)va_arg(ap, int), 10, 0, format);
	else if (format->type == 'x')
		converted = uitoa_base((unsigned char)va_arg(ap, int), 16, 0, format);
	else if (format->type == 'X')
		converted = uitoa_base((unsigned char)va_arg(ap, int), 16, 1, format);
	else
		converted = ft_strdup("cas non gere");
	return (converted ? converted : ft_strdup("(null)"));
}

char	*h_convert(t_format *f, va_list ap)
{
	char	*converted;

	if (f->type == 'd' || f->type == 'i')
		converted = itoa_10((short int)va_arg(ap, int), f);
	else if (f->type == 'o')
		converted = uitoa_base((unsigned short int)va_arg(ap, int), 8, 0, f);
	else if (f->type == 'u')
		converted = uitoa_base((unsigned short int)va_arg(ap, int), 10, 0, f);
	else if (f->type == 'x')
		converted = uitoa_base((unsigned short int)va_arg(ap, int), 16, 0, f);
	else if (f->type == 'X')
		converted = uitoa_base((unsigned short int)va_arg(ap, int), 16, 1, f);
	else
		converted = ft_strdup("cas non gere");
	return (converted ? converted : ft_strdup("(null)"));
}
