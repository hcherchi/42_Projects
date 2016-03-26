/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 10:07:04 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/24 11:23:07 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

char	*g_node[] = {"AND", "NOR", "THEN", "CMD", "PIPE", "HEREDOC"};
char	*g_token[] = {"WORD", "SEMI", "OR", "AND", "REDIR", "PIPE",
	"BACK_QUOTE", "PARENT_O", "PARENT_C", "SIMPLE_QUOTE", "DOUBLE_QUOTE",
	"ENDL", "END_OF_TOKEN"};

int		display_parser_level(t_parser *node, int level)
{
	if (node)
	{
		display_parser_level(node->left, level + 1);
		ft_printf("level %d : currently in node %s\n", level,
				g_node[node->type]);
		if (node->type == NODE_CMD)
		{
			if (((t_node_cmd*)(node->data))->connect)
				ft_printf("there's a redirection\n");
			else
				ft_printf("there's no redirection\n");
			ft_printf("{PCYAN}CMD{EOC}\n");
			display_arg_list(((t_node_cmd*)(node->data))->arg);
			ft_printf("{PCYAN}END{EOC}\n");
		}
		display_parser_level(node->right, level + 1);
	}
	return (1);
}

int		display_parser_level_child(t_parser *node, int level)
{
	if (node)
	{
		display_parser_level_child(node->left, level + 1);
		ft_printf("{PYELLOW}child{EOC}level %d : currently in node %s\n",
				level, g_node[node->type]);
		if (node->type == NODE_CMD)
		{
			if (((t_node_cmd*)(node->data))->connect)
				ft_printf("there's a redirection\n");
			else
				ft_printf("there's no redirection\n");
			ft_printf("{PCYAN}CMD{EOC}\n");
			display_arg_list(((t_node_cmd*)(node->data))->arg);
			ft_printf("{PCYAN}END{EOC}\n");
		}
		display_parser_level_child(node->right, level + 1);
	}
	return (1);
}

int		display_arg_list(t_arg *arg)
{
	while (arg)
	{
		if (arg->type == STRING)
			ft_printf("word: %s\n", arg->data);
		else if (arg->type == B_QUOTE)
		{
			ft_printf("{PYELLOW}SUBTREE{EOC}\n");
			display_parser_level_child(arg->data, 0);
			ft_printf("{PYELLOW}END OF SUBSHELL{EOC}\n");
		}
		arg = arg->next;
	}
	return (1);
}

int		display_token_liste(t_token *ptr)
{
	while (ptr)
	{
		ft_printf("{PLRED}TOKEN:{EOC} %s\n", g_token[ptr->type]);
		if (ptr->type == WORD)
			ft_printf("word is %s\n", ptr->content);
		ptr = ptr->next;
	}
	ft_printf("END OF LISTE\n");
	return (1);
}
