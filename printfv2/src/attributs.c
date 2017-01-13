#include "ft_printf.h"
#include <stdio.h>

char *add_prefix(t_format *format, char *buf)
{
  if (format->hash)
  {
    if (format->type == 'X')
      return (ft_strcat("0X", buf));
    else if (format->type == 'x' || format->type == 'p')
      return (ft_strcat("0x", buf));
    else
      return (ft_strcat("0", buf));
  }
  if (buf[0] != '-' && ft_strchr("di", format->type))
  {
    if (format->plus)
      return (ft_strcat("+", buf));
    else if (format->space)
      return (ft_strcat(" ", buf));
  }
  return ft_strdup(buf);
}

char *ft_attribute(t_format *format, char *buf)
{
  char *prefixedbuf;
  char filler;
  char *finalbuf;
  int   tofill;

  prefixedbuf = add_prefix(format, buf);
  tofill = format->width - ft_strlen(prefixedbuf);
  filler = (format->zero) ? '0' : ' ';
  if (tofill <= 0)
    return (prefixedbuf);
  finalbuf = (format->moins) ? ft_strcat(prefixedbuf, ft_strnew(filler, tofill)) : ft_strcat(ft_strnew(filler, tofill), prefixedbuf);
  return (finalbuf);
}
