/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token_globbing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 20:46:18 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/19 19:57:47 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

int		is_back_quote(char *line)
{
	if (*line == '`')
		return (1);
	return (0);
}

int		is_parent_c(char *line)
{
	if (*line == ')')
		return (1);
	return (0);
}

int		is_parent_o(char *line)
{
	if (*line == '(')
		return (1);
	return (0);
}

int		is_simple_quote(char *line)
{
	if (*line == '\'')
		return (1);
	return (0);
}

int		is_double_quote(char *line)
{
	if (*line == '"')
		return (1);
	return (0);
}
