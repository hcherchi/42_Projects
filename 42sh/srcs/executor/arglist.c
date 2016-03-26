/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arglist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:25:19 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/24 11:09:31 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <executor.h>

static void	build_bquote(t_arg *list)
{
	t_arg	*bquote;

	bquote = list->next;
	list->next = list_from_backquote((t_parser *)bquote->data);
	stick_end_list(&list->next, bquote->next);
	del_tree_parser((t_parser *)bquote->data);
	free(bquote);
}

void		rebuild_arglist(t_node_cmd *node)
{
	t_arg	*list;
	t_arg	*bquote;

	if (node->cmd)
		return ;
	list = node->arg;
	if (list == NULL)
		return ;
	while (list && list->type == B_QUOTE)
	{
		bquote = list;
		node->arg = list_from_backquote((t_parser *)bquote->data);
		stick_end_list(&node->arg, bquote->next);
		del_tree_parser((t_parser *)bquote->data);
		free(bquote);
		list = node->arg;
	}
	while (list && list->next)
	{
		if (list->next->type == B_QUOTE)
			build_bquote(list);
		if (list && list->next)
			list = list->next;
	}
	node->cmd = tab_from_arglist(node->arg);
}

void		stick_end_list(t_arg **list_to_iter, t_arg *rest)
{
	t_arg	*it;

	it = *list_to_iter;
	if (*list_to_iter == NULL)
	{
		*list_to_iter = rest;
		return ;
	}
	while (it && it->next)
		it = it->next;
	if (it)
		it->next = rest;
}

int			tabsize(char **tabs)
{
	int		i;

	i = 0;
	while (tabs && tabs[i])
		i++;
	return (i);
}

t_arg		*args_from_string(char *word)
{
	t_arg	*res;
	char	**split;
	int		i;

	i = 0;
	res = NULL;
	split = ft_strsplit(word, ' ');
	add_tab_to_list(&res, split);
	free(split);
	add_arg_to_list(NULL, NULL, 1);
	return (res);
}
