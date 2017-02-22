/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:13:03 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/13 17:57:16 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"

int			ft_strlen(const char *str)
{
	int		count;
	char	*copy;

	count = 0;
	copy = (char*)str;
	if (!copy)
		return (0);
	while (*copy != '\0')
	{
		count++;
		copy++;
	}
	return (count);
}

int			ft_strcmp(char *s1, char *s2)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (*p1 || *p2)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(int n)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	nb = (unsigned int)n;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void		ft_printname(char *str)
{
	ft_putchar('\n');
	ft_putstr("-------------------------------------\n  ");
	ft_putstr(str);
	ft_putchar('\n');
	ft_putstr("-------------------------------------\n");
}
