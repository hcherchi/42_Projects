/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:29:46 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/19 21:01:53 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

char	*set_line(t_read_opt *opt)
{
	struct termios	term;
	char			*line;

	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON);
	if (opt->s)
		term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &term);
	if (opt->p)
		ft_putstr(opt->p);
	line = get_line(opt);
	term.c_lflag |= (ECHO);
	return (line);
}

char	*get_line(t_read_opt *opt)
{
	int		i;
	char	*line;
	char	letter;

	i = 1;
	line = malloc(sizeof(char) * 1);
	line[0] = '\0';
	while (i != opt->n + 1)
	{
		letter = 'p';
		read(0, &letter, 1);
		if (letter == '\\' && !opt->r)
		{
			i++;
			continue ;
		}
		if (letter == opt->d)
			break ;
		if (letter == '\n' && opt->p)
			ft_putstr(opt->p);
		line = add_char(line, letter);
		i++;
	}
	return (line);
}

void	array_mode(t_read_opt *opt, char *line)
{
	int		i;
	char	**split;
	char	*value;

	value = malloc(sizeof(char) * 2);
	*value = '(';
	*(value + 1) = '\0';
	i = 0;
	split = ft_strsplit(line, ' ');
	while (i < tabsize(split))
	{
		value = add_char(value, '[');
		value = add_str(value, ft_itoa(i));
		value = ft_strjoin(value, "]=\"");
		value = add_str(value, ft_strdup(split[i]));
		value = add_char(value, '\"');
		if (i != tabsize(split) - 1)
			value = add_char(value, ' ');
		free(split[i]);
		i++;
	}
	value = add_char(value, ')');
	set_local_var(opt->a, value, 1);
	free(value);
	free(split);
}

void	simple_mode(t_read_opt *opt, char *line)
{
	char **split;
	char **save;

	split = ft_strnsplit(line, ' ', tabsize(opt->name));
	save = split;
	if (opt->name)
	{
		while (*(opt->name) && *split)
		{
			set_local_var(*(opt->name), *split, 1);
			(opt->name)++;
			free(*split);
			split++;
		}
	}
	free(save);
}

int		read_builtin(t_node_cmd *node)
{
	t_read_opt	*opt;
	char		*line;

	opt = malloc(sizeof(*opt));
	fill_read_opt(opt, node);
	if (opt->error != 0)
	{
		ft_putstr("read: usage: read [-rs] ");
		ft_putstr("[-p prompt] [-a array] [-n nchars] [-d delim] ");
		ft_putstr("[name ...]");
		return (0);
	}
	line = set_line(opt);
	if (opt->a)
		array_mode(opt, line);
	else
		simple_mode(opt, line);
	return (1);
}
