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
  int width;
  char  flag;
  int   hash;
  int   zero;
  int   plus;
  int   space;
  int   moins;
}               t_format;


int   ft_printf(const char *restrict format, ...);
int   handle_convertion(const char *input, va_list ap, int *count);
int   is_convertor(char c);
t_format *init_format();
int  fill_format(const char *input, t_format *format);
void update_format(t_format *format);

char *choose_convertion(t_format *format, va_list ap);
char *convert(t_format *format, va_list ap);
char *h_convert(t_format *format, va_list ap);
char *hh_convert(t_format *format, va_list ap);
char *l_convert(t_format *format, va_list ap);
char *ll_convert(t_format *format, va_list ap);
char *j_convert(t_format *format, va_list ap);
char *z_convert(t_format *format, va_list ap);

int   ft_isdigit(int c);
int   ft_atoi(const char *str);
char *ft_sstoa_base(ssize_t nb, int base, int maj);
char *ft_stoa_base(size_t nb, int base, int maj);
char *ft_ctoa(unsigned char uc);
char *ft_strdup(char *str);
void  print_struct(t_format *format);
int ft_strlen(const char *str);
int     lennbr(size_t unb, int base);

void ft_putchar(const char c);
void ft_putstr(const char *str);
void ft_putendl(const char *str);
void ft_putnbr(int n);
char	*ft_strchr(const char *s, int c);

char *ft_attribute(t_format *foramt, char *nbr);

char	*ft_strsub(char const *s, unsigned int start, size_t len);
#endif
