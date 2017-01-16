#include "ft_printf.h"

int		count_significant_bit(int value)
{
	int bit;

	bit = 31;
	while (bit >= 0)
	{
		if (value & (1 << bit))
			return (bit + 1);
		bit--;
	}
	return (0);
}

int	ctowc1(wchar_t letter, char *res)
{
	unsigned int	mask;

  res = malloc(sizeof(char) * 2);
	mask = 0;
	*res = letter;
  ft_putnbr(*res);
  *(res + 1) = '\0';
	return (1);
}

int	ctowc2(wchar_t letter, char *res)
{
	unsigned int	mask;
	char	b_octet;

  res = malloc(sizeof(char) * 3);
	mask = 49280;
	b_octet = ((letter >> 6) << 27) >> 27;
	*res = (mask >> 8) | b_octet;
  ft_putnbr(*res);
	b_octet = (letter << 26) >> 26;
	*(res + 1) = ((mask << 24) >> 24) | b_octet;
  *(res + 2) = '\0';
	return (2);
}

int	ctowc3(wchar_t letter, char *res)
{
	unsigned int	mask;
	char	b_octet;

  res = malloc(sizeof(char) * 4);
	mask = 14712960;
	b_octet = ((letter >> 12) << 28) >> 28;
	*res = (mask >> 16) | b_octet;
  ft_putnbr(*res);
	b_octet = ((letter >> 6) << 26) >> 26;
	*(res + 1) = ((mask << 16) >> 24) | b_octet;
	b_octet = (letter << 26) >> 26;
	*(res + 2) = ((mask << 24) >> 24) | b_octet;
  *(res + 3) = '\0';
  return (3);
}

int ctowc4(wchar_t letter, char *res)
{
	unsigned int	mask;
	char	b_octet;

  res = malloc(sizeof(char) * 5);
	mask = 4034953344;
	b_octet = ((letter >> 18) << 29) >> 29;
	*res = (mask >> 24) | b_octet;
  ft_putnbr(*res);
	b_octet = ((letter >> 12) << 26) >> 26;
	*(res + 1) = ((mask << 8) >> 24) | b_octet;
	b_octet = ((letter >> 6) << 26) >> 26;
	*(res + 2) = ((mask << 16) >> 24) | b_octet;
	b_octet = (letter << 26) >> 26;
	*(res + 3) = ((mask << 24) >> 24) | b_octet;
  *(res + 4) = '\0';
	return (4);
}

int ctowc(wchar_t letter, char *res)
{
	int nb_bit;
  int count;

	nb_bit = count_significant_bit(letter);
	if (nb_bit <= 7)
		count = ctowc1(letter, res);
	else if (nb_bit <= 11)
		count = ctowc2(letter, res);
	else if (nb_bit <= 16)
		count = ctowc3(letter, res);
	else
		count = ctowc4(letter, res);
  return (count);
}
