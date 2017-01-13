#include "ft_printf.h"

int     get_len(size_t unb, int base, t_format *format)
{
    int c;
    int len;

    c = 0;
    if (unb == 0)
        c = 1;
    while (unb != 0)
    {
        unb /= base;
        c++;
    }
    if (format->zero && format->width > format->accur && format->width > c)
      len = format->width;
    else if (format->accur > c)
      len = format->accur;
    else
      len = c;
    return (len);
}

size_t   get_sign(ssize_t nb, int *sign, int base)
{
  size_t unb;

  *sign = 0;
  if (nb >= 0)
      unb = (size_t)nb;
  else
  {
      if (base == 10)
          *sign = 1;
      unb = -1 * (size_t)nb;
  }
  return (unb);
}

char *ft_itoa_base(ssize_t nb, int base, int maj, t_format *format)
{
    size_t unb;
    int sign;
    int len;
    char    *value;

		if (nb == 0)
    {
      if (format->accur == 0)
        return (ft_strdup(""));
      format->hash = 0;
    }

    unb = get_sign(nb, &sign, base);
    len = get_len(unb, base, format) + sign;
    value = (char *)malloc(sizeof(*value) * len + 1);
    value[len] = '\0';
    len--;
    while (unb != 0)
    {
        if (unb % base <= 9)
            value[len] = unb % base + '0';
        else if (maj)
            value[len] = unb % base + 'A' - 10;
				else
						value[len] = unb % base + 'a' - 10;
        unb /= base;
        len--;
    }
		while (len >= 0)
		{
			value[len] = (sign == 1 && len == 0) ? '-' : '0';
			len--;
		}
    return (value);
}

char *ft_uitoa_base(size_t unb, int base, int maj, t_format *format)
{
    int len;
    char    *value;

    if (unb == 0)
    {
      if (format->accur == 0)
        return (ft_strdup(""));
      format->hash = 0;
    }
    len = get_len(unb, base, format);
		value = (char *)malloc(sizeof(*value) * len + 1);
    value[len] = '\0';
    len--;
    while (unb != 0)
    {
        if (unb % base <= 9)
            value[len] = unb % base + '0';
        else if (maj)
            value[len] = unb % base + 'A' - 10;
				else
						value[len] = unb % base + 'a' - 10;
        unb /= base;
        len--;
    }
		while (len >= 0)
		{
			value[len] = '0';
			len--;
		}
    return (value);
}
