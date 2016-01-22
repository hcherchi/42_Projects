/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:43:22 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 21:48:54 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	enter(t_tools *t, char ***env, t_line **his, t_line **l_line)
{
	static int	ret;

	ret = find_open_close((*l_line)->line, ret);
	ft_putchar('\n');
	if ((*l_line)->line[ft_strlen((*l_line)->line) - 1] != '\\' && ret == 1)
	{
		send(t, env, his, l_line);
		ret = 0;
	}
	else
	{
		add_endline(l_line, "");
		t->pos = 0;
		*l_line = (*l_line)->next;
	}
}

void	send(t_tools *t, char ***env, t_line **hist, t_line **l_line)
{
	char		*final_line;
	char		*home;
	char		*paths;

	list_begin(l_line);
	final_line = ft_lstjoin(*l_line);
	if (ft_strcmp(ft_strtrim(final_line), ""))
	{
		paths = get_elem(*env, "PATH=");
		default_terminal_mode();
		set_commands(final_line, paths, env);
		raw_term_mode();
		list_begin(hist);
		add_line(hist, final_line);
	}
	t->pos = 0;
	home = get_elem(*env, "PWD=");
	prompt(home);
	t->len_prompt = ft_strlen(home) + 2;
	*l_line = NULL;
	add_endline(l_line, "");
}

int		find_complement(int c)
{
	if (c == '{')
		return ('}');
	else if (c == '[')
		return (']');
	else if (c == '(')
		return (')');
	return (c);
}

int		find_open_close(char *line, int ret)
{
	int			i;

	i = 0;
	while (line[i] && ret == 0)
	{
		if (line[i] == '{' || line[i] == '(' || line[i] == '['
			|| line[i] == '\"' || line[i] == '\'' || line[i] == '`')
			ret = line[i];
		i++;
	}
	if (ret == 0)
		return (1);
	ret = find_complement(ret);
	while (line[i])
	{
		if (line[i] == ret)
		{
			i++;
			return (find_open_close(line + i, 0));
		}
		i++;
	}
	return (ret);
}

void	keyboard_home(size_t *position)
{
	while ((*position) > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_outc);
		(*position)--;
	}
}
