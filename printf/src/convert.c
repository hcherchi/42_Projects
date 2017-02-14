/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:16:39 by hcherchi          #+#    #+#             */
/*   Updated: 2017/01/12 10:16:42 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *choose_convertion(t_format *format, va_list ap)
{
  if (format->type == '%')
    return (ft_strdup("%"));
  if (!format->type)
    return (ft_strdup(""));
  if (format->type == 'p')
    return (uitoa_base((size_t)va_arg(ap, void *), 16, 0, format));
  if (format->flag == '\0'
    || (format->flag != 'l' && (format->type == 's' || format->type == 'c')))
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

char *convert(t_format *format, va_list ap)
{
  char *converted_arg;

  if (format->type == 's')
    converted_arg = ft_strdup(va_arg(ap, char*));
  else if (format->type == 'c')
    converted_arg = ft_strnew((unsigned char)va_arg(ap, int), 1);
  else if (format->type == 'd' || format->type == 'i')
    converted_arg = itoa_10(va_arg(ap, int), format);
  else if (format->type == 'o')
    converted_arg = uitoa_base(va_arg(ap, unsigned int), 8, 0, format);
  else if (format->type == 'u')
    converted_arg = uitoa_base(va_arg(ap, unsigned int), 10, 0, format);
  else if (format->type == 'x')
    converted_arg = uitoa_base(va_arg(ap, unsigned int), 16, 0, format);
  else if (format->type == 'X')
    converted_arg = uitoa_base(va_arg(ap, unsigned int), 16, 1, format);
  else
    converted_arg = ft_strdup("cas non gere");
  return (converted_arg ? converted_arg : ft_strdup("(null)"));
}

char *hh_convert(t_format *format, va_list ap)
{
  char *converted_arg;

  if (format->type == 'd' || format->type == 'i')
    converted_arg = itoa_10((char)va_arg(ap, int), format);
  else if (format->type == 'o')
    converted_arg = uitoa_base((unsigned char)va_arg(ap, int), 8, 0, format);
  else if (format->type == 'u')
    converted_arg = uitoa_base((unsigned char)va_arg(ap, int), 10, 0, format);
  else if (format->type == 'x')
    converted_arg = uitoa_base((unsigned char)va_arg(ap, int), 16, 0, format);
  else if (format->type == 'X')
    converted_arg = uitoa_base((unsigned char)va_arg(ap, int), 16, 1, format);
  else
    converted_arg = ft_strdup("cas non gere");
  return (converted_arg ? converted_arg : ft_strdup("(null)"));
}

char *h_convert(t_format *format, va_list ap)
{
  char *converted_arg;

  if (format->type == 'd' || format->type == 'i')
    converted_arg = itoa_10((short int)va_arg(ap, int), format);
  else if (format->type == 'o')
    converted_arg = uitoa_base((unsigned short int)va_arg(ap, int), 8, 0, format);
  else if (format->type == 'u')
    converted_arg = uitoa_base((unsigned short int)va_arg(ap, int), 10, 0, format);
  else if (format->type == 'x')
    converted_arg = uitoa_base((unsigned short int)va_arg(ap, int), 16, 0, format);
  else if (format->type == 'X')
    converted_arg = uitoa_base((unsigned short int)va_arg(ap, int), 16, 1, format);
  else
    converted_arg = ft_strdup("cas non gere");
  return (converted_arg ? converted_arg : ft_strdup("(null)"));
}
