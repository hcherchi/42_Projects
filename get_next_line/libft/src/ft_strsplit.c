/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:58:49 by bgantelm          #+#    #+#             */
/*   Updated: 2015/11/30 12:07:26 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word(char const *s, char c)
{
	int	v;
	int	i;

	v = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && i == 0)
		{
			i = 1;
			v++;
		}
		else if (i == 1 && *s == c)
		{
			i = 0;
		}
		s++;
	}
	return (v);
}

static size_t	nb_letter(const char *s, char c)
{
	size_t	nbletter;

	nbletter = 0;
	while (*s)
	{
		while (*s == c)
		{
			s++;
		}
		while (*s != c && *s != '\0')
		{
			s++;
			nbletter++;
			if (*s == c)
				return (nbletter);
		}
		s++;
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		word;
	char	**array;
	int		nb;

	nb = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	word = ft_word(s, c);
	array = (char **)malloc(sizeof(char *) * (word + 1));
	if (array == NULL)
		return (NULL);
	while (word > 0)
	{
		while (s[i] == c)
			i++;
		array[nb] = ft_strsub(s, i, nb_letter(s, c));
		s = s + i + nb_letter(s, c);
		nb++;
		i = 0;
		word--;
	}
	array[nb] = NULL;
	return (array);
}
