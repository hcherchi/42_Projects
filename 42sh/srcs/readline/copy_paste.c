/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:37:56 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/05 17:01:46 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	keyboard_copy(t_readline *r)
{
	int	i;
	int	j;

	i = r->i;
	j = i;
	while ((r->line)[j] != '\0' && (r->line)[j] != -2 && (r->line)[j] != -4)
		j++;
	r->save = ft_strsub(r->line, i, (j - i));
}

void	keyboard_cut(t_readline *r)
{
	int i;
	int j;

	i = r->i;
	while ((r->line)[r->i] != '\0' && (r->line)[r->i] !=
		-2 && (r->line)[r->i] != -4)
		keyboard_right(r);
	j = r->i;
	r->save = ft_strsub(r->line, i, (j - i));
	while ((int)(r->i) > i)
		del_char_to_str(r);
}

void	keyboard_paste(t_readline *r)
{
	int	i;

	i = 0;
	if (!(r->save))
		return ;
	while ((r->save)[i])
	{
		keyboard_print((r->save)[i], r);
		i++;
	}
}
