/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjean-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 00:12:11 by wjean-ma          #+#    #+#             */
/*   Updated: 2015/12/21 00:41:25 by wjean-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	remove_al(t_line **lines, int nb)
{
	if ((*lines)->nb - nb > 0)
		(*lines)->nb -= nb;
	else if ((*lines)->nb == nb)
		delone(lines);
}

void	delone(t_line **alines)
{
	t_line *todel;

	todel = *alines;
	*alines = (*alines)->next;
	free(todel);
}
