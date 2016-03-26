/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:55:40 by jhoudan           #+#    #+#             */
/*   Updated: 2015/11/25 17:38:11 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*data;

	data = NULL;
	data = malloc(size);
	if (data == NULL)
		return (NULL);
	ft_memset(data, 0, size);
	return (data);
}
