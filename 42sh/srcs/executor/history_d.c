/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:10:14 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/19 20:31:39 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>

static int	is_invalid_arg_d(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	get_new_index_his(t_his *node)
{
	while (node)
	{
		if (node->index != -1)
			node->index--;
		node = node->next;
	}
}

int			history_d(char *str)
{
	t_his	*ptr;
	int		index;

	if (!str || is_invalid_arg_d(str))
		return (1);
	index = ft_atoi(str);
	if (!g_shell->history->head)
		return (1);
	ptr = g_shell->history->head;
	while (ptr)
	{
		if (ptr->index == index)
			break ;
		ptr = ptr->next;
	}
	if (ptr && ptr->index == index)
	{
		get_new_index_his(ptr);
		pop_his_node(ptr);
		return (0);
	}
	else
		ft_putstr_fd("history: -d: position out of range\n", STDERR_FILENO);
	return (1);
}
