/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_modifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:11:32 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/07 11:03:43 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <executor.h>
#include <libft.h>

static char	*keep_last_suffix(char **cmd, char ch)
{
	char *tmp;

	if (!ft_strchr(*cmd, ch))
	{
		ft_strdel(cmd);
		return (NULL);
	}
	else
	{
		tmp = ft_strdup(ft_strrchr(*cmd, ch));
		ft_strdel(cmd);
		if (ch == '/')
		{
			*cmd = ft_strdup(tmp + 1);
			free(tmp);
		}
		else
			*cmd = tmp;
		return (tmp);
	}
}

static char	*remove_last_suffix(char **cmd, char ch)
{
	char	*tmp;

	if (!ft_strchr(*cmd, ch))
	{
		ft_strdel(cmd);
		return (NULL);
	}
	else
	{
		tmp = ft_strrchr(*cmd, ch);
		tmp[0] = '\0';
		return (*cmd);
	}
}

char		*mark_modifier(char **instr, char **cmd)
{
	if (!ft_strchr("htresglu", **instr))
		return (NULL);
	if (**instr == 'l')
		ft_strlower(*cmd);
	else if (**instr == 'u')
		ft_strupper(*cmd);
	else if (**instr == 'e' || **instr == 't')
		keep_last_suffix(cmd, (**instr == 'e') ? '.' : '/');
	else if (**instr == 'r' || **instr == 'h')
		*cmd = remove_last_suffix(cmd, (**instr == 'h') ? '/' : '.');
	else if (**instr == 's' || **instr == 'g')
		*cmd = mark_substitution(instr, cmd);
	if (*cmd && **instr != 's' && **instr != 'g')
	{
		if ((*instr)[1])
			*instr += 1;
		*instr += 1;
	}
	return (*cmd);
}
