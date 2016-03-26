/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 20:45:47 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/20 14:04:21 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lexer.h>

t_matcher	g_tab[] = {
	{OR, &is_or},
	{AND, &is_and},
	{SEMI, &is_semi},
	{PIPE, &is_pipe},
	{REDIR, &is_redir},
	{BACK_QUOTE, &is_back_quote},
	{PARENT_O, &is_parent_o},
	{PARENT_C, &is_parent_c},
	{SIMPLE_QUOTE, &is_simple_quote},
	{DOUBLE_QUOTE, &is_double_quote},
	{END_OF_TOKEN, NULL}
};

int		is_token(char *str)
{
	int		i;

	i = 0;
	while (g_tab[i].type != END_OF_TOKEN)
	{
		if (g_tab[i].match_token(str) != 0)
			return (1);
		i++;
	}
	return (0);
}

int		parse_token(t_token **token_list, char *str)
{
	int		i;
	int		l;

	i = 0;
	while (g_tab[i].type != END_OF_TOKEN)
	{
		l = g_tab[i].match_token(str);
		if (l != 0)
		{
			if (g_tab[i].type == REDIR)
				add_token(token_list, parse_new_redir(str), REDIR);
			else
				add_token(token_list, NULL, g_tab[i].type);
			return (l);
		}
		i++;
	}
	return (0);
}

void	cut_word(t_token **token_list, char *line, int length)
{
	char	*word;
	int		i;

	if (length == 0)
		return ;
	i = 0;
	while (ft_isspace(line[i]))
		i++;
	word = ft_strsub(line, i, length);
	add_token(token_list, word, WORD);
}

void	fill_token_list(char *line, t_token **token_list)
{
	int i;

	i = 0;
	while (*line)
	{
		while (*line && ft_isspace(*line))
			line++;
		while (line[i] == '\\' && line[i + 1])
			i += 2;
		if (is_token(line + i) || ft_isspace(line[i]) || !line[i])
		{
			cut_word(token_list, line, i);
			while (line[i] && ft_isspace(line[i]))
				i++;
			if (line[i] == '\'' || line[i] == '"')
				i += parse_token_quote(token_list, line, i);
			else
				i += parse_token(token_list, line + i);
			line += i;
			i = 0;
		}
		else
			i++;
	}
	add_token(token_list, NULL, ENDL);
}
