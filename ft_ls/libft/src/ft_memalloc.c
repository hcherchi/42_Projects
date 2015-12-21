/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:59:35 by bgantelm          #+#    #+#             */
/*   Updated: 2015/11/27 14:21:05 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*v;
	size_t			i;

	v = NULL;
	v = (unsigned char *)malloc(size);
	if (v)
	{
		i = 0;
		while (size > 0)
		{
			v[i] = 0;
			i++;
			size--;
		}
	}
	return ((void*)v);
}
