/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_word_designator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:11:42 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/07 10:32:21 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <executor.h>
#include <libft.h>

static int	tab_size(char **cmd)
{
	int i;

	i = 0;
	while (cmd[i])
		i++;
	return (i);
}

static char	*concat_cmd(char **cmd, int start, int end, int size)
{
	int		i;
	char	*new;
	char	*tmp;

	new = NULL;
	if (end < start || start < 0 || end >= size)
		return (NULL);
	i = start;
	while (i <= end)
	{
		if (!new)
			new = ft_strdup(cmd[i]);
		else
		{
			tmp = new;
			new = ft_strjoin(new, " ");
			ft_strdel(&tmp);
			tmp = new;
			new = ft_strjoin(new, cmd[i]);
			ft_strdel(&tmp);
		}
		i++;
	}
	return (new);
}

char		*mark_word_designator(char **instr, char *cmd)
{
	char	**tmp;
	int		size;
	int		n;

	tmp = ft_strsplit(cmd, ' ');
	size = tab_size(tmp);
	if (!ft_strchr("0123456789^$*", **instr))
		return (ft_strdup(cmd));
	if (ft_isdigit(**instr))
	{
		n = ft_atoi(*instr);
		if (n >= size || n < 0)
			return (NULL);
		else
			cmd = ft_strdup(tmp[n]);
	}
	else if (**instr == '$')
		cmd = ft_strdup(tmp[size - 1]);
	else if (**instr == '^')
		cmd = (size >= 2) ? ft_strdup(tmp[1]) : NULL;
	else if (**instr == '*')
		cmd = concat_cmd(tmp, 1, size - 1, size);
	ft_tabdel((void***)&tmp);
	(*instr) += 2;
	return (cmd);
}
