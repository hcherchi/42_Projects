/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handling2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:37:27 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 19:37:48 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*get_firstword(char *str)
{
	int		i;
	int		k;

	i = 0;
	while ((str[i] == ' ' || str[i] == '\t') && str[i])
		i++;
	if (str[i] == '\0')
		return (NULL);
	k = i;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		i++;
	return (ft_strsub(str, k, i - k));
}
