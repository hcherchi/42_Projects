/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:39:18 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 19:42:20 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_test(char **myenv, int len_prompt)
{
	char		*buffer;
	t_line		*historic;
	size_t		position;
	char		*save;
	t_line		*l_line;

	raw_term_mode();
	position = 0;
	buffer = ft_strnew(7);
	l_line = NULL;
	add_endline(&l_line, "");
	historic = malloc(sizeof(*historic));
	historic->next = NULL;
	historic->prev = NULL;
	historic->line = NULL;
	while (read(0, buffer, 7) > 0)
	{
		mainloop(buffer, &position, &l_line, len_prompt);
		m2(buffer, &position, &l_line, &historic, &save);
		if (buffer[0] == 5 && buffer[1] == '\0')
			keyboard_ctrlc(&(l_line->line), &position, myenv);
		else if (buffer[0] == 10 || buffer[0] == 13)
			enter(&position, &myenv, &historic, &l_line, &len_prompt);
		ft_bzero(buffer, 7);
	}
}

void	mainloop(char *buffer, size_t *pos, t_line **l_line, size_t len_prompt)
{
	if (buffer[0] == 127)
		keyboard_delete(&((*l_line)->line), pos);
	else if (ft_isprint(buffer[0]))
		keyboard_print(&buffer, &((*l_line)->line), pos);
	else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 67)
		keyboard_right(&((*l_line)->line), pos);
	else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 68)
		keyboard_left(pos);
	else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 72)
		keyboard_home(pos);
	else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 70)
		keyboard_end(&((*l_line)->line), pos);
	else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 49 \
		&& buffer[3] == 59 && buffer[4] == 50 && buffer[5] == 68)
		keyboard_left_word(&((*l_line)->line), pos);
	else if (buffer[0] == 8 && buffer[1] == '\0')
		keyboard_line_up(l_line, pos, len_prompt);
	else if (buffer[0] == 14 && buffer[1] == '\0')
		keyboard_line_down(l_line, pos, len_prompt);
}

void	m2(char *buf, size_t *pos, t_line **l_line, t_line **hist, char **save)
{
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 \
		&& buf[3] == 59 && buf[4] == 50 && buf[5] == 67)
		keyboard_right_word(&((*l_line)->line), pos);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
		keyboard_up(&((*l_line)->line), pos, hist);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 'B')
		keyboard_down(&((*l_line)->line), pos, hist);
	else if (buf[0] == 25 && buf[1] == '\0')
		keyboard_copy((*l_line)->line, save, *pos);
	else if (buf[0] == 20 && buf[1] == '\0')
		keyboard_cut(&((*l_line)->line), save, pos);
	else if (buf[0] == 16 && buf[1] == '\0')
		keyboard_paste(*save, &((*l_line)->line), pos);
	else if (buf[0] == 4 && buf[1] == '\0')
		keyboard_ctrl_d(&((*l_line)->line), pos);
}
