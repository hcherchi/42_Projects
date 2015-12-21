/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:19:43 by bgantelm          #+#    #+#             */
/*   Updated: 2015/11/27 16:35:36 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;
	size_t		c;
	char		*s;
	const char	*str;

	s = dst;
	str = src;
	c = size;
	while (c-- != 0 && *s != '\0')
		s++;
	len = s - dst;
	c = size - len;
	if (c == 0)
		return (len + ft_strlen(str));
	while (*str != '\0')
	{
		if (c != 1)
		{
			*s++ = *str;
			c--;
		}
		str++;
	}
	*s = '\0';
	return (len + (str - src));
}
