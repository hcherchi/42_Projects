/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:22:39 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/18 14:22:45 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

char		*add_char_without_print(t_readline *r, long key)
{
	int		j;
	char	*tmp;

	j = 0;
	tmp = ft_strdup(r->line);
	r->line = ft_realloc(r->line, 1);
	while ((size_t)j < (size_t)r->i)
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
	return (r->line);
}

char		*add_char_to_str(t_readline *r, long key)
{
	int		j;
	char	*tmp;

	j = 0;
	tmp = ft_strdup(r->line);
	r->line = ft_realloc(r->line, 1);
	while ((size_t)j < (size_t)r->i)
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
	tputs(tgetstr("im", NULL), 0, ft_outc);
	ft_putchar(key);
	tputs(tgetstr("ei", NULL), 0, ft_outc);
	ft_strdel(&tmp);
	(r->i)++;
	return (r->line);
}

void		del_char_to_str(t_readline *r)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tputs(tgetstr("le", NULL), 1, ft_outc);
	tputs(tgetstr("im", NULL), 0, ft_outc);
	tputs(tgetstr("dc", NULL), 1, ft_outc);
	tputs(tgetstr("ei", NULL), 0, ft_outc);
	tmp = (char *)malloc(sizeof(char) * ft_strlen(r->line));
	while ((r->line)[i] != '\0')
	{
		if (i == ((int)r->i - 1))
			i++;
		if ((r->line)[i] == '\0')
			break ;
		tmp[j] = (r->line)[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	ft_strdel(&(r->line));
	r->line = tmp;
	(r->i)--;
}
