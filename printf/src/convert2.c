/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:30:51 by hcherchi          #+#    #+#             */
/*   Updated: 2017/02/15 14:30:54 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*l_convert(t_format *f, va_list ap)
{
	char	*converted;

	converted = NULL;
	if (f->type == 'd' || f->type == 'i')
		converted = itoa_10(va_arg(ap, long int), f);
	else if (f->type == 'o')
		converted = uitoa_base(va_arg(ap, unsigned long int), 8, 0, f);
	else if (f->type == 'u')
		converted = uitoa_base(va_arg(ap, unsigned long int), 10, 0, f);
	else if (f->type == 'x')
		converted = uitoa_base(va_arg(ap, unsigned long int), 16, 0, f);
	else if (f->type == 'X')
		converted = uitoa_base(va_arg(ap, unsigned long int), 16, 1, f);
	else
		converted = ft_strdup("cas non gere");
	return (converted ? converted : ft_strdup("(null)"));
}

char	*ll_convert(t_format *f, va_list ap)
{
	char	*converted;

	if (f->type == 'd' || f->type == 'i')
		converted = itoa_10(va_arg(ap, long long int), f);
	else if (f->type == 'o')
		converted = uitoa_base(va_arg(ap, unsigned long long int), 8, 0, f);
	else if (f->type == 'u')
		converted = uitoa_base(va_arg(ap, unsigned long long int), 10, 0, f);
	else if (f->type == 'x')
		converted = uitoa_base(va_arg(ap, unsigned long long int), 16, 0, f);
	else if (f->type == 'X')
		converted = uitoa_base(va_arg(ap, unsigned long long int), 16, 1, f);
	else
		converted = ft_strdup("cas non gere");
	return (converted ? converted : ft_strdup("(null)"));
}

char	*j_convert(t_format *f, va_list ap)
{
	char	*converted;

	if (f->type == 'd' || f->type == 'i')
		converted = itoa_10(va_arg(ap, intmax_t), f);
	else if (f->type == 'o')
		converted = uitoa_base(va_arg(ap, uintmax_t), 8, 0, f);
	else if (f->type == 'u')
		converted = uitoa_base(va_arg(ap, uintmax_t), 10, 0, f);
	else if (f->type == 'x')
		converted = uitoa_base(va_arg(ap, uintmax_t), 16, 0, f);
	else if (f->type == 'X')
		converted = uitoa_base(va_arg(ap, uintmax_t), 16, 1, f);
	else
		converted = ft_strdup("cas non gere");
	return (converted ? converted : ft_strdup("(null)"));
}

char	*z_convert(t_format *f, va_list ap)
{
	char	*converted;

	if (f->type == 'd' || f->type == 'i')
		converted = itoa_10(va_arg(ap, ssize_t), f);
	else if (f->type == 'o')
		converted = uitoa_base(va_arg(ap, size_t), 8, 0, f);
	else if (f->type == 'u')
		converted = uitoa_base(va_arg(ap, size_t), 10, 0, f);
	else if (f->type == 'x')
		converted = uitoa_base(va_arg(ap, size_t), 16, 0, f);
	else if (f->type == 'X')
		converted = uitoa_base(va_arg(ap, size_t), 16, 1, f);
	else
		converted = ft_strdup("cas non gere");
	return (converted ? converted : ft_strdup("(null)"));
}
