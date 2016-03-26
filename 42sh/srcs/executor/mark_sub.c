/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:11:34 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/24 15:40:13 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <executor.h>

static int	compact_str(char **cmd, char *old, char *new)
{
	int		i;
	int		size;
	char	*tmp;

	i = 0;
	size = ft_strlen(old);
	tmp = ft_strstr(*cmd, old);
	while (*cmd + i != tmp)
		i++;
	insert_string(cmd, i, i + size - 1, new);
	return (1);
}

static char	*yolo_youlou_norm(void)
{
	ft_putstr_fd("!: substitution cannot contains substituee\n",
			STDERR_FILENO);
	return (0);
}

char		*mark_substitution(char **instr, char **cmd)
{
	char	**tmp;
	int		count;

	tmp = ft_strsplit(*instr, '/');
	if (!tmp[0] || !tmp[1] || !tmp[2])
		return (NULL);
	if (ft_strstr(tmp[2], tmp[1]))
		return (yolo_youlou_norm());
	if (ft_strstr(*cmd, tmp[1]))
	{
		if (**instr == 's')
			compact_str(cmd, tmp[1], tmp[2]);
		else
			while (ft_strstr(*cmd, tmp[1]))
				compact_str(cmd, tmp[1], tmp[2]);
	}
	else
		ft_strdel(cmd);
	ft_tabdel((void***)&tmp);
	count = 0;
	while ((*instr)++)
		if (**instr == '/' && ++count == 3)
			break ;
	return (*cmd);
}
