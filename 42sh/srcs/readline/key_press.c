/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:37:21 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/18 16:34:32 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

void	keyboard_left(t_readline *r)
{
	if (r->i > 0 && ((r->line)[r->i - 1] != -2 && (r->line)[r->i - 1] != -4))
	{
		tputs(tgetstr("le", NULL), 1, ft_outc);
		(r->i)--;
	}
}

void	keyboard_right(t_readline *r)
{
	if (r->i < ft_strlen(r->line) && ((r->line)[r->i] != -2) &&
	(r->line)[r->i] != -4)
	{
		tputs(tgetstr("nd", NULL), 1, ft_outc);
		(r->i)++;
	}
}

void	keyboard_delete(t_readline *r)
{
	if (r->i > 0 && (r->line)[r->i - 1] != -2 && (r->line)[r->i - 1] != -4)
		del_char_to_str(r);
}

void	keyboard_ctrlc(t_readline *r)
{
	go_to_end(r);
	ft_putchar('\n');
	free(r->line);
	r->line = (char *)malloc(sizeof(char));
	(r->line)[0] = '\0';
	r->i = 0;
	ft_printf("{PYELLOW}%s{EOC}", r->prompt);
}

void	keyboard_home(t_readline *r)
{
	while (r->i > 0 && (r->line)[r->i - 1] != -2 && (r->line)[r->i - 1] != -4)
		keyboard_left(r);
}
