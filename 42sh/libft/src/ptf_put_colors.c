/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_put_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:42:49 by jhoudan           #+#    #+#             */
/*   Updated: 2015/12/13 22:18:57 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	pick_color(char *color)
{
	if (ft_strcmp(color, "PRED") == 0)
		ft_putstr(PRED);
	else if (ft_strcmp(color, "PGREEN") == 0)
		ft_putstr(PGREEN);
	else if (ft_strcmp(color, "PYELLOW") == 0)
		ft_putstr(PYELLOW);
	else if (ft_strcmp(color, "PBLUE") == 0)
		ft_putstr(PBLUE);
	else if (ft_strcmp(color, "PMAGENTA") == 0)
		ft_putstr(PMAGENTA);
	else if (ft_strcmp(color, "PCYAN") == 0)
		ft_putstr(PCYAN);
	else if (ft_strcmp(color, "EOC") == 0)
		ft_putstr(PRESET);
	else
		return (0);
	return (1);
}

static int	pick_light_color(char *color)
{
	if (ft_strcmp(color, "PLRED") == 0)
		ft_putstr(PLRED);
	else if (ft_strcmp(color, "PLGREEN") == 0)
		ft_putstr(PLGREEN);
	else if (ft_strcmp(color, "PLYELLOW") == 0)
		ft_putstr(PLYELLOW);
	else if (ft_strcmp(color, "PLBLUE") == 0)
		ft_putstr(PLBLUE);
	else if (ft_strcmp(color, "PLMAGENTA") == 0)
		ft_putstr(PLMAGENTA);
	else if (ft_strcmp(color, "PLCYAN") == 0)
		ft_putstr(PLCYAN);
	else if (ft_strcmp(color, "EOC") == 0)
		ft_putstr(PRESET);
	else
		return (0);
	return (1);
}

int			ptf_process_colors(char *str, int *count)
{
	int		i;
	char	*ptr;
	int		result;

	i = 0;
	if (str[i] == 'P' || str[i] == 'E')
	{
		while (str[i] && str[i] != '}')
			i++;
		if (str[i])
		{
			ptr = ft_strsub(str, 0, i);
			if (ptr[1] == 'L')
				result = pick_light_color(ptr);
			else
				result = pick_color(ptr);
			ft_strdel(&ptr);
			if (result)
				return (i + 1);
		}
	}
	*count += ft_putchar('{');
	return (0);
}
