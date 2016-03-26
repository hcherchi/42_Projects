/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 20:37:44 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/15 13:06:59 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realloc(char *str, int n)
{
	char	*tmp;

	tmp = str;
	str = ft_strnew(ft_strlen(tmp) + n + 1);
	if (str)
	{
		ft_strcpy(str, tmp);
		free(tmp);
		return (str);
	}
	else
		return (tmp);
}
