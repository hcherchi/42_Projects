/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:50:51 by bgantelm          #+#    #+#             */
/*   Updated: 2015/11/27 16:09:39 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*i1;
	unsigned char	*i2;

	if (dst && src)
	{
		i1 = (unsigned char *)dst;
		i2 = (unsigned char *)src;
		while (n > 0)
		{
			*i1 = *i2;
			if (*i2 == (unsigned char)c)
				return ((void *)(i1 + 1));
			i1++;
			i2++;
			n--;
		}
	}
	return (NULL);
}
