/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:14:23 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/18 19:14:24 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "lexer.h"
#include "libft.h"
#include "executor.h"

t_shell *g_shell;

t_parser	*new_node_parser(int type, void *data)
{
	t_parser	*new;

	if ((new = (t_parser*)malloc(sizeof(t_parser))) == NULL)
		return (NULL);
	new->type = type;
	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

t_node_cmd	*new_node_cmd(t_arg *arg_liste, t_connect *connect_l)
{
	t_node_cmd *new;

	if ((new = (t_node_cmd*)malloc(sizeof(t_node_cmd))) == NULL)
		return (NULL);
	new->ac = 0;
	new->cmd = NULL;
	new->connect = connect_l;
	if (arg_liste == NULL && connect_l)
		add_arg(&arg_liste, new_arg(STRING, ft_strdup("cat")));
	new->arg = arg_liste;
	if (g_shell && g_shell->env)
		new->env = dup_env(g_shell->env);
	else
		new->env = NULL;
	return (new);
}

void		add_node_parser(t_parser **head, t_parser *new, char mode)
{
	t_parser *ptr;

	if (!*head)
		return ((void)(*head = new));
	ptr = *head;
	while (ptr->right)
		ptr = ptr->right;
	if (mode & LEFT)
		ptr->left = new;
	else
		ptr->right = new;
}
