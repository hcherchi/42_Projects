/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:14:07 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/18 19:14:12 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			escape_char_in_quote(char *str)
{
	int		i;
	char	*ch;
	char	*rep;

	i = 0;
	rep = "\'\"\n\t\b\f\v\0\r";
	while (str[i])
	{
		if (str[i] == '\\' && (ch = ft_strchr("\'\"ntbfv0r", str[i + 1])))
		{
			str[i] = rep[ft_get_index("\'\"ntbfv0r", ch[0])];
			ft_memmove(str + i + 1, str + i + 2, ft_strlen(str + i + 2) + 1);
		}
		i++;
	}
	return (1);
}

int			escape_char_without_quote(char *str)
{
	int		i;
	char	*ch;
	char	*rep;

	i = 0;
	rep = "\'\"\\ ";
	while (str[i])
	{
		if (str[i] == '\\' && (ch = ft_strchr(rep, str[i + 1])) != NULL)
		{
			str[i] = rep[ft_get_index(rep, ch[0])];
			ft_memmove(str + i + 1, str + i + 2, ft_strlen(str + i + 2) + 1);
		}
		else if (str[i] == '\\')
			ft_memmove(str + i, str + i + 1, ft_strlen(str + i + 1) + 1);
		i++;
	}
	return (1);
}
