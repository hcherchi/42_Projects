/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:28:33 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/24 15:22:45 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline.h>

void	print_line(t_readline *r)
{
	int	i;

	i = 0;
	while ((r->line)[i] != '\0')
	{
		if ((r->line)[i] == -2 || (r->line)[i] == -4)
		{
			tputs(tgetstr("im", NULL), 0, ft_outc);
			ft_putchar('\n');
			ft_putstr("newline> ");
			tputs(tgetstr("ei", NULL), 0, ft_outc);
		}
		else
		{
			tputs(tgetstr("im", NULL), 0, ft_outc);
			ft_putchar((r->line)[i]);
			tputs(tgetstr("ei", NULL), 0, ft_outc);
		}
		i++;
	}
	r->i = ft_strlen(r->line);
}

int		is_special_char(char c)
{
	if (c == '\0' || c == ' ' || c == -2 || c == -4)
		return (1);
	return (0);
}

int		is_dir(char *path, char *name)
{
	struct stat	dir;
	int			res;
	char		*pathname;
	char		*tmp;

	pathname = ft_strjoin(path, "/");
	tmp = pathname;
	pathname = ft_strjoin(pathname, name);
	ft_strdel(&tmp);
	res = stat(pathname, &dir);
	ft_strdel(&pathname);
	if (res == -1)
		return (0);
	if (dir.st_mode & S_IFDIR)
		return (1);
	return (0);
}

t_com	*new_maillon_completion(char *name)
{
	t_com	*new;

	new = (t_com *)malloc(sizeof(t_com));
	new->name = ft_strdup(name);
	new->size = ft_strlen(name);
	new->dir = 0;
	new->next = NULL;
	new->index = 0;
	return (new);
}

void	completion(t_readline *r)
{
	char			*tmp;
	char			*path;
	int				ret;

	ret = 0;
	r->completion = (t_completion *)malloc(sizeof(t_completion));
	r->completion->head = NULL;
	r->completion->tail = NULL;
	tmp = part_of_line(r);
	path = search_path(&tmp);
	if ((ret = remplissage_completion(tmp, path, r)) == 1)
		print_completion(r);
	else if (ret > 1)
		print_completion_list(r);
	clear_completion_list(r);
	ft_strdel(&tmp);
	ft_strdel(&path);
}
