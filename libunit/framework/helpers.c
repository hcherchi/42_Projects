/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:12:11 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/13 23:10:05 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"

char		*ft_strdup(char *str)
{
	int		len;
	char	*newstr;
	int		i;

	i = 0;
	len = ft_strlen(str);
	newstr = (char*)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

void		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*s;

	if (s2 == NULL && s1 == NULL)
		return (NULL);
	else if (s2 == NULL)
		return ((char *)s1);
	else if (s1 == NULL)
		return ((char *)s2);
	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s == NULL)
		return (NULL);
	ft_strcpy(s, s1);
	ft_strcat(s, s2);
	return (s);
}

char		*ft_strcpy(char *dst, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_strcat(char *s1, char *s2)
{
	char	*str1;
	char	*str2;

	str1 = s1;
	str2 = (char*)s2;
	while (*str1)
	{
		str1++;
	}
	while (*str2)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return (s1);
}
