/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_connect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:15:21 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/15 13:42:14 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_connect	*new_connect_l(t_token **token_l)
{
	t_token		*ptr;
	t_connect	*connect_l;
	int			b_q;

	b_q = 0;
	ptr = *token_l;
	connect_l = NULL;
	while (ptr)
	{
		if (ptr->type == REDIR && b_q == 0)
			redir_spotted(&ptr, &connect_l, token_l);
		else
		{
			if (ptr->type == BACK_QUOTE)
			{
				if (b_q == 0)
					b_q = 1;
				else
					b_q = 0;
			}
			ptr = ptr->next;
		}
	}
	return (connect_l);
}

void		redir_spotted(t_token **ptr,
		t_connect **connect_l, t_token **token_l)
{
	add_connect(connect_l, (t_redir*)((*ptr)->content),
			(char *)((*ptr)->next->content));
	if ((*ptr)->prev)
	{
		(*ptr)->prev->next = (*ptr)->next->next;
		if ((*ptr)->next->next)
			(*ptr)->next->next->prev = (*ptr)->prev;
		*ptr = (*ptr)->prev;
	}
	else
	{
		*token_l = (*ptr)->next->next;
		*ptr = (*ptr)->next->next;
		(*ptr)->prev = NULL;
	}
}

void		handle_l_double(t_connect *connect)
{
	int		pipefd[2];
	char	*line;

	line = "";
	pipe(pipefd);
	while (ft_strcmp(line, connect->label))
	{
		ft_putstr("<heredoc> ");
		if (get_next_line(0, &line) != 1)
			break ;
		if (ft_strcmp(line, connect->label))
			ft_putendl_fd(line, pipefd[1]);
	}
	close(pipefd[1]);
	connect->from = 0;
	connect->to = pipefd[0];
}

void		add_connect(t_connect **connect_l, t_redir *redir, char *label)
{
	t_connect	*new;
	t_connect	*tmp;

	new = malloc(sizeof(*new));
	new->next = NULL;
	new->type = redir->type;
	new->fd = redir->from;
	new->label = ft_strdup(label);
	if (new->type == L_DOUBLE)
		handle_l_double(new);
	if (*connect_l == NULL)
		*connect_l = new;
	else
	{
		tmp = *connect_l;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
