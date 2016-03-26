/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 13:25:30 by jhoudan           #+#    #+#             */
/*   Updated: 2015/12/13 22:11:11 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	print_wchar1(unsigned int letter)
{
	unsigned int	mask;
	unsigned char	octet;

	mask = 0;
	octet = letter;
	return (write(1, &octet, 1));
}

static	int	print_wchar2(unsigned int letter)
{
	unsigned int	mask;
	unsigned char	octet;
	unsigned char	b_octet;

	mask = 49280;
	b_octet = ((letter >> 6) << 27) >> 27;
	octet = (mask >> 8) | b_octet;
	write(1, &octet, 1);
	b_octet = (letter << 26) >> 26;
	octet = ((mask << 24) >> 24) | b_octet;
	write(1, &octet, 1);
	return (2);
}

static	int	print_wchar3(unsigned int letter)
{
	unsigned int	mask;
	unsigned char	octet;
	unsigned char	b_octet;

	mask = 14712960;
	b_octet = ((letter >> 12) << 28) >> 28;
	octet = (mask >> 16) | b_octet;
	write(1, &octet, 1);
	b_octet = ((letter >> 6) << 26) >> 26;
	octet = ((mask << 16) >> 24) | b_octet;
	write(1, &octet, 1);
	b_octet = (letter << 26) >> 26;
	octet = ((mask << 24) >> 24) | b_octet;
	write(1, &octet, 1);
	return (3);
}

static	int	print_wchar4(unsigned int letter)
{
	unsigned int	mask;
	unsigned char	octet;
	unsigned char	b_octet;

	mask = 4034953344;
	b_octet = ((letter >> 18) << 29) >> 29;
	octet = (mask >> 24) | b_octet;
	write(1, &octet, 1);
	b_octet = ((letter >> 12) << 26) >> 26;
	octet = ((mask << 8) >> 24) | b_octet;
	write(1, &octet, 1);
	b_octet = ((letter >> 6) << 26) >> 26;
	octet = ((mask << 16) >> 24) | b_octet;
	write(1, &octet, 1);
	b_octet = (letter << 26) >> 26;
	octet = ((mask << 24) >> 24) | b_octet;
	write(1, &octet, 1);
	return (4);
}

int			ft_putwchar(wchar_t letter)
{
	int nb_bit;

	nb_bit = count_significant_bit(letter);
	if (nb_bit <= 7)
		return (print_wchar1(letter));
	else if (nb_bit <= 11)
		return (print_wchar2(letter));
	else if (nb_bit <= 16)
		return (print_wchar3(letter));
	else
		return (print_wchar4(letter));
	return (0);
}
