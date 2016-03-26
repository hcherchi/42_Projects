/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:39:15 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/14 15:37:40 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

int			is_quote_r(char c)
{
	if (c == 34 || c == 39 || c == 96
			|| c == '{' || c == '[' || c == '(')
	{
		return (1);
	}
	return (0);
}

static int	quotes_bis(t_readline *r, int i, int c)
{
	if ((c == 34 || c == 39 || c == 96) && (r->line)[i] == c &&
		!is_escaped(r, i))
		c = 0;
	else if (c == '{' && (r->line)[i] == '}' && !is_escaped(r, i))
		c = 0;
	else if (c == '[' && (r->line)[i] == ']' && !is_escaped(r, i))
		c = 0;
	else if (c == '(' && (r->line)[i] == ')' && !is_escaped(r, i))
		c = 0;
	return (c);
}

int			quotes(t_readline *r)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while ((r->line)[i] != '\0')
	{
		if (c == 0 && is_quote_r((r->line)[i]) && !is_escaped(r, i))
			c = (r->line)[i];
		else
			c = quotes_bis(r, i, c);
		i++;
	}
	return (c);
}

int			only_b(t_readline *r)
{
	int j;

	j = ft_strlen(r->line) - 1;
	if ((r->line)[j] == '\\' && j == 0)
		return (1);
	if ((r->line)[j] == '\\' && ((r->line)[j - 1] == -2 ||
		(r->line)[j - 1] == -4))
		return (1);
	return (0);
}

int			count_backslash(t_readline *r)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(r->line) - 1;
	while ((r->line)[j] == '\\')
	{
		if ((r->line)[j] == '\\')
			i = (i == 1) ? 0 : 1;
		j--;
	}
	if (i == 0)
		return (0);
	return (1);
}
