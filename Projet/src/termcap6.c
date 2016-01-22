/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:51:04 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 19:51:13 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	keyboard_copy(char *line, char **save, size_t position)
{
	*save = ft_strdup(line + position);
}

void	keyboard_cut(char **line, char **save, size_t *position)
{
	*save = ft_strdup(*line + *position);
	keyboard_end(line, position);
	while (*position > (ft_strlen(*line) - ft_strlen(*save)))
	{
		tputs(tgetstr("le", NULL), 1, ft_outc);
		tputs(tgetstr("dc", NULL), 1, ft_outc);
		(*position)--;
	}
	while (ft_strlen(*line) > *position)
		*line = del_char_to_str(*line, (*position));
}

void	keyboard_paste(char *save, char **line, size_t *position)
{
	int i;

	i = 0;
	while (save[i])
	{
		*line = add_char_to_str(*line, save[i], ++(*position));
		ft_putchar(save[i]);
		i++;
	}
}
