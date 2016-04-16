/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:34:58 by bgantelm          #+#    #+#             */
/*   Updated: 2015/11/27 14:25:49 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*v;
	size_t			i;

	i = 0;
	v = (unsigned char*)b;
	while (i < len)
	{
		v[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
