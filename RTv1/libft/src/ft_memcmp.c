/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:51:25 by bgantelm          #+#    #+#             */
/*   Updated: 2015/11/29 11:27:54 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*i1;
	unsigned char	*i2;

	if (s1 && s2)
	{
		i1 = (unsigned char*)s1;
		i2 = (unsigned char*)s2;
		while (n > 0)
		{
			if (*i1 != *i2)
				return (*i1 - *i2);
			n--;
			i1++;
			i2++;
		}
	}
	return (0);
}
