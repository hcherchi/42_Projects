/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_digit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 14:43:14 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/23 14:43:17 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	str_digit(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (j == 1)
				return (1);
			j = 1;
			i++;
		}
		if (str[i] > 57 || str[i] < 48)
			return (1);
		i++;
	}
	return (0);
}
