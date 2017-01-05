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

int   is_attribut(char c)
{
  if (ft_strchr("# 0-+", c))
    return (1);
  return (0);
}

int   is_convertor(char c)
{
  if (ft_strchr("sSpdDioOuUxXcC", c))
    return (1);
  return (0);
}

char *convert_arg(t_format *format, va_list ap)
{
  char *converted_arg;

  if (format->type == 's')
    converted_arg = va_arg(ap, char*);
  else if (format->type == 'S')
    converted_arg = va_arg(ap, char*);

  else if (format->type == 'p')
    converted_arg = ft_itoa_base(va_arg(ap, int), 16);
  else if (format->type == 'd' || format->type == 'i')
    converted_arg = ft_itoa_base(va_arg(ap, int), 10);
  else if (format->type == 'D')
    converted_arg = ft_itoa_base(va_arg(ap, int), 10);

  else if (format->type == 'c')
    converted_arg = ft_ctoa((unsigned char)va_arg(ap, int));
  else if (format->type == 'C')
    converted_arg = ft_ctoa((unsigned char)va_arg(ap, int));

  else if (format->type == 'o')
    converted_arg = ft_uitoa_base(va_arg(ap, unsigned int), 8);
  else if (format->type == 'u')
    converted_arg = ft_uitoa_base(va_arg(ap, unsigned int), 10);
  else if (format->type == 'O')
    converted_arg = ft_uitoa_base(va_arg(ap, unsigned int), 8);
  else if (format->type == 'U')
    converted_arg = ft_uitoa_base(va_arg(ap, unsigned int), 10);
  else if (format->type == 'x' || format->type == 'X')
    converted_arg = ft_uitoa_base(va_arg(ap, unsigned int), 16);

  else
    converted_arg = "";

  return (converted_arg);
}

t_format *init_format()
{
  t_format *format;

  format = malloc(sizeof(t_format*));
  format->type = '\0';
  return (format);
}

int  fill_format(const char *input, t_format *format)
{
    if (is_attribut(*input))
    {
      format->attr = *input;
    }
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
  to_print = convert_arg(format, ap);
  ft_putstr(to_print);
  *count += ft_strlen(to_print) + 1;
  return (pass + 1);
}
