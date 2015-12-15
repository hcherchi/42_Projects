/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 12:01:59 by bgantelm          #+#    #+#             */
/*   Updated: 2015/12/15 12:15:11 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*new_file(struct dirent *info, char *path)
{
	t_file *new;
	struct stat *stats;
	char *acl;

	acl = (char *)malloc(sizeof(*acl) * 12);
	new = malloc(sizeof(*new));
	stats = malloc(sizeof(*stats));
	if (new == NULL || stats == NULL)
		return (NULL);
	new->data->name = ft_strdup(info->d_name);
	new->data->path = add_path(path, new->data->name);
	lstat(new->data->path, stats);
	strmode(stats->st_mode, acl);
	new->data->mod = acl;
	new->data->nblink = ft_itoa(stats->st_nlink);
	new->data->nboct = ft_itoa(stats->st_size);
	new->data->nb_blocks = stats->st_blocks;
	new->data->gid = ft_strdup(getgrgid(stats->st_gid)->gr_name);
	new->data->uid = ft_strdup(getpwuid(stats->st_uid)->pw_name);
	new->data->time = ft_strsub(ctime(&(stats->st_mtime)), 4, 12);
	if (new->data->mod[0] == 'l')
		new->data->namelk = getlink(new);
	else
		new->data->namelk = NULL;
	new->next = NULL;
	new->prev = NULL;
	free(stats);
	return (new);
}

void	add_file(t_file **al_files, t_file *new)
{
	t_file	*cur;

	cur = *al_files;
	if (cur == NULL)
		*al_files = new;
	else
	{
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
		new->next = NULL;
	}
}

char	*add_path(char *path, char *name)
{
	char	*newpath;
	int		i;

	i = 0;
	newpath = (char *)malloc(sizeof(*newpath) * (ft_strlen(path) + ft_strlen(name) + 2));
	if (newpath == NULL)
		return (NULL);
	while (*path)
	{
		newpath[i] = *path;
		i++;
		path++;
	}
	newpath[i] = '/';
	i++;
	while (*name)
	{
		newpath[i] = *name;
		i++;
		name++;
	}
	newpath[i] = '\0';
	return (newpath);
}

t_file	*init_files(char *path, char *options)
{
	DIR				*opening;
	t_file			*l_files;
	struct dirent	*info;

	l_files = NULL;
	opening = opendir(path);
	while ((info = readdir(opening)) != NULL)
	{
		if (instr(options, 'a') || (instr(options, 'a') == 0 && info->d_name[0] != '.'))
			add_file(&l_files, new_file(info, path));
	}
	free(info);
	closedir(opening);
	return(l_files);
}

char	*getlink(t_file *file)
{
	ssize_t	buf_size;
	char	*buf;
	int		i;

	i = 0;
	buf_size = 1;
	buf = (char *)malloc(sizeof(*buf) * buf_size);
	while ((i = readlink(file->data->name, buf, buf_size)) == buf_size)
	{
		buf_size += 1;
		free(buf);
		buf = (char *)malloc(sizeof(*buf) * buf_size);
	}
	buf[i] = '\0';
	return (buf);
}
