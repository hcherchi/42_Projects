/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:03:10 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/14 18:27:36 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int ac, char **av)
{
	int	i;
	int	j;
	char	*str;
	int	count;
	int	v;

	v = 0;
	count= 0;
	i = 0;
	j = 1;
	while (av[j] && j < ac)
	{
		count = count + ft_strlen(av[j]);
		j++;
	}
	j = 1;
	str = malloc(sizeof(char *) * count);
	if (ac == 1)
		ft_ls(".", "");
	else if (ac >= 2)
	{	
		while (j < ac)
		{
			i = 0;
			while (av[j][i] != '\0')
			{
				if (av[j][i] == '-' && i == 0)
					i++;
				else if (av[j][i] != '-' && i == 0)
					while (av[j][i])
					{
						ft_error(1, av[j][i]);
						i++;
						exit(1);
					}
				if (av[j][i] == 'l' || av[j][i] == 'R' || av[j][i] == 'a' 
						 || av[j][i] == 'r' || av[j][i] == 't')
					str[v] = av[j][i];
				else
					ft_error(0, av[j][i]);
				i++;
				v++;
			}
			j++;
		}
		str[v] = '\0';
		ft_union(str);
		ft_ls(".", str);
		free(str);
	}
	return (0);
}
