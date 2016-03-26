/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_proper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:38:16 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/23 14:11:08 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

char	*line_proper(char **str)
{
	char	*tmp;
	int		i;
	int		j;

	if (!str || !(*str))
		return (NULL);
	i = 0;
	j = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(*str) + 1));
	while ((*str)[j] != '\0')
	{
		if ((*str)[j] == -4)
			tmp[i++] = '\n';
		else if ((*str)[j] > 31 && (*str)[j] < 127)
		{
			tmp[i] = (*str)[j];
			i++;
		}
		j++;
	}
	tmp[i] = '\0';
	ft_strdel(&(*str));
	return (tmp);
}
