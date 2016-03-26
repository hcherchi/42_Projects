/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_token_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 20:46:22 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/19 19:58:36 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

int		is_redir(char *line)
{
	int		ret;

	if ((ret = is_r_double(line)))
		return (ret);
	if ((ret = is_l_double(line)))
		return (ret);
	if ((ret = is_r_simple(line)))
		return (ret);
	if ((ret = is_l_simple(line)))
		return (ret);
	return (0);
}

int		is_r_simple(char *line)
{
	int		i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == '>')
		return (i + 1);
	return (0);
}

int		is_r_double(char *line)
{
	int		i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == '>' && line[i + 1] == '>')
		return (i + 2);
	return (0);
}

int		is_l_simple(char *line)
{
	int		i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == '<')
		return (i + 1);
	return (0);
}

int		is_l_double(char *line)
{
	int		i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == '<' && line[i + 1] == '<')
		return (i + 2);
	return (0);
}
