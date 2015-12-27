/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:05:56 by bgantelm          #+#    #+#             */
/*   Updated: 2015/11/27 14:24:01 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*i1;
	char	*i2;
	size_t	i;

	if (n == 0 || dst == src)
		return (dst);
	i1 = (char*)dst;
	i2 = (char*)src;
	i = 0;
	while (i < n)
	{
		i1[i] = i2[i];
		i++;
	}
	return (dst);
}
