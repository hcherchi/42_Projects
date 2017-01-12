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
  printf("\nConvertor: %c\nWidth: %d\nAccuracy: %d\nAttributs: \n", format->type, format->width, format->accur);
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
  printf("Flag:\n");
  if (format->j != 0)
  printf("J: %d\n", format->j);
  if (format->l != 0)
  printf("L: %d\n", format->l);
  if (format->h != 0)
    printf("H: %d\n", format->h);
  if (format->z != 0)
  printf("Z: %d\n", format->z);
}

int   is_attribut(char c, t_format *format)
{
  if (c == '#')
    format->hash += 1;
  else if (c == ' ')
    format->space += 1;
  else if (c == '0')
    format->zero += 1;
  else if (c == '-')
    format->moins += 1;
  else if (c == '+')
    format->plus += 1;
  else
    return (0);
  return (1);
}

int   is_flag(char c, t_format *format)
{
  if (c == 'h')
    format->h += 1;
  else if (c == 'l')
    format->l += 1;
  else if (c == 'j')
    format->j += 1;
  else if (c == 'z')
    format->z += 1;
  else
    return (0);
  return (1);
}

t_format *init_format(void)
{
  t_format *format;

  format = malloc(sizeof(t_format));
  format->hash = 0;
  format->zero = 0;
  format->plus = 0;
  format->moins = 0;
  format->space = 0;
  format->j = 0;
  format->h = 0;
  format->z = 0;
  format->l = 0;
  format->type = '\0';
  format->accur = -1;
  format->width = -1;
  return (format);
}

int   is_convertor(char c)
{
  if (ft_strchr("sSpdDioOuUxXcC%", c))
    return (1);
  return (0);
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

  while (is_attribut(input[j], format))
    j++;
  while (input[j] >= '0' && input[j] <= '9')
  {
    tmp[i] = input[j];
    j++;
    i++;
  }
  if (i > 0)
    format->width = ft_atoi(tmp);
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
  while (is_flag(input[j], format))
    j++;
  if (is_convertor(input[j]))
  {
    format->type = input[j];
    j++;
  }
  return (j);
}

void update_format(t_format *format)
{
  if (ft_strchr("DOU", format->type))
  {
    format->type = format->type - 32;
    format->l += 1;
  }
  if (format->type == '%')
  {
    format->plus = 0;
    format->zero = 0;
    format->space = 0;
    format->hash = 0;
  }
  if (format->zero && (format->moins || ft_strchr("scp", format->type)))
    format->zero = 0;
  if (format->hash && !ft_strchr("oxX", format->type))
    format->hash = 0;
  if (format->plus && ft_strchr("cps", format->type))
    format->plus = 0;
  if (format->space && ft_strchr("cps", format->type))
    format->space = 0;
  if (format->space && format->plus)
    format->space = 0;
  if (!ft_strchr("scdoxXiup%", format->type))
    format->type = '\0';
}

int   handle_convertion(const char *input, va_list ap, int *count)
{
  t_format *format;
  char *to_print;
  int pass;

  format = init_format();
  pass = fill_format(input, format);
  //ft_putendl("AVANT");
  //print_struct(format);
  update_format(format);
  //ft_putendl("\nAPRES");
  //print_struct(format);

  to_print = choose_convertion(format, ap);
  to_print = ft_attribute(format, to_print);
  ft_putstr(to_print);
  *count += ft_strlen(to_print);
  return (pass + 1);
}
