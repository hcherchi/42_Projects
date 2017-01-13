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
