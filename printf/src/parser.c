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

  to_print = choose_convertion(format, ap);
  ft_putstr(to_print);
  *count += ft_strlen(to_print) + 1;
  return (pass + 1);
}
