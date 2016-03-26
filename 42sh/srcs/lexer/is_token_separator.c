/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token_separator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 20:46:26 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/19 19:58:11 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

int		is_semi(char *line)
{
	if (*line == ';')
		return (1);
	return (0);
}

int		is_or(char *line)
{
	if (*line == '|' && *(line + 1) == '|')
		return (2);
	return (0);
}

int		is_pipe(char *line)
{
	if (*line == '|')
		return (1);
	return (0);
}

int		is_and(char *line)
{
	if (*line == '&' && *(line + 1) == '&')
		return (2);
	return (0);
}
