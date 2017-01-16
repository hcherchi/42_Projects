#include "ft_printf.h"

int     get_len(size_t unb, int base, int prefix, t_format *format)
{
    int c;
    int len;

    c = 0;
    if (unb == 0)
        c = (format->accur == 0) ? 0 : 1;
    while (unb != 0)
    {
        unb /= base;
        c++;
    }
    if (format->zero && format->width > format->accur && format->width > c)
      len = format->width - prefix;
    else if (format->accur > c)
      len = format->accur;
    else
      len = c;
    return (len);
}

char   get_sign(ssize_t nb, t_format *format)
{
  if (nb >= 0)
  {
    if (format->space)
      return (' ');
    else if (format->plus)
      return ('+');
  }
  else
      return ('-');
  return (0);
}

char *itoa_10(ssize_t nb, t_format *format)
{
    size_t unb;
    char sign;
    int len;
    char    *value;

		if (nb == 0 && format->accur == 0)
        return (ft_strdup(""));
    sign = get_sign(nb, format);
    unb = (nb < 0) ? -1 * nb : nb;
    len = get_len(unb, 10, ((sign) ? 1 : 0), format) + ((sign) ? 1 : 0);
    value = (char *)malloc(sizeof(*value) * len + 1);
    value[len] = '\0';
    len--;
    while (unb != 0)
    {
        value[len] = unb % 10 + '0';
        unb /= 10;
        len--;
    }
		while (len >= 0)
		{
			value[len] = (sign != 0 && len == 0) ? sign : '0';
			len--;
		}
    return (value);
}

int  get_prefix(size_t unb, t_format *format)
{
  int prefix;

  prefix = 0;
  if (format->hash)
  {
    if (((format->type == 'x' || format->type == 'X') && unb != 0) || format->type == 'p')
      prefix = 2;
    else if (format->type == 'o')
      prefix = 1;
  }
  return (prefix);
}

void put_prefix(char *value, int len, int prefix, int maj)
{
  while (len >= 0)
  {
    if (len == 1 && prefix == 2)
    {
       value[len] = (maj) ? 'X' : 'x';
       prefix--;
    }
    else
      value[len] = '0';
    len--;
  }
}

char *uitoa_base(size_t unb, int base, int maj, t_format *format)
{
    int len;
    char    *value;
    int     prefix;

    if (unb == 0 && format->accur == 0 && format->type != 'o' && format->type != 'p')
      return (ft_strdup(""));
    prefix = get_prefix(unb, format);
    len = get_len(unb, base, prefix, format) + prefix;
		value = (char *)malloc(sizeof(*value) * len + 1);
    value[len] = '\0';
    len--;
    while (unb != 0)
    {
        if (unb % base <= 9)
            value[len] = unb % base + '0';
        else
            value[len] = (maj) ? unb % base + 'A' - 10 : unb % base + 'a' - 10;
        unb /= base;
        len--;
    }
    put_prefix(value, len, prefix, maj);
    return (value);
}
