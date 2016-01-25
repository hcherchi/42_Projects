/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:47:46 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 21:07:29 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	keyboard_line_down(t_line **l_line, size_t *position, int len_prompt)
{
	if ((*l_line)->next)
	{
		if (!(*l_line)->prev)
		{
			*position = len_prompt + *position + 1;
		}
		if (*position >= ft_strlen((*l_line)->next->line))
		{
			tputs(tgetstr("do", NULL), 1, ft_outc);
			*l_line = (*l_line)->next;
			*position = 0;
			while (*position < ft_strlen((*l_line)->line))
			{
				tputs(tgetstr("nd", NULL), 1, ft_outc);
				(*position)++;
			}
		}
		else
			else_down(l_line, position);
	}
}

void	else_down(t_line **l_line, size_t *position)
{
	size_t		tmp;

	tmp = *position;
	tputs(tgetstr("do", NULL), 1, ft_outc);
	*position = 0;
	*l_line = (*l_line)->next;
	while (*position < tmp)
	{
		tputs(tgetstr("nd", NULL), 1, ft_outc);
		(*position)++;
	}
}

void	keyboard_line_up(t_line **l_line, size_t *position, int len_prompt)
{
	if ((*l_line)->prev)
	{
		if (!((*l_line)->prev->prev))
			prompt_up(l_line, position, len_prompt);
		else if (*position <= ft_strlen((*l_line)->prev->line))
		{
			tputs(tgetstr("up", NULL), 1, ft_outc);
			*l_line = (*l_line)->prev;
		}
		else
		{
			tputs(tgetstr("up", NULL), 1, ft_outc);
			*l_line = (*l_line)->prev;
			while (*position > ft_strlen((*l_line)->line))
			{
				tputs(tgetstr("le", NULL), 1, ft_outc);
				(*position)--;
			}
		}
	}
}

void	prompt_up(t_line **l_line, size_t *position, int len_prompt)
{
	if (*position <= (size_t)len_prompt)
		smaller_than_prompt(l_line, position, len_prompt);
	else if (*position - len_prompt <= ft_strlen((*l_line)->prev->line) + 1)
	{
		tputs(tgetstr("up", NULL), 1, ft_outc);
		*l_line = (*l_line)->prev;
		*position -= len_prompt + 1;
	}
	else
	{
		tputs(tgetstr("up", NULL), 1, ft_outc);
		*l_line = (*l_line)->prev;
		*position -= len_prompt + 1;
		while (*position > ft_strlen((*l_line)->line))
		{
			tputs(tgetstr("le", NULL), 1, ft_outc);
			(*position)--;
		}
	}
}

void	smaller_than_prompt(t_line **l_line, size_t *position, int len_prompt)
{
	tputs(tgetstr("up", NULL), 1, ft_outc);
	*l_line = (*l_line)->prev;
	while (*position < (size_t)len_prompt + 1)
	{
		tputs(tgetstr("nd", NULL), 1, ft_outc);
		(*position)++;
	}
	*position = 0;
}
