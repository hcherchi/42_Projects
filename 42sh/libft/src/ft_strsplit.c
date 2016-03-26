/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:07:04 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/17 15:44:54 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_remove_char(char *s, char c)
{
	int wcount;
	int word;

	word = 0;
	wcount = 0;
	while (*s)
	{
		if (*s != c && word == 0)
		{
			wcount++;
			word = 1;
		}
		else if (*s == c)
		{
			*s = '\0';
			word = 0;
		}
		s++;
	}
	return (wcount);
}

char		**ft_strsplit(char const *s, char c)
{
	char	*str;
	int		count;
	int		j;
	char	**ptr;
	char	*temp;

	j = 0;
	if ((str = ft_strdup((char*)s)) == NULL)
		return (NULL);
	temp = str;
	count = ft_remove_char(str, c);
	ptr = (char **)ft_memalloc(sizeof(char *) * (count + 1));
	while (count)
	{
		while (*str == '\0')
			str++;
		ptr[j] = ft_strsub(str, 0, ft_strlen(str));
		while (*str != '\0')
			str++;
		count--;
		j++;
	}
	ptr[j] = 0;
	ft_strdel(&temp);
	return (ptr);
}
