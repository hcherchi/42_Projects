/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 18:29:51 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/24 12:44:00 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>
#include <ftsh.h>

int		detect_identical_lines(void)
{
	if (g_shell->history->tail && g_shell->history->tail->cmd)
	{
		if (!ft_strcmp(g_shell->history->tail->cmd,
			g_shell->reader->line_before))
			return (1);
	}
	return (0);
}

void	up_arrow(t_readline *r)
{
	if (r->current->next == NULL)
	{
		ft_strdel(&(r->current->cmd));
		r->current->cmd = ft_strdup(r->line);
	}
	if (r->current->prev != NULL)
		r->current = r->current->prev;
	else
		return ;
	if (r->current && r->current->index == -1)
	{
		if (!r->current->prev)
			return ;
		r->current = r->current->prev;
	}
	clean_line(r);
	ft_strdel(&(r->line));
	r->line = ft_strdup(r->current->cmd);
	replace_line(r);
}

void	down_arrow(t_readline *r)
{
	if (r->current->next != NULL)
		r->current = r->current->next;
	else
		return ;
	if (r->current && r->current->index == -1 &&
			r->current->next)
		r->current = r->current->next;
	clean_line(r);
	ft_strdel(&(r->line));
	r->line = ft_strdup(r->current->cmd);
	replace_line(r);
}
