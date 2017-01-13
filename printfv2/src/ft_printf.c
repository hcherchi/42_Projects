/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:58:06 by hcherchi          #+#    #+#             */
/*   Updated: 2017/01/03 14:58:14 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *ajust_buffer(t_format *format, char *buf)
{
  char *finalbuf;
  int   tofill;
  char filler;

  if (format->type == 'c' && ft_strlen(buf) == 0)
    format->nullchar = 1;
  if (format->type == 's' && format->accur < ft_strlen(buf))
    buf = ft_strsub(buf, 0, format->accur);
  filler = (ft_strchr("%cs", format->type) && format->zero) ? '0' : ' ';
  tofill = format->width - ((format->type == 'c') ? 1 : ft_strlen(buf));
  if (tofill <= 0)
    return (buf);
  finalbuf = (format->moins) ? ft_strcat(buf, ft_strnew(filler, tofill)) : ft_strcat(ft_strnew(filler, tofill), buf);
  return (finalbuf);
}

int   handle_convertion(const char *input, va_list ap, int *count)
{
  t_format *format;
  char *to_print;
  int pass;

  format = init_format();
  pass = fill_format(input, format);
  update_format(format);
  to_print = choose_convertion(format, ap);
  to_print = ajust_buffer(format, (to_print) ? to_print : ft_strdup("(null)"));
  ft_putstr(to_print);
  *count += ft_strlen(to_print) + format->nullchar;
  return (pass + 1);
}

int ft_printf(const char *input, ...)
{
  int count;
  va_list	ap;

  count = 0;
  va_start(ap, input);
  while (*input)
  {
    if (*input == '%')
      input += handle_convertion(input + 1, ap, &count);
    else
    {
      ft_putchar(*input);
      count++;
      input++;
    }
  }
  va_end(ap);
  return (count);
}
