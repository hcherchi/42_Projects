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
#include <stdio.h>

void  print_struct(t_format *format)
{
  printf("\nConvertor: %c\nWidth: %d\nAccuracy: %d\nFlags: %c\nAttributs: \n", format->type, format->width, format->accur, format->flag);
  if (format->hash != 0)
  printf("Hash: %d\n", format->hash);
  if (format->zero != 0)
  printf("ZERO: %d\n", format->zero);
  if (format->plus != 0)
    printf("PLUS: %d\n", format->plus);
  if (format->moins != 0)
  printf("MOINS: %d\n", format->moins);
  if (format->space != 0)
  printf("SPACE: %d\n", format->space);
}

char *ajust_buffer(t_format *format, char *buf)
{
  char *finalbuf;
  int   tofill;

  tofill = format->width - ft_strlen(buf);
  if (tofill <= 0)
    return (buf);
  finalbuf = (format->moins) ? ft_strcat(buf, ft_strnew(' ', tofill)) : ft_strcat(ft_strnew(' ', tofill), buf);
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
  to_print = ajust_buffer(format, to_print);
  ft_putstr(to_print);
  *count += ft_strlen(to_print);
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
