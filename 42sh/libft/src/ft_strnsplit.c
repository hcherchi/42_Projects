/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:38:18 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/19 18:17:32 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbwords(char const *str, char c, int nbrest)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] == '\0')
			return ((count < nbrest) ? count : nbrest);
		while (str[i] != c && str[i] != '\0')
			i++;
		count++;
	}
	return ((count < nbrest) ? count : nbrest);
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

char		**ft_strnsplit(char const *str, char c, int nbrest)
{
	char	**split;
	int		nbcur;

	if (str == NULL)
		return (NULL);
	nbcur = 0;
	nbrest = ft_nbwords(str, c, nbrest);
	split = (char **)malloc(sizeof(*split) * (nbrest + 1));
	if (split == NULL)
		return (NULL);
	while (nbrest > 0)
	{
		while (*str == c)
			str++;
		if (nbrest > 1)
			split[nbcur] = ft_strsub(str, 0, ft_wordsize(str, c));
		else
			split[nbcur] = ft_strtrim(str);
		str = str + ft_wordsize(str, c);
		nbcur++;
		nbrest--;
	}
	split[nbcur] = NULL;
	return (split);
}
