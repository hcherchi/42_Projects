/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjean-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 00:10:15 by wjean-ma          #+#    #+#             */
/*   Updated: 2015/12/21 18:23:55 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		al_count(t_line *lines)
{
	int nb;

	nb = 0;
	while (lines)
	{
		nb += lines->nb;
		lines = lines->next;
	}
	return (nb);
}

int		nb_lines(char *buf)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			c++;
		i++;
	}
	return (c);
}
