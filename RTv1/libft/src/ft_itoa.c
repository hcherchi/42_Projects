/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:08:16 by hcherchi          #+#    #+#             */
/*   Updated: 2015/11/30 12:30:39 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lennbr(int nbr)
{
	int c;

	c = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		c++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		c++;
	}
	return (c);
}

static int	ft_signe(int *pn)
{
	if (*pn < 0)
	{
		*pn = -1 * (*pn);
		return (1);
	}
	else
		return (0);
}

char		*ft_itoa(int nbr)
{
	char	*nombre;
	int		i;
	int		signe;

	i = ft_lennbr(nbr);
	nombre = (char *)malloc(sizeof(*nombre) * i + 1);
	if (nbr == -2147483648)
		return (ft_strcpy(nombre, "-2147483648"));
	signe = ft_signe(&nbr);
	nombre[i] = '\0';
	i--;
	if (nbr == 0)
		nombre[i] = '0';
	while (nbr != 0)
	{
		nombre[i] = (nbr % 10) + 48;
		nbr = nbr / 10;
		i--;
	}
	if (signe == 1)
		nombre[i] = '-';
	return (nombre);
}
