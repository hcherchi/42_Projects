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
    return (ft_strdup(""));
  if (format->flag == '\0' || (format->flag != 'l' && (format->type == 's' || format->type == 'c')))
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
}

char *convert(t_format *format, va_list ap)
{
  char *converted_arg;

  if (format->type == 's')
    converted_arg = va_arg(ap, char*);
  else if (format->type == 'c')
    converted_arg = ft_ctoa((unsigned char)va_arg(ap, int));
  else if (format->type == 'd' || format->type == 'i')
    converted_arg = ft_sstoa_base((ssize_t)va_arg(ap, int), 10);
  else if (format->type == 'o')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned int), 8, 0);
  else if (format->type == 'u')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned int), 10, 0);
  else if (format->type == 'x')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned int), 16, 0);
  else if (format->type == 'X')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned int), 16, 1);
  return (converted_arg);
}

char *hh_convert(t_format *format, va_list ap)
{
  char *converted_arg;

  if (format->type == 'd' || format->type == 'i')
    converted_arg = ft_sstoa_base((ssize_t)va_arg(ap, char), 10);
  else if (format->type == 'o')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned char), 8, 0);
  else if (format->type == 'u')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned char), 10, 0);
  else if (format->type == 'x')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned char), 16, 0);
  else if (format->type == 'X')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned char), 16, 1);
  return (converted_arg);
}

char *h_convert(t_format *format, va_list ap)
{
  char *converted_arg;

  if (format->type == 'd' || format->type == 'i')
    converted_arg = ft_sstoa_base((ssize_t)va_arg(ap, short int), 10);
  else if (format->type == 'o')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned short int), 8, 0);
  else if (format->type == 'u')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned short int), 10, 0);
  else if (format->type == 'x')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned short int), 16, 0);
  else if (format->type == 'X')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned short int), 16, 1);
  return (converted_arg);
}

char *l_convert(t_format *format, va_list ap)
{
  char *converted_arg;

  else if (format->type == 'd' || format->type == 'i')
    converted_arg = ft_sstoa_base((ssize_t)va_arg(ap, long int), 10);
  else if (format->type == 'o')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned long int), 8, 0);
  else if (format->type == 'u')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned long int), 10, 0);
  else if (format->type == 'x')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned long int), 16, 0);
  else if (format->type == 'X')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned long int), 16, 1);
  return (converted_arg);
}

char *ll_convert(t_format *format, va_list ap)
{
  char *converted_arg;

  if (format->type == 'd' || format->type == 'i')
    converted_arg = ft_sstoa_base((ssize_t)va_arg(ap, long long int), 10);
  else if (format->type == 'o')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned long long int), 8, 0);
  else if (format->type == 'u')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned long long int), 10, 0);
  else if (format->type == 'x')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned long long int), 16, 0);
  else if (format->type == 'X')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, unsigned long long int), 16, 1);
  return (converted_arg);
}

char *j_convert(t_format *format, va_list ap)
{
  else if (format->type == 'd' || format->type == 'i')
    converted_arg = ft_sstoa_base((ssize_t)va_arg(ap, intmax_t), 10);
  else if (format->type == 'o')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, uintmax_t), 8, 0);
  else if (format->type == 'u')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, uintmax_t), 10, 0);
  else if (format->type == 'x')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, uintmax_t), 16, 0);
  else if (format->type == 'X')
    converted_arg = ft_stoa_base((size_t)va_arg(ap, uintmax_t), 16, 1);
  return (converted_arg);
}

char *z_convert(t_format *format, va_list ap)
{
  else if (format->type == 'd' || format->type == 'i')
    converted_arg = ft_sstoa_base(va_arg(ap, ssize_t), 10);
  else if (format->type == 'o')
    converted_arg = ft_stoa_base(va_arg(ap, size_t), 8, 0);
  else if (format->type == 'u')
    converted_arg = ft_stoa_base(va_arg(ap, size_t), 10, 0);
  else if (format->type == 'x')
    converted_arg = ft_stoa_base(va_arg(ap, size_t), 16, 0);
  else if (format->type == 'X')
    converted_arg = ft_stoa_base(va_arg(ap, size_t), 16, 1);
  return (converted_arg);
}
