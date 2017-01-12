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

int   is_attribut(char c, t_format *format)
{
  ft_putstr("attribute");
  if (c == '#')
  {
    format->attribut = '#';
    return (1);
  }
  else if (c == ' ')
  {
    format->attribut = ' ';
    return (1);
  }
  else if (c == '0')
  {
    format->attribut = '0';
    return (1);
  }
  else if (c == '-')
  {
    format->attribut = '-';
    return (1);
  }
  else if (c == '+')
  {
    format->attribut = '+';
    return (1);
  }
  return (0);
}

int   is_flag(char c, t_format *format)
{
  if (c == 'h')
  {
    format->flag = 'h';
    return (1);
  }
  else if (c == 'l')
  {
    format->flag = 'l';
    return (1);
  }
  else if (c == 'j')
  {
    format->flag = 'j';
    return (1);
  }
  else if (c == 'z')
  {
    format->flag = 'z';
    return (1);
  }
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

int  fill_format(const char *input, t_format *format)
{
  char *tmp;
  char *tmp2;
  int i;
  int j;

  i = 0;
  j = 0;
  tmp = malloc(sizeof(*input));
  tmp2 = malloc(sizeof(*input));

  if (is_attribut(input[j], format))
    j++;
  while (ft_strchr("# -+", input[j]))
    j++;
  while (input[j] >= '0' && input[j] <= '9')
  {
    tmp[i] = input[j];
    j++;
    i++;
  }
  if (i > 0)
    format->minus = ft_atoi(tmp);
  if (input[j] == '.')
  {
    j++;
    i = 0;
    while (input[j] >= '0' && input[j] <= '9')
    {
      tmp2[i] = input[j];
      j++;
      i++;
    }
    if (i > 0)
      format->accur = ft_atoi(tmp2);
  }
  if (is_flag(input[j], format))
    j++;
  if (input[j] == 'h')
  {
    format->flag = 'H';
    j++;
  }
  if (input[j] == 'l')
  {
    format->flag = 'L';
    j++;
  }
  if (is_convertor(input[j]))
  {
    format->type = input[j];
    j++;
  }
  return (j);
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
  *count += ft_strlen(to_print) + 1;
  return (pass + 1);
}
