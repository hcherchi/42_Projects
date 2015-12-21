/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjean-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 00:07:55 by wjean-ma          #+#    #+#             */
/*   Updated: 2015/12/21 18:46:10 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/alum1.h"

int		valid_file(char *buf)
{
	int i;

	i = 0;
	if (buf == NULL)
	{
		ft_putstr("Error, invalid file\n");
		return (0);
	}
	if (buf[0] == '\n')
	{
		ft_putstr_fd("Error, invalid file\n", 2);
		return (0);
	}
	while (buf[i])
	{
		if (buf[i] == '\n' && buf[i + 1] == '\n')
		{
			ft_putstr_fd("Error, invalid file\n", 2);
			return (0);
		}
		if (!check_digit(buf, i))
			return (0);
		i++;
	}
	return (1);
}

int		check_digit(char *buf, int i)
{
	int c;

	c = 0;
	while (buf[i] != '\n')
	{
		if (ft_isdigit(buf[i]))
		{
			if (c < 4 || !ft_strequ(buf, "10000"))
				i++;
			else
			{
				ft_putstr_fd("Error, invalid file\n", 2);
				return (0);
			}
			c++;
		}
		else
		{
			ft_putstr_fd("Error, invalid file\n", 2);
			return (0);
		}
	}
	return (1);
}
