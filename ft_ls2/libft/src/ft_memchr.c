/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:07:38 by bgantelm          #+#    #+#             */
/*   Updated: 2015/11/27 14:22:32 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*u;
	unsigned char	i;
	int				v;

	v = 0;
	i = (unsigned char)c;
	u = (unsigned char *)s;
	while (n--)
	{
		if (u[v] == i)
			return (u + v);
		v++;
	}
	return (NULL);
}
