/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:42:34 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/18 14:42:36 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>
#include <ftsh.h>

void	reprint_resize(t_readline *r)
{
	char	*tmp;

	tmp = ft_strdup(r->line);
	go_to_end(r);
	clean_line(r);
	r->line = tmp;
	replace_line(r);
}

void	resize(int status)
{
	struct winsize	sz;

	ioctl(0, TIOCGWINSZ, &sz);
	g_shell->reader->width = sz.ws_col;
	reprint_resize(g_shell->reader);
	(void)status;
}
