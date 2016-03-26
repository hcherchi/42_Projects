/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_controller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:11:28 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/07 11:05:05 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <executor.h>
#include <libft.h>

static char	*insert_mark(char *src, char *mark)
{
	int		i;
	char	*new;

	i = 0;
	new = ft_strnew(ft_strlen(src) + ft_strlen(mark));
	while (*src && *src != -1)
	{
		new[i++] = *src;
		src++;
	}
	while (*mark)
	{
		new[i++] = *mark;
		mark++;
	}
	while (*src == -1)
		src++;
	while (*src && *src != -1)
	{
		new[i++] = *src;
		src++;
	}
	return (new);
}

static int	print_error_mark(char *instr, char status)
{
	ft_putstr_fd("!: '", STDERR_FILENO);
	if (*instr)
		ft_putchar_fd(*instr, STDERR_FILENO);
	if (status == 1)
		ft_putstr_fd("' no such event designator\n", STDERR_FILENO);
	else if (status == 2)
		ft_putstr_fd("' no such word designator\n", STDERR_FILENO);
	else if (status == 3)
		ft_putstr_fd("' no such modifier\n", STDERR_FILENO);
	return (1);
}

int			mark_controller(char *instr, char **src)
{
	char *cmd;
	char *tmp;

	if (!(cmd = mark_event_designator(instr, *src)))
		return (print_error_mark(instr, 1));
	while (*instr)
		if (*instr++ == ':')
			break ;
	if (*instr)
	{
		if (!(tmp = mark_word_designator(&instr, cmd)))
			return (print_error_mark(instr, 2));
		ft_strdel(&cmd);
		cmd = tmp;
	}
	while (*instr)
	{
		if (!mark_modifier(&instr, &cmd))
			return (print_error_mark(instr, 3));
	}
	*src = insert_mark(*src, cmd);
	return (0);
}
