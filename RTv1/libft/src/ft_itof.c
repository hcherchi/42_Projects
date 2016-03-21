/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:08:16 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/21 11:23:34 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char    *ft_strjoin_moin(char *s1)
{
	char	*s3;
	int i;
	int j;

	i = 0;
	j =  3;
	s3 = ft_strnew(ft_strlen(s1) + 1);
	s3[0] = '-';
	s3[1] = '0';
	s3[2] = ',';
	while (s1[i] != '\0')
	{
		s3[j] = s1[i];
		i++;
		j++;
	}
	return (s3);
}

static	char    *ft_strjoin_plus(char *s1)
{
	char	*s3;
	int i;
	int j;

	i = 0;
	j =  2;
	s3 = ft_strnew(ft_strlen(s1) + 1);
	s3[0] = '0';
	s3[1] = ',';
	while (s1[i] != '\0')
	{
		s3[j] = s1[i];
		i++;
		j++;
	}
	return (s3);
}
static int  ft_lennbr(int nbr)
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
char        *ft_itoa_spe(int nbr)
{
	char    *nombre;
	int		i;
	if (nbr < 0)
		nbr = nbr * -1;
	i = ft_lennbr(nbr);
	nombre = (char *)malloc(sizeof(*nombre) * i + 1);
	if (nbr == -2147483648)
		return (ft_strcpy(nombre, "-2147483648"));
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
	return (nombre);
}
char			*ft_itof(int nbr)
{
	char *s1;

	s1 = ft_itoa_spe(nbr);
	if (nbr < 0)
		return (ft_strjoin_plus(s1));
	else
		return (ft_strjoin_moin(s1));
}
