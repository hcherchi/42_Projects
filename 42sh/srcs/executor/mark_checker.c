/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:11:26 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/15 13:03:58 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <executor.h>

static int	get_word_size(char *str)
{
	int i;

	i = 1;
	if (ft_isdigit(str[i]) || (str[i] == '-' && ++i))
	{
		while (str[i] && ft_isdigit(str[i]))
			i++;
	}
	else if (str[i] == '#' || str[i] == '!')
		i++;
	else
	{
		while (str[i] && !ft_isspace(str[i]) && str[i] != ':')
			i++;
	}
	return (i);
}

static int	get_modifier_size(char *str)
{
	int i;
	int j;
	int count;

	i = 0;
	while (str[i] && str[i] == ':' && !ft_isspace(str[i]))
	{
		count = 0;
		if (str[i + 1] && str[i + 1] != 's' && str[i + 1] != 'g')
			i += 2;
		else if (str[i + 1] == 's' || str[i + 1] == 'g')
		{
			j = i + 1;
			while (str[j] && count != 3)
				if (str[j++] == '/')
					count++;
			if (count == 3)
				i = j;
			else
				break ;
		}
		else
			break ;
	}
	return (i);
}

static char	*get_mark_cmd(char *str)
{
	char	*tmp;
	int		size;

	size = get_word_size(str);
	if (str[size] == ':' && str[size + 1])
	{
		if (str[size + 1] != 's' && str[size + 1] != 'g')
			size += 2;
		size += get_modifier_size(str + size);
	}
	tmp = ft_strsub(str, 0, size);
	while (--size >= 0)
		str[size] = -1;
	return (tmp);
}

static void	replace_reader(char *str)
{
	if (ft_strcmp(str, g_shell->reader->line))
	{
		ft_strdel(&g_shell->reader->line);
		ft_strdel(&g_shell->reader->line_before);
		g_shell->reader->line = ft_strdup(str);
		g_shell->reader->line_before = ft_strdup(str);
	}
	ft_strdel(&str);
}

int			mark_checker(void)
{
	int		i;
	char	*str;
	char	*tmp;
	size_t	size;

	i = -1;
	str = ft_strdup(g_shell->reader->line);
	while (str[++i])
	{
		if (str[i] == '!' && (!i || (str[i - 1] != '$' && str[i - 1] != '\\')))
		{
			tmp = get_mark_cmd(str + i);
			size = ft_strlen(str + i) + ft_strlen(tmp) + 1;
			if (mark_controller(tmp, &str))
				return (1);
			ft_printf("{PGREEN}%s{EOC}\n", str);
			ft_strdel(&tmp);
		}
		if (!str[i])
			break ;
	}
	replace_reader(str);
	return (check_match_quote(g_shell->reader->line));
	return (0);
}
