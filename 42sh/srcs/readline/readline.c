/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:39:34 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/05 19:21:52 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include <ftsh.h>
#include <executor.h>

t_readline	*init_readline(char *prompt)
{
	t_readline	*r;

	r = malloc(sizeof(*r));
	r->i = 0;
	r->prompt = prompt;
	r->line = (char *)malloc(sizeof(char));
	(r->line)[0] = '\0';
	r->save = NULL;
	r->line_before = NULL;
	r->i = 0;
	add_his(new_his_node(1, ft_strdup("\0")));
	r->current = g_shell->history->tail;
	return (r);
}

void		delete_reader(void)
{
	if (!g_shell->history->head || !g_shell->reader->line)
		return ;
	while (g_shell->history->tail->next)
		g_shell->history->tail = g_shell->history->tail->next;
	if (g_shell->history->tail->index == -1)
		return ;
	if (g_shell->reader->line[0] == '\0')
	{
		pop_his_node(g_shell->history->tail);
		return ;
	}
}

static long	readline_completion(t_readline *r)
{
	long key;

	if (r->comp == 1)
	{
		ft_printf("\n{PYELLOW}%s{EOC}", r->prompt);
		print_line(r);
		r->comp = 0;
	}
	key = 0;
	read(0, &key, sizeof(long));
	return (key);
}

static void	ft_readline_bis(t_readline *r)
{
	long key;

	while (1)
	{
		key = readline_completion(r);
		if (key == 10)
		{
			if (return_line(r) == 1)
				continue ;
			else
			{
				go_to_end(r);
				ft_putchar('\n');
				break ;
			}
		}
		if (is_special_key(key))
		{
			controller_key(r, key);
			if (key == 4)
				break ;
		}
		else if (key < 127 && key > 31)
			keyboard_print(key, r);
	}
}

char		*ft_readline(t_readline *r)
{
	size_t			h;
	struct winsize	sz;

	ioctl(0, TIOCGWINSZ, &sz);
	r->width = sz.ws_col;
	r->comp = 0;
	h = 0;
	if (raw_term_mode() != 0)
		return (NULL);
	signal(SIGWINCH, resize);
	ft_printf("{PYELLOW}%s{EOC}", r->prompt);
	ft_readline_bis(r);
	default_terminal_mode();
	if (r->comp == 1)
		return (NULL);
	pop_his_node(g_shell->history->tail);
	r->line_before = ft_strdup(r->line);
	return (r->line);
}
