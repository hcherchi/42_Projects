/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:08:36 by jhoudan           #+#    #+#             */
/*   Updated: 2015/11/23 13:09:04 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;

	ptr = ft_strnew(len);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	s += start;
	while (len)
	{
		ptr[i] = s[i];
		len--;
		i++;
	}
	return (ptr);
}
