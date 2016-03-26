/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_event_designator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:11:29 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/19 20:29:10 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <executor.h>
#include <libft.h>

static char	*get_his_cmd(int i, char mode)
{
	t_his	*ptr;
	int		count;

	ptr = g_shell->history->tail;
	if (mode == 3)
	{
		if (ptr && ptr->index != -1)
			return (ft_strdup(ptr->cmd));
		else if (ptr && ptr->prev)
			return (ft_strdup(ptr->prev->cmd));
	}
	count = 0;
	while (ptr && mode != 3)
	{
		if (ptr->cmd)
			count--;
		if (mode == 1 && ptr->index == i && ptr->cmd)
			return (ft_strdup(ptr->cmd));
		else if (mode == 2 && count == i && ptr->cmd)
			return (ft_strdup(ptr->cmd));
		ptr = ptr->prev;
	}
	return (NULL);
}

static char	*get_str(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] && str[i] != ':')
		i++;
	tmp = ft_strsub(str, 0, i);
	return (tmp);
}

static char	*get_str_for_match(char *str, char mode)
{
	char *tmp;

	if (mode == 1)
	{
		tmp = str;
		str = ft_strjoin("*", str);
		ft_strdel(&tmp);
	}
	tmp = str;
	str = ft_strjoin(str, "*");
	ft_strdel(&tmp);
	return (str);
}

static char	*get_base_src(char *str)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i] && str[i] != -1)
		i++;
	new = ft_strsub(str, 0, i);
	return (new);
}

char		*mark_event_designator(char *str, char *src)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = ft_atoi(str + 1);
	if (ft_isdigit(str[1]) || str[1] == '-')
		return (get_his_cmd(i, (i < 0) ? 2 : 1));
	else if (str[1] == '!')
		return (get_his_cmd(0, 3));
	else if (str[1] == '#')
		return (get_base_src(src));
	else
	{
		if (str[1] == '?')
			str = get_str_for_match(get_str(str + 2), 1);
		else
			str = get_str_for_match(get_str(str + 1), 2);
		return (histo_match(str));
	}
	return (tmp);
}
