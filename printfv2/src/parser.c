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


t_format *init_format(void)
{
  t_format *format;

  format = malloc(sizeof(t_format));
  format->hash = 0;
  format->zero = 0;
  format->plus = 0;
  format->moins = 0;
  format->space = 0;
  format->flag = '\0';
  format->type = '\0';
  format->accur = -1;
  format->width = -1;
  format->nullchar = 0;
  return (format);
}

int  fill_format(const char *input, t_format *format)
{
  int count;

  count = 0;
  count += fill_attribut(input, count, format);
  count += fill_width(input, count, format);
  count += fill_accur(input, count, format);
  count += fill_flag(input, count, format);
  count += fill_type(input, count, format);
  return (count);
}

void update_format(t_format *format)
{
  if (ft_strchr("DOUCS", format->type))
  {
    format->type = format->type + 32;
    if (format->flag == 'l')
      format->flag = 'L';
    else if (!format->flag)
      format->flag = 'l';
  }
  if (format->type == 'p')
    format->hash = 1;
  if (format->zero && (format->moins || (format->accur > -1 && !ft_strchr("sc%", format->type))))
    format->zero = 0;
  if (format->space && format->plus)
    format->space = 0;
}
