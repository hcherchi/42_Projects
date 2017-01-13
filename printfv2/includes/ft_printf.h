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
  int   nullchar;
}               t_format;


int   ft_printf(const char *restrict format, ...);
int   handle_convertion(const char *input, va_list ap, int *count);
char *ajust_buffer(t_format *format, char *buf);

int   is_convertor(char c);
t_format *init_format();
int  fill_format(const char *input, t_format *format);
void update_format(t_format *format);
char *add_prefix(t_format *format, char *buf);

char *choose_convertion(t_format *format, va_list ap);
char *convert(t_format *format, va_list ap);
char *h_convert(t_format *format, va_list ap);
char *hh_convert(t_format *format, va_list ap);
char *l_convert(t_format *format, va_list ap);
char *ll_convert(t_format *format, va_list ap);
char *j_convert(t_format *format, va_list ap);
char *z_convert(t_format *format, va_list ap);
char		*ft_itoa(int nbr);

char	ft_toupper(char c);
int   ft_isdigit(int c);
int   ft_atoi(const char *str);
char *ft_strdup(char *str);
char	*ft_strsub(char const *s, int start, size_t len);
size_t	ft_iscount(const char *input, int j);
void  print_struct(t_format *format);
int ft_strlen(const char *str);
char *ft_strcat(char *src, char *dest);
char *ft_strnew(char c, int n);

int  get_prefix(size_t unb, t_format *format);
int     get_len(size_t unb, int base, int prefix, t_format *format);
char   get_sign(ssize_t nb, t_format *format);
char *itoa_10(ssize_t nb, t_format *format);
char *uitoa_base(size_t nb, int base, int maj, t_format *format);

void ft_putchar(const char c);
void ft_putstr(const char *str);
void ft_putendl(const char *str);
void ft_putnbr(int n);
char	*ft_strchr(const char *s, int c);

char *ft_attribute(t_format *format, char *nbr);

#endif
