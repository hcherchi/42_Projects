/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strsplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:11:59 by jhoudan           #+#    #+#             */
/*   Updated: 2015/11/25 22:26:27 by jhoudan          ###   ########.fr       */
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

t_list		*ft_lst_strsplit(char const *s, char c)
{
	char	*str;
	int		count;
	t_list	*ptr;
	char	*temp;
	t_list	*new;

	ptr = NULL;
	if ((str = ft_strdup((char*)s)) == NULL)
		return (NULL);
	temp = str;
	count = ft_remove_char(str, c);
	while (count)
	{
		while (*str == '\0')
			str++;
		new = ft_lstnew(ft_strsub(str, 0, ft_strlen(str)), ft_strlen(str));
		ft_lst_push_back(&ptr, new);
		while (*str != '\0')
			str++;
		count--;
	}
	ft_strdel(&temp);
	return (ptr);
}
