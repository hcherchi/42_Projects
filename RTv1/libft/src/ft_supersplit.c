/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supersplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:06:53 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 20:06:54 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbwords(char const *str, char c, char v)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c || str[i] == v || str[i] == '\t')
			i++;
		if (str[i] == '\0')
			return (count);
		while (str[i] != c && str[i] != v && str[i] != '\0')
			i++;
		count++;
	}
	return (count);
}

static int	ft_wordsize(char const *str, char c, char v)
{
	int size;
	int i;

	i = 0;
	size = 0;
	while (str[i] == c || str[i] == v || str[i] == '\t')
		i++;
	while (str[i] != c && str[i] != v && str[i] != '\0')
	{
		i++;
		size++;
	}
	return (size);
}

char		**ft_supersplit(char const *str, char c, char v)
{
	char	**split;
	int		i;
	int		nbcur;
	int		nbrest;

	if (str == NULL)
		return (NULL);
	nbcur = 0;
	nbrest = ft_nbwords(str, c, v);
	i = 0;
	split = (char **)malloc(sizeof(*split) * nbrest + 1);
	if (split == NULL)
		return (NULL);
	while (nbrest > 0)
	{
		while (*str == c || *str == v || *str == '\t')
			str++;
		split[nbcur] = ft_strsub(str, i, ft_wordsize(str, c, v));
		str = str + ft_wordsize(str, c, v);
		nbcur++;
		nbrest--;
	}
	split[nbcur] = NULL;
	return (split);
}
