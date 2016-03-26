/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:10:23 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/05 15:31:55 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>
#include <ftsh.h>
#include <readline.h>

static int	get_padding_index(void)
{
	int size;
	int number;

	size = 0;
	if (!g_shell->history->tail)
		return (0);
	number = g_shell->history->tail->index;
	while (number)
	{
		size++;
		number /= 10;
	}
	return (size);
}

int			print_history(void)
{
	t_his	*ptr;
	int		pad;

	if (!g_shell->history->head)
		return (1);
	ptr = g_shell->history->head;
	pad = get_padding_index();
	while (ptr && ptr->next)
	{
		ptr->cmd = line_proper(&ptr->cmd);
		if (ptr->index != -1)
			ft_printf("{PYELLOW}%*d{EOC} : %s\n", pad, ptr->index, ptr->cmd);
		ptr = ptr->next;
	}
	return (0);
}

int			recu_print_his(int count, t_his *ptr)
{
	if (count < 0)
	{
		return (ft_putendl_fd("history: index must be positive",
			STDERR_FILENO));
	}
	if (!count || !ptr)
		return (0);
	if (ptr->index == -1)
		return (recu_print_his(count, ptr->prev));
	recu_print_his(count - 1, ptr->prev);
	ptr->cmd = line_proper(&ptr->cmd);
	ft_printf("{PYELLOW}%5d{EOC} : %s\n", ptr->index, ptr->cmd);
	return (0);
}
