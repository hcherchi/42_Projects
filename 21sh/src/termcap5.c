/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:50:45 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 19:50:53 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	keyboard_end(char **line, size_t *position)
{
	while (*position < ft_strlen(*line))
	{
		tputs(tgetstr("nd", NULL), 1, ft_outc);
		(*position)++;
	}
}

void	keyboard_left_word(char **line, size_t *position)
{
	int		ok;

	ok = 0;
	if ((*position) > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_outc);
		(*position)--;
	}
	while ((*position) > 0 && (*line)[*position] == ' ')
	{
		tputs(tgetstr("le", NULL), 1, ft_outc);
		(*position)--;
	}
	while ((*position) > 0 && (*line)[*position] != ' ')
	{
		tputs(tgetstr("le", NULL), 1, ft_outc);
		(*position)--;
		ok = 1;
	}
	if ((*position) > 0 && ok == 1)
	{
		tputs(tgetstr("nd", NULL), 1, ft_outc);
		(*position)++;
	}
}

void	keyboard_right_word(char **line, size_t *position)
{
	while ((*line)[*position] != ' ' && *position < ft_strlen(*line))
	{
		tputs(tgetstr("nd", NULL), 1, ft_outc);
		(*position)++;
	}
	if ((*line)[*position] == ' ' && *position < ft_strlen(*line))
	{
		tputs(tgetstr("nd", NULL), 1, ft_outc);
		(*position)++;
	}
}
