/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_match_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 11:35:33 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/14 14:43:15 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>
#include <readline.h>
#include <ftsh.h>

static int	print_error(void)
{
	ft_putendl_fd("42sh: Unmatched quote or parenthesis", STDERR_FILENO);
	return (1);
}

int			check_match_quote(char *s)
{
	int i;
	int q;
	int	b_quote_count;
	int	parent_count;

	i = -1;
	q = 0;
	parent_count = 0;
	b_quote_count = 0;
	while (s[++i])
	{
		if ((s[i] == '\'' || s[i] == '\"') && !q && (!i || s[i - 1] != '\\'))
			q = s[i];
		else if ((s[i] == '\'' || s[i] == '\"') && s[i] == q
			&& (!i || s[i - 1] != '\\'))
			q = 0;
		else if (s[i] == '`' && !q && (!i || s[i - 1] != '\\'))
			b_quote_count++;
		else if ((s[i] == ')' || s[i] == '(') && !q && (!i || s[i - 1] != '\\'))
			parent_count += (s[i] == ')') ? -1 : 1;
	}
	if (parent_count != 0 || b_quote_count % 2 || quotes(g_shell->reader))
		return (print_error());
	return (0);
}
