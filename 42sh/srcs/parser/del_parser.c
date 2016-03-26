/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:13:35 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/05 13:37:31 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <executor.h>
#include "lexer.h"
#include "libft.h"

static int	del_arg_liste(t_arg *head)
{
	t_arg *ptr;

	while (head)
	{
		ptr = head;
		head = head->next;
		if (ptr->type == STRING && ptr->data)
			ft_strdel((char**)(&ptr->data));
		free(ptr);
	}
	return (1);
}

static int	del_node_cmd(t_node_cmd *ptr)
{
	if (ptr->cmd)
		free(ptr->cmd);
	if (ptr->arg)
		del_arg_liste(ptr->arg);
	if (ptr->env)
		del_env(&ptr->env);
	return (1);
}

int			del_tree_parser(t_parser *ptr)
{
	if (!ptr)
		return (0);
	del_tree_parser(ptr->right);
	del_tree_parser(ptr->left);
	if (ptr->data)
	{
		if (ptr->type == NODE_CMD)
			del_node_cmd((t_node_cmd*)(ptr->data));
		free(ptr->data);
	}
	free(ptr);
	return (1);
}

int			del_one_parser(t_parser **ptr)
{
	if (!ptr || !*ptr)
		return (-1);
	if ((*ptr)->type == NODE_CMD)
		del_node_cmd((*ptr)->data);
	free(*ptr);
	*ptr = NULL;
	return (1);
}
