/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:46:04 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 19:47:26 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	keyboard_up(char **line, size_t *position, t_line **historic)
{
	if ((*historic)->next)
	{
		while (*position > 0)
			keyboard_delete(line, position);
		*historic = (*historic)->next;
		*line = ft_strdup((*historic)->line);
		*position = ft_strlen(*line);
		ft_putstr(*line);
	}
}

void	keyboard_down(char **line, size_t *position, t_line **historic)
{
	if ((*historic)->prev)
	{
		while (*position > 0)
			keyboard_delete(line, position);
		*historic = (*historic)->prev;
		if ((*historic)->line)
			*line = ft_strdup((*historic)->line);
		*position = ft_strlen(*line);
		ft_putstr(*line);
	}
}

void	list_begin(t_line **historic)
{
	while ((*historic)->prev != NULL)
	{
		(*historic) = (*historic)->prev;
	}
}

void	keyboard_ctrl_d(char **line, size_t *position)
{
	if (**line == '\0')
	{
		ft_putchar('\n');
		default_terminal_mode();
		exit(0);
	}
	if (*position != ft_strlen(*line) + 1)
	{
		tputs(tgetstr("dc", NULL), 1, ft_outc);
		*line = del_char_to_str(*line, (*position));
	}
}

char	*ft_lstjoin(t_line *lst)
{
	char	*final_line;

	final_line = NULL;
	while (lst)
	{
		lst->line = del_backslash(lst->line);
		final_line = ft_strjoin(final_line, lst->line);
		lst = lst->next;
	}
	return (final_line);
}
