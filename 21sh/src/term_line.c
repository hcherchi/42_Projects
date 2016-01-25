/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:39:18 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 21:39:57 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_test(char **myenv, size_t len_prompt)
{
	t_line		*historic;
	t_tools		*t;
	char		*save;
	t_line		*l_line;

	t = malloc(sizeof(*t));
	t->buf = ft_strnew(7);
	t->pos = 0;
	t->len_prompt = len_prompt;
	raw_term_mode();
	l_line = NULL;
	add_endline(&l_line, "");
	historic = malloc(sizeof(*historic));
	historic->next = NULL;
	historic->prev = NULL;
	historic->line = NULL;
	while (read(0, t->buf, 7) > 0)
	{
		if ((t->buf)[0] == 5 && (t->buf)[1] == '\0')
			keyboard_ctrlc(&(l_line->line), &(t->pos), myenv);
		else if ((t->buf)[0] == 10 || (t->buf)[0] == 13)
			enter(t, &myenv, &historic, &l_line);
		mainloop(t, &l_line);
		m2(t, &l_line, &historic, &save);
	}
}

void	mainloop(t_tools *t, t_line **l_line)
{
	if ((t->buf)[0] == 127)
		keyboard_delete(&((*l_line)->line), &(t->pos));
	else if (ft_isprint(t->buf[0]))
		keyboard_print(&(t->buf), &((*l_line)->line), &(t->pos));
	else if ((t->buf)[0] == 27 && (t->buf)[1] == 91 && (t->buf)[2] == 67)
		keyboard_right(&((*l_line)->line), &(t->pos));
	else if ((t->buf)[0] == 27 && (t->buf)[1] == 91 && (t->buf)[2] == 68)
		keyboard_left(&(t->pos));
	else if ((t->buf)[0] == 27 && (t->buf)[1] == 91 && (t->buf)[2] == 72)
		keyboard_home(&(t->pos));
	else if ((t->buf)[0] == 27 && (t->buf)[1] == 91 && (t->buf)[2] == 70)
		keyboard_end(&((*l_line)->line), &(t->pos));
	else if ((t->buf)[0] == 27 && (t->buf)[1] == 91 && (t->buf)[2] == 49 \
		&& (t->buf)[3] == 59 && (t->buf)[4] == 50 && (t->buf)[5] == 68)
		keyboard_left_word(&((*l_line)->line), &(t->pos));
	else if ((t->buf)[0] == 8 && (t->buf)[1] == '\0')
		keyboard_line_up(l_line, &(t->pos), t->len_prompt);
	else if ((t->buf)[0] == 14 && (t->buf)[1] == '\0')
		keyboard_line_down(l_line, &(t->pos), t->len_prompt);
}

void	m2(t_tools *t, t_line **l_line, t_line **hist, char **save)
{
	if ((t->buf)[0] == 27 && (t->buf)[1] == 91 && (t->buf)[2] == 49 \
		&& (t->buf)[3] == 59 && (t->buf)[4] == 50 && (t->buf)[5] == 67)
		keyboard_right_word(&((*l_line)->line), &(t->pos));
	else if ((t->buf)[0] == 27 && (t->buf)[1] == 91 && (t->buf)[2] == 65)
		keyboard_up(&((*l_line)->line), &(t->pos), hist);
	else if ((t->buf)[0] == 27 && (t->buf)[1] == 91 && (t->buf)[2] == 'B')
		keyboard_down(&((*l_line)->line), &(t->pos), hist);
	else if ((t->buf)[0] == 25 && (t->buf)[1] == '\0')
		keyboard_copy((*l_line)->line, save, (t->pos));
	else if ((t->buf)[0] == 20 && (t->buf)[1] == '\0')
		keyboard_cut(&((*l_line)->line), save, &(t->pos));
	else if ((t->buf)[0] == 16 && (t->buf)[1] == '\0')
		keyboard_paste(*save, &((*l_line)->line), &(t->pos));
	else if ((t->buf)[0] == 4 && (t->buf)[1] == '\0')
		keyboard_ctrl_d(&((*l_line)->line), &(t->pos));
	ft_bzero(t->buf, 7);
}
