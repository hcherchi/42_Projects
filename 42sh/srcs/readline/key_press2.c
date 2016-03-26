/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:37:35 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/19 15:00:41 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <ftsh.h>

void	keyboard_ctrld(t_readline *r)
{
	if (r->line[r->i] == '\0')
	{
		go_to_end(r);
		ft_putchar('\n');
		g_shell->running = 0;
	}
}

void	keyboard_end(t_readline *r)
{
	while ((r->line)[r->i] != '\0' && (r->line)[r->i] !=
		-2 && (r->line)[r->i] != -4)
		keyboard_right(r);
}

void	keyboard_print(long key, t_readline *r)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	i = r->i;
	j = r->i;
	k = r->i;
	while (i > 0 && (r->line)[i - 1] != -2 && (r->line)[i - 1] != -4)
		i--;
	while ((r->line)[j] != -2 && (r->line)[j] != -4 && (r->line)[j] != '\0')
		j++;
	if ((j - i + 9) >= r->width)
	{
		tmp = ft_strdup(r->line);
		clean_line(r);
		r->line = tmp;
		r->i = k;
		r->line = add_char_without_print(r, key);
		r->i = 0;
		replace_line(r);
	}
	else
		r->line = add_char_to_str(r, key);
}

void	keyboard_left_word(t_readline *r)
{
	if (r->i > 0 && (r->line)[r->i - 1] != -2 && (r->line)[r->i] !=
		' ' && (r->line)[r->i - 1] != -4)
	{
		tputs(tgetstr("le", NULL), 1, ft_outc);
		(r->i)--;
	}
	while (r->i > 0 && r->line[(r->i)] == ' ' && r->line[r->i - 1] !=
		-2 && (r->line)[r->i - 1] != -4)
	{
		tputs(tgetstr("le", NULL), 1, ft_outc);
		(r->i)--;
	}
	while (r->i > 0 && r->line[r->i - 1] != ' ' && r->line[r->i - 1] !=
		-2 && (r->line)[r->i - 1] != -4)
	{
		tputs(tgetstr("le", NULL), 1, ft_outc);
		(r->i)--;
	}
}

void	keyboard_right_word(t_readline *r)
{
	while (r->line[r->i] != ' ' && r->i < ft_strlen(r->line) && r->line[r->i] !=
		-2 && (r->line)[r->i] != -4)
	{
		tputs(tgetstr("nd", NULL), 1, ft_outc);
		(r->i)++;
	}
	while (r->line[r->i] == ' ' && r->i < ft_strlen(r->line) && r->line[r->i] !=
		-2 && (r->line)[r->i] != -4)
	{
		tputs(tgetstr("nd", NULL), 1, ft_outc);
		(r->i)++;
	}
}
