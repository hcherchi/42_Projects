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

int     lennbr(unsigned int unb, int base)
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

char *ft_itoa_base(int nb, int base)
{
    unsigned int unb;
    int signe;
    int len;
    char    *value;

    signe = 0;
    if (nb >= 0)
        unb = nb;
    else
    {
        if (base == 10)
            signe = 1;
        unb = -1 * nb;
    }
    len = lennbr(unb, base) + signe;
    value = (char *)malloc(sizeof(*value) * len + 1);
    value[len] = '\0';
    len--;
    if (unb == 0)
        value[len] = '0';
    while (unb != 0)
    {
        if (unb % base <= 9)
            value[len] = unb % base + '0';
        else
            value[len] = unb % base + 'A' - 10;
        unb /= base;
        len--;
    }
    if (signe == 1)
        value[len] = '-';
    return (value);
}

char *ft_uitoa_base(unsigned int unb, int base)
{
    int len;
    char    *value;

    len = lennbr(unb, base);
    value = (char *)malloc(sizeof(*value) * len + 1);
    value[len] = '\0';
    len--;
    if (unb == 0)
        value[len] = '0';
    while (unb != 0)
    {
        if (unb % base <= 9)
            value[len] = unb % base + '0';
        else
            value[len] = unb % base + 'A' - 10;
        unb /= base;
        len--;
    }
    return (value);
}

char *ft_ctoa(unsigned char uc)
{
  char *res;

  res = malloc(sizeof(char *) + 1);
  res[0] = (char)uc;
  res[1] = '\0';
  return (res);
}
