/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 12:55:14 by jhoudan           #+#    #+#             */
/*   Updated: 2015/11/24 19:12:13 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t my_size;

	i = 0;
	while (*dst && size)
	{
		dst++;
		size--;
		i++;
	}
	if (size == 0 && *dst != '\0')
		return (i + ft_strlen(src));
	my_size = i + ft_strlen(src);
	i = 0;
	while (src[i] && size - 1)
	{
		dst[i] = src[i];
		i++;
		size--;
	}
	dst[i] = '\0';
	return (my_size);
}
