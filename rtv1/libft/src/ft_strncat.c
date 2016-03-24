/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:09:13 by bgantelm          #+#    #+#             */
/*   Updated: 2015/11/27 14:44:15 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = s1;
	str2 = (char*)s2;
	while (*str1)
	{
		str1++;
	}
	while (*str2 && n > 0)
	{
		*str1 = *str2;
		str1++;
		str2++;
		n--;
	}
	*str1 = '\0';
	return (s1);
}
