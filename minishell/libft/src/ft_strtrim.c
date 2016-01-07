/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:31:04 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/07 18:00:16 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		end;
	int		start;
	char	*res;

	if (s == '\0')
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	if (s[start] == '\0')
	{
		return (ft_strnew(0));
	}
	while (s[end] == ' ' || s[end] == '\t' || s[end] == '\n')
		end--;
	res = ft_strsub(s, start, end - start + 1);
	return (res);
}
