/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usuals.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 11:51:38 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/30 17:37:23 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	argsdel(t_args *args)
{
	l_filesdel(args->files);
	l_filesdel(args->dirs);
	free(args->opt);
	free(args);
}

char	*add_path(char *p, char *n)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(*new) * (ft_strlen(p) + ft_strlen(n) + 2));
	if (new == NULL)
		return (NULL);
	while (*p)
	{
		new[i] = *p++;
		i++;
	}
	if (new[i - 1] != '/')
	{
		new[i] = '/';
		i++;
	}
	while (*n)
	{
		new[i] = *n++;
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	l_filesdel(t_file *l_files)
{
	t_file *todel;

	while (l_files)
	{
		todel = l_files;
		l_files = l_files->next;
		free(todel->data->name);
		free(todel->data->path);
		free(todel->data->mod);
		free(todel->data->nblink);
		free(todel->data->uid);
		free(todel->data->nboct);
		free(todel->data->gid);
		if (todel->data->namelk)
			free(todel->data->namelk);
		free(todel->data);
		free(todel);
	}
}

int		instr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*getlink(t_file *file)
{
	ssize_t	buf_size;
	char	*buf;
	int		i;

	i = 0;
	buf_size = 1;
	buf = (char *)malloc(sizeof(*buf) * buf_size + 1);
	while ((i = readlink(file->data->path, buf, buf_size)) == buf_size)
	{
		buf_size += 1;
		free(buf);
		buf = (char *)malloc(sizeof(*buf) * buf_size + 1);
	}
	buf[i] = '\0';
	return (buf);
}
