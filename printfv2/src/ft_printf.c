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

int ft_printf(const char *input, ...)
{
  int count;
  va_list	ap;

  count = 0;
  va_start(ap, input);
  while (*input)
  {
    if (*input == '%')
    {
      input += handle_convertion(input + 1, ap, &count);
    }
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
