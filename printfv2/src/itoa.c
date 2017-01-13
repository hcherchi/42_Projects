#include "ft_printf.h"

int     lennbr(size_t unb, int base)
{
    int c;

    c = 0;
    if (unb == 0)
        return (1);
    while (unb != 0)
    {
        unb /= base;
        c++;
    }
    return (c);
}

char *ft_sstoa_base(ssize_t nb, int base, int maj, t_format *format)
{
    size_t unb;
    int signe;
    int len;
    char    *value;

		if (nb == 0 && format->accur == 0)
			return (ft_strdup(""));
    signe = 0;
    if (nb >= 0)
        unb = nb;
    else
    {
        if (base == 10)
            signe = 1;
        unb = -1 * nb;
    }
    len = lennbr(unb, base);
		len = (len < format->accur) ? format->accur + signe : len + signe;
    value = (char *)malloc(sizeof(*value) * len + 1);
    value[len] = '\0';
    len--;
    if (unb == 0)
		{
			format->hash = 0;
        value[len] = '0';
		}
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
			value[len] = (signe == 1 && len == 0) ? '-' : '0';
			len--;
		}
    return (value);
}

char *ft_stoa_base(size_t unb, int base, int maj, t_format *format)
{
    int len;
    char    *value;

		if (unb == 0 && format->accur == 0)
			return (ft_strdup(""));
    len = lennbr(unb, base);
		len = (len < format->accur) ? format->accur : len;
		value = (char *)malloc(sizeof(*value) * len + 1);
    value[len] = '\0';
    len--;
    if (unb == 0)
		{
			format->hash = 0;
        value[len] = '0';
		}
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
