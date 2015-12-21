/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:19:51 by bgantelm          #+#    #+#             */
/*   Updated: 2015/11/27 14:56:34 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*s;

	s = NULL;
	s = (char *)malloc(sizeof(char) * size + 1);
	if (s)
	{
		i = 0;
		while (i <= size)
		{
			s[i] = '\0';
			i++;
		}
	}
	return (s);
}
