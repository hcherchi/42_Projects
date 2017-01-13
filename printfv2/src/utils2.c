#include "ft_printf.h"

char *ft_strnew(char c, int n)
{
	char *str;
	int i;

	i = 0;
	str = malloc(sizeof(char) * (n + 1));
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char *ft_strcat(char *dest, char *src)
{
	int i;
	int j;
	char *newstr;

	j = 0;
	i = 0;
	newstr = malloc(sizeof(char) * (ft_strlen(src) + ft_strlen(dest)) + 1);
	while (dest[i])
	{
		newstr[i] = dest[i];
		i++;
	}
	while (src[j])
	{
		newstr[i] = src[j];
		j++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

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

int	ft_atoi(const char *str)
{
	int				number;
	int				neg;

	number = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
	|| *str == '\f' || *str == '\r')
		str++;
	if (!str)
		return (0);
	neg = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = 1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		number = (number * 10) + ((int)*str - 48);
		str++;
	}
	if (neg == 1)
		number = -number;
	return (number);
}
