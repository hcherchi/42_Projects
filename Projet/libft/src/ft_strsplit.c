/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:38:18 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/07 18:18:45 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbwords(char const *str, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] == '\0')
			return (count);
		while (str[i] != c && str[i] != '\0')
			i++;
		count++;
	}
	return (count);
}

static int	ft_wordsize(char const *str, char c)
{
	int size;
	int i;

	i = 0;
	size = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		size++;
	}
	return (size);
}

char		**ft_strsplit(char const *str, char c)
{
	char	**split;
	int		i;
	int		nbcur;
	int		nbrest;

	if (str == NULL)
		return (NULL);
	nbcur = 0;
	nbrest = ft_nbwords(str, c);
	i = 0;
	split = (char **)malloc(sizeof(*split) * nbrest + 1);
	if (split == NULL)
		return (NULL);
	while (nbrest > 0)
	{
		while (*str == c)
			str++;
		split[nbcur] = ft_strsub(str, i, ft_wordsize(str, c));
		str = str + ft_wordsize(str, c);
		nbcur++;
		nbrest--;
	}
	split[nbcur] = NULL;
	return (split);
}
