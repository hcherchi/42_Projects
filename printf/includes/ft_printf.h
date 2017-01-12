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
# include <stdarg.h>

typedef struct	s_format
{
  int accur;
  char type;
  char attribut;
  int width;
  char flag;
  int   hash;
  int   zero;
  int   minus;
  int   plus;
  int   space;
}               t_format;


int   ft_printf(const char *restrict format, ...);
int   handle_convertion(const char *input, va_list ap, int *count);
int   is_convertor(char c);
t_format *init_format();
int  fill_format(const char *input, t_format *format);

int   ft_isdigit(int c);
int   ft_atoi(const char *str);
char *ft_itoa_base(int nb, int base);
char *ft_uitoa_base(unsigned int unb, int base);
char *ft_ctoa(unsigned char uc);

int ft_strlen(const char *str);
int     lennbr(unsigned int unb, int base);

void ft_putchar(const char c);
void ft_putstr(const char *str);
void ft_putendl(const char *str);
void ft_putnbr(int n);
char	*ft_strchr(const char *s, int c);

#endif
