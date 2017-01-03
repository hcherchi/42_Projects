/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:24:19 by hcherchi          #+#    #+#             */
/*   Updated: 2017/01/03 15:24:21 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_conv
{
  int accur;
  char indic;
  char att;
  int width;
  char *mod;
}               t_conv;

typedef struct	s_tool
{
  t_conv *l_conv;
}               t_tool;


int   ft_printf(const char *restrict format, ...);

#endif
