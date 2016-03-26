/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:40:05 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/19 13:47:33 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int				max_line_size(t_readline *r, int *i)
{
	int j;
	int k;
	int max_debut;
	int max_fin;
	int max_size;

	max_debut = 0;
	max_fin = 0;
	max_size = 0;
	j = 0;
	while ((r->line)[j] != '\0')
	{
		*i = j;
		while ((r->line)[j] != '\0' && (r->line)[j] != -2 && (r->line)[j] != -4)
			j++;
		k = j;
		if ((k - *i) > max_size && (max_size = k - *i))
		{
			max_debut = *i;
			max_fin = k;
		}
		j++;
	}
	*i = (max_debut + ((r->width) - 9) * 0.90);
	return (max_size);
}

void			add_newline_str(t_readline *r, long key, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	tmp = ft_strdup(r->line);
	r->line = ft_realloc(r->line, 1);
	while (j < i)
	{
		(r->line)[j] = tmp[j];
		j++;
	}
	(r->line)[j] = key;
	j++;
	while (j <= (int)ft_strlen(tmp))
	{
		(r->line)[j] = tmp[j - 1];
		j++;
	}
	(r->line)[j] = '\0';
	ft_strdel(&tmp);
}

static void		put_newline(void)
{
	tputs(tgetstr("im", NULL), 0, ft_outc);
	ft_putstr("\nnewline> ");
	tputs(tgetstr("ei", NULL), 0, ft_outc);
}

void			replace_line(t_readline *r)
{
	int max_size;
	int max_num;

	max_num = 0;
	max_size = max_line_size(r, &max_num);
	if ((max_size + 9) >= r->width)
	{
		add_newline_str(r, -2, max_num);
		replace_line(r);
		return ;
	}
	while ((r->line)[r->i] != '\0')
	{
		if ((r->line)[r->i] == -2 || (r->line)[r->i] == -4)
			put_newline();
		else
		{
			tputs(tgetstr("im", NULL), 0, ft_outc);
			ft_putchar((r->line)[r->i]);
			tputs(tgetstr("ei", NULL), 0, ft_outc);
		}
		(r->i)++;
	}
}
