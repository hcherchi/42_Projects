/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:38:36 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/17 13:03:39 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

static void	print_quote(char c)
{
	if (c == 0)
		ft_putstr("\nn_slash> ");
	if (c == 34)
		ft_putstr("\nd_quote> ");
	if (c == 39)
		ft_putstr("\ns_quote> ");
	if (c == 96)
		ft_putstr("\nb_quote> ");
	if (c == '{')
		ft_putstr("\na_ccola> ");
	if (c == '[')
		ft_putstr("\nop_hook> ");
	if (c == '(')
		ft_putstr("\nparenth> ");
}

int			return_line(t_readline *r)
{
	char c;

	if ((c = quotes(r)) != 0 || (ft_strlen(r->line) > 0 &&
		(r->line)[ft_strlen(r->line) - 1] == '\\'))
	{
		if ((c == 0 && only_b(r)) || (c == 0 && count_backslash(r) == 0))
			return (0);
		go_to_end(r);
		print_quote(c);
		if ((r->line)[ft_strlen(r->line) - 1] == '\\')
			(r->line)[ft_strlen(r->line) - 1] = -2;
		else
		{
			if (c == 34 || c == 39)
				add_char_without_print(r, -4);
			else
				add_char_without_print(r, -2);
		}
		r->i = ft_strlen(r->line);
		return (1);
	}
	else
		return (0);
}

static void	go_up_bis(t_readline *r, int j, int h)
{
	while (r->i != 0 && (r->line)[r->i - 1] != -2 && (r->line)[r->i - 1] != -4)
		(r->i)--;
	if (r->i == 0)
	{
		while (h++ < (int)ft_strlen(r->prompt))
			tputs(tgetstr("nd", NULL), 0, ft_outc);
		h = 0;
	}
	else
		while (h++ < 9)
			tputs(tgetstr("nd", NULL), 0, ft_outc);
	h = 0;
	while (h++ < j && (r->line)[r->i] != -2 && (r->line)[r->i] !=
		-4 && (r->line)[r->i] != '\0')
		keyboard_right(r);
}

void		go_up(t_readline *r)
{
	int j;
	int h;

	j = 0;
	h = 0;
	while ((r->line)[r->i - 1] != -2 && r->i !=
		0 && (r->line)[r->i - 1] != -4)
	{
		keyboard_left(r);
		j++;
	}
	if (r->i == 0)
		return ;
	else
	{
		(r->i) = ((r->i == 1) || ((r->i) > 1 && ((r->line)[r->i - 2] == -2 ||
			(r->line)[r->i - 2] == -4))) ? (r->i) - 1 : (r->i) - 2;
	}
	tputs(tgoto(tgetstr("ch", NULL), 0, 0), 1, ft_outc);
	tputs(tgetstr("up", NULL), 0, ft_outc);
	go_up_bis(r, j, h);
}

void		go_down(t_readline *r)
{
	int j;
	int h;

	j = 0;
	h = 0;
	if (last_line(r) == 1)
		return ;
	while ((r->line)[r->i - 1] != -2 && r->i != 0 && (r->line)[r->i - 1] != -4)
		if (j++ || 1)
			keyboard_left(r);
	while ((r->line)[r->i] != -2 && (r->line)[r->i] !=
		'\0' && (r->line)[r->i] != -4)
		(r->i)++;
	if ((r->line)[r->i] == '\0')
		return ;
	else
		(r->i)++;
	tputs(tgoto(tgetstr("ch", NULL), 0, 0), 1, ft_outc);
	tputs(tgetstr("do", NULL), 0, ft_outc);
	while (h++ < 9)
		tputs(tgetstr("nd", NULL), 0, ft_outc);
	h = 0;
	while (h++ < j && (r->line)[r->i] != -2 && (r->line)[r->i] !=
		'\0' && (r->line)[r->i] != -4)
		keyboard_right(r);
}
