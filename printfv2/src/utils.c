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
#include <stdio.h>

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

char	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strsub(char const *s, int start, size_t len)
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

size_t	ft_iscount(const char *input, int count)
{
	while (input[count] >= '0' && input[count] <= '9')
		count++;
	return (count);
}
