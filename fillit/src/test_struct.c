/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:53:25 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/04 16:58:43 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	test_nbline(char *piece)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (piece[i] != '\0')
	{
		if (piece[i] == '\n')
			c++;
		i++;
	}
	if (c != 4)
		return (1);
	return (0);
}

int	test_nbcol(char *piece)
{
	int i;
	int c;

	i = 0;
	while (piece[i] != '\0')
	{
		c = 0;
		while (piece[i] != '\n')
		{
			c++;
			i++;
		}
		if (c != 4)
			return (1);
		i++;
	}
	return (0);
}

int	test_sizemin(char *pieces, size_t i)
{
	int c;

	c = 0;
	while (pieces[i] != '\0')
	{
		c++;
		i++;
	}
	if (c < 20)
		return (1);
	return (0);
}

int	test_struct(char *pieces)
{
	size_t	i;
	char	*temp;

	i = 0;
	if (pieces == NULL || pieces[i] == '\0')
		return (1);
	while (pieces[i] != '\0')
	{
		if (test_sizemin(pieces, i) == 1)
			return (1);
		temp = ft_strsub((const char *)pieces, i, 20);
		if (test_nbline(temp) == 1 || test_nbcol(temp) == 1)
			return (1);
		i += 20;
		if (pieces[i] != '\n' && pieces[i] != '\0')
			return (1);
		if (pieces[i] == '\n')
			i++;
		free(temp);
	}
	return (0);
}
