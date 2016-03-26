/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:28:57 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/18 16:48:41 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>
#include <ftsh.h>

void			clear_completion_list(t_readline *r)
{
	t_com *tmp;

	while (r->completion->head)
	{
		ft_strdel(&(r->completion->head->name));
		tmp = r->completion->head;
		r->completion->head = r->completion->head->next;
		free(tmp);
	}
	free(r->completion);
}

void			print_completion_list(t_readline *r)
{
	int		count;
	int		window;
	t_com	*start;

	count = 0;
	window = r->width;
	start = r->completion->head;
	while (window > (r->completion->max + 2))
	{
		window -= (r->completion->max + 2);
		count++;
	}
	count--;
	r->comp = 1;
	ft_putchar('\n');
	while (r->completion->head)
	{
		ft_printf("%-*s", r->completion->max + 2,
			r->completion->head->name);
		if (r->completion->head->index > 0 &&
			(r->completion->head->index) % count == 0)
			ft_putchar('\n');
		r->completion->head = r->completion->head->next;
	}
	r->completion->head = start;
}

void			print_completion(t_readline *r)
{
	int i;
	int j;

	j = 0;
	while (!is_special_char((r->line)[r->i]))
		keyboard_right(r);
	i = r->i;
	while (i > 0 && !(is_special_char((r->line)[i - 1])) &&
		(r->line)[i - 1] != '/')
		i--;
	while ((int)(r->i) > i)
		keyboard_delete(r);
	while ((r->completion->head->name)[j] != '\0')
	{
		add_char_to_str(r, (r->completion->head->name)[j]);
		j++;
	}
	if (r->completion->head->dir == 1)
		add_char_to_str(r, '/');
}

static void		remplissage_completion_bis(t_com **head, t_com **tail,
	char *path, char *name)
{
	if ((int)ft_strlen(name) > g_shell->reader->completion->max)
		g_shell->reader->completion->max = (int)ft_strlen(name);
	if (*tail)
	{
		(*tail)->next = new_maillon_completion(name);
		(*tail)->next->index = (*tail)->index + 1;
		if (is_dir(path, name))
			(*tail)->next->dir = 1;
		(*tail) = (*tail)->next;
	}
	else
	{
		(*tail) = new_maillon_completion(name);
		if (is_dir(path, name))
			(*tail)->dir = 1;
	}
	if (!(*head))
		(*head) = (*tail);
}

int				remplissage_completion(char *str, char *path, t_readline *r)
{
	t_com			*head;
	t_com			*tail;
	DIR				*dir;
	struct dirent	*lec;
	int				count;

	dir = opendir(path);
	count = 0;
	r->completion->max = 0;
	tail = NULL;
	head = NULL;
	if (dir == 0)
		return (0);
	while ((lec = readdir(dir)))
	{
		if (match(lec->d_name, str) && ++count)
		{
			remplissage_completion_bis(&head, &tail, path, lec->d_name);
		}
	}
	r->completion->tail = tail;
	r->completion->head = head;
	closedir(dir);
	return (count);
}
