/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:11:38 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/18 19:11:40 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <executor.h>

char	*histo_match(char *str)
{
	t_his *ptr;

	ptr = g_shell->history->tail;
	while (ptr)
	{
		if (ptr->cmd && match(ptr->cmd, str))
			return (ft_strdup(ptr->cmd));
		ptr = ptr->prev;
	}
	return (NULL);
}
