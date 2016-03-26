/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_manip.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:42:53 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/18 18:40:51 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

char	*create_part_of_line(t_readline *r)
{
	int		i;
	int		j;
	int		h;
	char	*tmp;

	i = r->i;
	j = r->i;
	h = 0;
	while (!(is_special_char((r->line)[j])))
		j++;
	while (i > 0 && !(is_special_char((r->line)[i - 1])))
		i--;
	tmp = (char *)malloc(sizeof(char) * (j - i + 2));
	while (i < j)
	{
		tmp[h] = (r->line)[i];
		h++;
		i++;
	}
	tmp[h] = '*';
	h++;
	tmp[h] = '\0';
	return (tmp);
}

char	*part_of_line(t_readline *r)
{
	if (r->i == 0 || (is_special_char((r->line)[r->i]) &&
		is_special_char((r->line)[r->i - 1])))
		return (ft_strdup("*"));
	else
		return (create_part_of_line(r));
}

char	*string_sub_path(char *str, int j)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (j + 1));
	while (i < j)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*string_sub_str(char *str, int j)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) - j + 1));
	j++;
	while (str[j] != '\0')
	{
		tmp[i] = str[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*search_path(char **str)
{
	int		i;
	int		last;
	char	*tmp;
	char	*path;

	i = 0;
	last = -1;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '/')
			last = i;
		i++;
	}
	if (last > 0 && (tmp = *str))
	{
		path = string_sub_path(*str, last);
		*str = string_sub_str(*str, last);
		ft_strdel(&tmp);
	}
	else if (last == 0 && (path = ft_strdup("/")))
		*str = string_sub_str(*str, last);
	else
		path = ft_strdup(".");
	return (path);
}
