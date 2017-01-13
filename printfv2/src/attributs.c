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
  else if (format->plus)
  {
    if (buf[0] != '-')
      return (ft_strcat("+", buf));
  }
  else if (format->space)
  {
    if (buf[0] != '-')
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
  if (tofill <= 0)
    return (prefixedbuf);
  if (format->zero)
    filler = '0';
  else
    filler = ' ';
  if (format->moins)
    finalbuf = ft_strcat(prefixedbuf, ft_strnew(filler, tofill));
  else
    finalbuf = ft_strcat(ft_strnew(filler, tofill), prefixedbuf);
  return (finalbuf);
}
