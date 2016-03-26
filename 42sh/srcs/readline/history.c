/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:35:13 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/05 12:47:59 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>
#include <executor.h>

void		newline_history(t_history *history)
{
	t_his	*new;
	int		index;

	if (detect_identical_lines())
		return ;
	if (!g_shell->history->tail || !g_shell->history->tail->prev)
		index = 1;
	else if (g_shell->history->tail->index == -1)
		index = g_shell->history->tail->prev->index + 1;
	else
		index = g_shell->history->tail->index + 1;
	if (history->tail)
	{
		new = create_history(index, NULL);
		history->tail->next = new;
		new->prev = history->tail;
		history->tail = new;
	}
	else
	{
		new = create_history(index, NULL);
		history->head = new;
		history->tail = new;
	}
	g_shell->history->tail->cmd = ft_strdup(g_shell->reader->line_before);
}

t_history	*init_history(void)
{
	t_history	*history;
	t_his		*head;
	t_his		*tail;

	tail = NULL;
	head = NULL;
	history = (t_history *)malloc(sizeof(t_history));
	tail = read_history(&head, tail);
	history->tail = tail;
	history->head = head;
	return (history);
}

t_his		*create_history(int i, char **line)
{
	t_his	*new;

	new = (t_his *)malloc(sizeof(t_his));
	new->index = i;
	if (line)
		new->cmd = *line;
	else
		new->cmd = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_his		*read_history(t_his **head, t_his *tail)
{
	t_his	*new;
	char	*line;
	int		i;
	int		fd;

	i = 1;
	*head = NULL;
	if ((fd = open(".history", O_RDONLY | O_CREAT, 0644)) == -1)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		new = create_history(i, &line);
		if (i++ == 1)
		{
			*head = new;
			tail = new;
			continue ;
		}
		tail->next = new;
		new->prev = tail;
		tail = new;
	}
	close(fd);
	return (tail);
}

int			save_history(t_his *head)
{
	int		fd;
	t_his	*tmp;
	t_his	*ptr;
	char	*history_filename;

	if (!(history_filename = get_env(g_shell->env, "HISTFILE", 0)))
		return (-1);
	ptr = head;
	if ((fd = open(history_filename, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
		return (-1);
	while (ptr)
	{
		if (ptr->index != -1)
		{
			ft_putendl_fd(ptr->cmd, fd);
			ft_strdel(&ptr->cmd);
		}
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
	if (g_shell->history)
		free(g_shell->history);
	close(fd);
	return (0);
}
