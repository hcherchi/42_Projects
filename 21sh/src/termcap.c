/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:42:36 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 19:43:10 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	keyboard_ctrlc(char **line, size_t *position, char **env)
{
	char	*home;

	ft_putchar('\n');
	free(*line);
	*line = ft_strnew(0);
	*position = 0;
	home = get_elem(env, "PWD=");
	prompt(home);
}

void	keyboard_left(size_t *position)
{
	if (*position > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_outc);
		(*position)--;
	}
}

void	keyboard_right(char **line, size_t *position)
{
	if (*position < ft_strlen(*line))
	{
		tputs(tgetstr("nd", NULL), 1, ft_outc);
		(*position)++;
	}
}

void	keyboard_print(char **buffer, char **line, size_t *position)
{
	*line = add_char_to_str(*line, *buffer[0], (*position)++);
	ft_putstr((*buffer));
}

void	keyboard_delete(char **line, size_t *position)
{
	if (*position > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_outc);
		tputs(tgetstr("dc", NULL), 1, ft_outc);
		*line = del_char_to_str(*line, --(*position));
	}
}
