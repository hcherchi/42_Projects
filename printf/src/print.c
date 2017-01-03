/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:44:11 by hcherchi          #+#    #+#             */
/*   Updated: 2017/01/03 16:44:13 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(const char c)
{
  write(1, &c, 1);
}

int ft_strlen(const char *str)
{
  int i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void ft_putstr(const char *str)
{
  write(1, str, ft_strlen(str));
}

void ft_putendl(const char *str)
{
  ft_putstr(str);
  ft_putchar('\n');
}
