/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:44:20 by hcherchi          #+#    #+#             */
/*   Updated: 2017/01/03 16:44:22 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void  print_struct(t_format *format)
{
  printf("flag: %c\nConvertor: %c\nWidth: %d\nAccuracy: %d\nAttributs: \n", format->flag, format->type, format->width, format->accur);
  if (format->hash != 0)
    ft_putendl("#");
  if (format->zero != 0)
    ft_putendl("0");
  if (format->plus != 0)
    ft_putendl("+");
  if (format->minus != 0)
    ft_putendl("-");
  if (format->space != 0)
    ft_putendl("sp");
}

int   is_attribut(char c)
{
  if (ft_strchr("# 0-+", c))
    return (1);
  return (0);
}

t_format *init_format(void)
{
  t_format *format;

  format = malloc(sizeof(t_format));
  format->hash = 0;
  format->zero = 0;
  format->plus = 0;
  format->minus = 0;
  format->space = 0;
  format->flag = '\0';
  format->type = '\0';
  format->attribut = '\0';
  format->accur = -1;
  format->width = -1;
  return (format);
}

int   is_convertor(char c)
{
  if (ft_strchr("sSpdDioOuUxXcC", c))
    return (1);
  return (0);
}

char *choose_convertion(t_format *format, va_list ap)
{
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
    converted_arg = ft_lltoa_base((long long int)va_arg(ap, int), 10);
  else if (format->type == 'o')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned int), 8, 0);
  else if (format->type == 'u')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned int), 10, 0);
  else if (format->type == 'x')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned int), 16, 0);
  else if (format->type == 'X')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned int), 16, 1);
  return (converted_arg);
}

char *hh_convert(t_format *format, va_list ap)
{
  char *converted_arg;

  if (format->type == 'd' || format->type == 'i')
    converted_arg = ft_lltoa_base((long long int)va_arg(ap, char), 10);
  else if (format->type == 'o')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned char), 8, 0);
  else if (format->type == 'u')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned char), 10, 0);
  else if (format->type == 'x')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned char), 16, 0);
  else if (format->type == 'X')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned char), 16, 1);
  return (converted_arg);
}

char *h_convert(t_format *format, va_list ap)
{
  char *converted_arg;

  if (format->type == 'd' || format->type == 'i')
    converted_arg = ft_lltoa_base((long long int)va_arg(ap, short int), 10);
  else if (format->type == 'o')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned short int), 8, 0);
  else if (format->type == 'u')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned short int), 10, 0);
  else if (format->type == 'x')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned short int), 16, 0);
  else if (format->type == 'X')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned short int), 16, 1);
  return (converted_arg);
}

char *l_convert(t_format *format, va_list ap)
{
  char *converted_arg;

  if (format->type == 'c')
    converted_arg = ft_ctoa((unsigned char)va_arg(ap, wint_t));
  else if (format->type == 'd' || format->type == 'i')
    converted_arg = ft_lltoa_base((long long int)va_arg(ap, long int), 10);
  else if (format->type == 'o')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned long int), 8, 0);
  else if (format->type == 'u')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned long int), 10, 0);
  else if (format->type == 'x')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned long int), 16, 0);
  else if (format->type == 'X')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned long int), 16, 1);
  return (converted_arg);
}

char *ll_convert(t_format *format, va_list ap)
{
  char *converted_arg;

  if (format->type == 'd' || format->type == 'i')
    converted_arg = ft_lltoa_base((long long int)va_arg(ap, short int), 10);
  else if (format->type == 'o')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned long long int), 8, 0);
  else if (format->type == 'u')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned long long int), 10, 0);
  else if (format->type == 'x')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned long long int), 16, 0);
  else if (format->type == 'X')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned long long int), 16, 1);
  return (converted_arg);
}

char *j_convert(t_format *format, va_list ap)
{
  else if (format->type == 'd' || format->type == 'i')
    converted_arg = ft_lltoa_base((long long int)va_arg(ap, int), 10);
  else if (format->type == 'o')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned int), 8, 0);
  else if (format->type == 'u')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned int), 10, 0);
  else if (format->type == 'x')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned int), 16, 0);
  else if (format->type == 'X')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned int), 16, 1);
  return (converted_arg);
}

char *z_convert(t_format *format, va_list ap)
{
  else if (format->type == 'd' || format->type == 'i')
    converted_arg = ft_lltoa_base((long long int)va_arg(ap, int), 10);
  else if (format->type == 'o')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned int), 8, 0);
  else if (format->type == 'u')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned int), 10, 0);
  else if (format->type == 'x')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned int), 16, 0);
  else if (format->type == 'X')
    converted_arg = ft_ulltoa_base((unsigned long long int)va_arg(ap, unsigned int), 16, 1);
  return (converted_arg);
}

int  fill_format(const char *input, t_format *format)
{
    if (is_convertor(*input))
    {
      format->type = *input;
    }
    return (1);
}

int   handle_convertion(const char *input, va_list ap, int *count)
{
  t_format *format;
  char *to_print;
  int pass;

  if (*input == '%')
  {
    ft_putchar('%');
    *count += 2;
    return (2);
  }

  format = init_format();
  pass = fill_format(input, format);

  print_struct(format);

  to_print = convert_arg(format, ap);
  ft_putstr(to_print);
  *count += ft_strlen(to_print) + 1;
  return (pass + 1);
}
