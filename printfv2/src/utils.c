/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:43:57 by hcherchi          #+#    #+#             */
/*   Updated: 2017/01/03 16:43:59 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s != '\0')
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

int ft_strlen(const char *str)
{
  int i;

  i = 0;
  while (str[i])
  {
    i++;
  }
  return (i);
}

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

char *ft_strdup(char *str)
{
	char *newstr;
	int i;

	i = 0;
	newstr = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char *ft_ctoa(unsigned char uc)
{
  char *res;

  res = malloc(sizeof(char *) + 1);
  res[0] = (char)uc;
  res[1] = '\0';
  return (res);
}


int	ft_atoi(const char *str)
{
	int				number;
	int				neg;

	number = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
	|| *str == '\f' || *str == '\r')
		str++;
	if (!str)
		return (0);
	neg = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = 1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		number = (number * 10) + ((int)*str - 48);
		str++;
	}
	if (neg == 1)
		number = -number;
	return (number);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char *ft_strnew(char c, int n)
{
	char *str;
	int i;

	i = 0;
	str = malloc(sizeof(char) * (n + 1));
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	if ((res = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		res[i] = s[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_iscount(const char **input)
{
	int	count;

	count = 0;
	while (**input >= '0' && **input <= '9')
	{
		**input++;
		count++;
	}
	return (count);
}

char *ft_strcat(char *dest, char *src)
{
	int i;
	int j;
	char *newstr;

	j = 0;
	i = 0;
	newstr = malloc(sizeof(char) * (ft_strlen(src) + ft_strlen(dest)) + 1);
	while (dest[i])
	{
		newstr[i] = dest[i];
		i++;
	}
	while (src[j])
	{
		newstr[i] = src[j];
		j++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
