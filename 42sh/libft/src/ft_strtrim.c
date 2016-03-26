/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:09:08 by jhoudan           #+#    #+#             */
/*   Updated: 2015/11/23 13:09:40 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*ptr;
	int		i;

	i = 0;
	start = 0;
	while (s[start] && ft_is_space(s[start]))
		start++;
	end = ft_strlen(s) - 1;
	while (end > start && ft_is_space(s[end]))
		end--;
	ptr = ft_strnew(end - start + 1);
	if (ptr != NULL)
	{
		while (start <= end)
		{
			ptr[i] = s[start];
			start++;
			i++;
		}
	}
	return (ptr);
}
