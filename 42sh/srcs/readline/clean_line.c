/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:22:55 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/14 11:39:07 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

void	go_to_end(t_readline *r)
{
	while ((r->line)[r->i] != '\0')
	{
		while ((r->line)[r->i] != -2 && (r->line)[r->i] !=
			'\0' && (r->line)[r->i] != -4)
			(r->i)++;
		if ((r->line)[r->i] == -2 || (r->line)[r->i] == -4)
		{
			(r->i)++;
			tputs(tgoto(tgetstr("ch", NULL), 0, 0), 1, ft_outc);
			tputs(tgetstr("do", NULL), 0, ft_outc);
		}
	}
	r->i = ft_strlen(r->line);
}

void	clean_line(t_readline *r)
{
	go_to_end(r);
	while (r->i != 0)
	{
		while ((r->line)[r->i - 1] != -2 && r->i !=
			0 && (r->line)[r->i - 1] != -4)
			(r->i)--;
		tputs(tgoto(tgetstr("ch", NULL), 0, 0), 1, ft_outc);
		if ((r->line)[r->i - 1] == -2 || (r->line)[r->i - 1] == -4)
		{
			if (r->i == 1 || (r->i > 1 && ((r->line)[r->i - 2] == -2 ||
				(r->line)[r->i - 2] == -4)))
				(r->i)--;
			else
				(r->i) -= 2;
			tputs(tgetstr("up", NULL), 0, ft_outc);
		}
	}
	ft_strdel(&(r->line));
	r->line = ft_strdup("\0");
	tputs(tgoto(tgetstr("ch", NULL), 0, 0), 1, ft_outc);
	tputs(tgetstr("cd", NULL), 0, ft_outc);
	ft_printf("{PYELLOW}%s{EOC}", r->prompt);
}
