/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_termcaps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:14:30 by bgantelm          #+#    #+#             */
/*   Updated: 2016/02/18 14:36:34 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>
#include <ftsh.h>

int				ft_outc(int c)
{
	static int	fd = -1;

	if (fd == -1)
		fd = open("/dev/tty", O_WRONLY);
	ft_putchar_fd(c, fd);
	return (0);
}

void			default_terminal_mode(void)
{
	struct termios		term;

	tcgetattr(0, &term);
	term.c_lflag |= ICANON;
	term.c_lflag |= ECHO;
	tputs(tgetstr("ei", NULL), 1, ft_outc);
	tcsetattr(0, TCSANOW, &term);
}

int				raw_term_mode(void)
{
	struct termios term;

	if (tgetent(NULL, getenv("TERM")) != 1)
		tgetent(NULL, DEFAULT_TERM);
	if (tcgetattr(0, &term) == -1)
		return (-1);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &term) == -1)
		return (-1);
	tputs(tgetstr("im", NULL), 1, ft_outc);
	return (0);
}
