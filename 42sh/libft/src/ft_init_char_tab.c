/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_char_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 20:30:12 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/09 20:34:29 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_init_char_tab(int size)
{
	char	**ptr;
	int		i;

	ptr = (char**)malloc(sizeof(char*) * (size + 1));
	if (!ptr)
		return (ptr);
	i = -1;
	while (++i <= size)
		ptr[i] = NULL;
	return (ptr);
}
