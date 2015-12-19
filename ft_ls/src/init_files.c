/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 17:49:29 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/19 14:56:08 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*new_file(char *path)
{
	t_data		*data;
	t_file		*new;
	struct stat *stats;

	data = malloc(sizeof(*data));
	new = malloc(sizeof(*new));
	stats = malloc(sizeof(*stats));
	if (new == NULL || stats == NULL || data == NULL)
		return (NULL);
	new->data = data;
	new->data->path = path;
	if (instr(path, '/') == 1)
		new->data->name = ft_strdup(ft_strrchr(path, '/') + 1);
	else
		new->data->name = path;
	lstat(new->data->path, stats);
	fill_file(stats, new);
	free(stats);
	return (new);
}

t_file	*fill_file(struct stat *stats, t_file *new)
{
	char	*acl;

	acl = (char *)malloc(sizeof(*acl) * 12);
	strmode(stats->st_mode, acl);
	new->data->mod = acl;
	new->data->nblink = ft_itoa(stats->st_nlink);
	new->data->nboct = ft_itoa(stats->st_size);
	new->data->nb_blocks = stats->st_blocks;
	new->data->gid = ft_strdup(getgrgid(stats->st_gid)->gr_name);
	new->data->uid = ft_strdup(getpwuid(stats->st_uid)->pw_name);
	new->data->time = stats->st_mtime;
	if (new->data->mod[0] == 'l')
		new->data->namelk = getlink(new);
	else
		new->data->namelk = NULL;
	new->next = NULL;
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

t_file	*init_files(char *path, t_option *opt)
{
	DIR				*opening;
	t_file			*l_files;
	struct dirent	*info;
	char			*newpath;

	l_files = NULL;
	opening = opendir(path);
	if (opening == NULL)
		return (NULL);
	while ((info = readdir(opening)) != NULL)
	{
		if (opt->a || (!opt->a && info->d_name[0] != '.'))
		{
			newpath = add_path(path, info->d_name);
			add_file(&l_files, new_file(newpath));
		}
	}
	closedir(opening);
	choose_sort(&l_files, opt);
	return (l_files);
}
