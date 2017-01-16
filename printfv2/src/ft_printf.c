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

// void  print_struct(t_format *format)
// {
//   printf("\nConvertor: %c\nWidth: %d\nAccuracy: %d\nFlags: %c\nAttributs: \n", format->type, format->width, format->accur, format->flag);
//   if (format->hash != 0)
//   printf("Hash: %d\n", format->hash);
//   if (format->zero != 0)
//   printf("ZERO: %d\n", format->zero);
//   if (format->plus != 0)
//     printf("PLUS: %d\n", format->plus);
//   if (format->moins != 0)
//   printf("MOINS: %d\n", format->moins);
//   if (format->space != 0)
//   printf("SPACE: %d\n", format->space);
// }

char *cut_string(t_format *format, char *buf)
{
  char *cut;

  if (format->type == 's' && format->accur != -1 && format->accur < ft_strlen(buf))
  {
    cut = ft_strsub(buf, 0, format->accur);
    free(buf);
    buf = cut;
  }
  return (buf);
}

char *ajust_buffer(t_format *format, char *buf)
{
  char *finalbuf;
  char *spaces;
  int   tofill;
  char filler;

  if (format->type == 'c' && ft_strlen(buf) == 0)
    format->nullchar = 1;
  filler = (ft_strchr("%cs", format->type) && format->zero) ? '0' : ' ';
  tofill = format->width - ((format->type == 'c') ? 1 : ft_strlen(buf));
  if (tofill <= 0)
    return (ft_strdup(buf));
  spaces = ft_strnew(filler, tofill);
  finalbuf = (format->moins) ? ft_strcat(buf, spaces) : ft_strcat(spaces, buf);
  free(spaces);
  return (finalbuf);
}

int   handle_convertion(const char *input, va_list ap, int *count)
{
  t_format *format;
  char *convert;
  char *to_print;
  int pass;

  format = init_format();
  pass = fill_format(input, format);
  update_format(format);
  convert = choose_convertion(format, ap);
  convert = cut_string(format, convert);
  to_print = ajust_buffer(format, convert);
  ft_putstr(to_print);
  *count += ft_strlen(to_print) + format->nullchar;
  free(convert);
  free(format);
  free(to_print);
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
