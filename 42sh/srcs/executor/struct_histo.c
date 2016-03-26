/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_histo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:11:05 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/19 20:30:12 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <readline.h>

t_his		*new_his_node(int index, char *cmd)
{
	t_his *new;

	if (!(new = (t_his*)malloc(sizeof(t_his))))
		return (NULL);
	new->index = index;
	new->cmd = cmd;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		add_his(t_his *new)
{
	if (!g_shell->history->tail)
	{
		g_shell->history->tail = new;
		g_shell->history->head = new;
	}
	else
	{
		g_shell->history->tail->next = new;
		new->prev = g_shell->history->tail;
		g_shell->history->tail = g_shell->history->tail->next;
	}
}

void		pop_his_node(t_his *node)
{
	if (!node->prev)
		g_shell->history->head = node->next;
	if (!node->next)
		g_shell->history->tail = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	if (node->cmd)
		ft_strdel(&node->cmd);
	free(node);
}

int			del_his(void)
{
	t_his	*ptr;
	t_his	*tmp;
	int		fd;

	if (!g_shell->history->head)
		return (0);
	while (g_shell->history->head->prev)
		g_shell->history->head = g_shell->history->head->prev;
	fd = open(".history", O_TRUNC);
	close(fd);
	ptr = g_shell->history->head;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		ft_strdel(&tmp->cmd);
		free(tmp);
	}
	g_shell->history->head = NULL;
	g_shell->history->tail = NULL;
	add_his(new_his_node(-1, NULL));
	return (0);
}
