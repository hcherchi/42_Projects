/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:25:26 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/23 15:56:21 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <executor.h>

char		**tab_from_arglist(t_arg *arglist)
{
	int		size;
	t_arg	*it;
	char	**res;

	size = 0;
	it = arglist;
	while (it && ++size)
		it = it->next;
	if (!(res = (char **)malloc(sizeof(*res) * (size + 1))))
		return (NULL);
	it = arglist;
	size = 0;
	while (it)
	{
		replace_env_var((char**)&it->data);
		res[size++] = (char *)it->data;
		it = it->next;
	}
	res[size] = NULL;
	return (res);
}

t_arg		*new_cmd_arg(char *arg)
{
	t_arg	*res;

	if (!(res = (t_arg *)malloc(sizeof(*res))))
		return (NULL);
	res->data = arg;
	res->next = NULL;
	return (res);
}

void		add_arg_to_list(t_arg **list, char *arg, int reset)
{
	static t_arg	*last = NULL;

	if (!reset && last == NULL)
	{
		*list = new_cmd_arg(arg);
		last = *list;
	}
	else if (!reset)
	{
		last->next = new_cmd_arg(arg);
		last = last->next;
	}
	else
		last = NULL;
}

static void	exec_bquote(t_parser *backquote, int pipefd[2])
{
	close(pipefd[0]);
	dup2(pipefd[1], STDOUT_FILENO);
	exec_node(backquote);
	exit(0);
}

t_arg		*list_from_backquote(t_parser *backquote)
{
	int		pipefd[2];
	t_arg	*list;
	char	**split;
	char	*line;
	pid_t	b_quote_cmd;

	list = NULL;
	pipe(pipefd);
	if ((b_quote_cmd = fork()) > 0)
	{
		close(pipefd[1]);
		while (get_next_line(pipefd[0], &line) == 1)
		{
			split = ft_strsplit(line, ' ');
			add_tab_to_list(&list, split);
			free(line);
			free(split);
		}
		close(pipefd[0]);
		add_arg_to_list(NULL, NULL, 1);
	}
	else
		exec_bquote(backquote, pipefd);
	return (list);
}
