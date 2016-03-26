/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:25:58 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/14 17:53:25 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftsh.h"
#include "parser.h"
#include "executor.h"
#include <sys/param.h>

char		*rel_path(char *filename)
{
	char		*res;

	if (ft_strncmp(filename, "./", 2) != 0 &&
			ft_strncmp(filename, "../", 3) != 0 && filename[0] != '/')
		res = ft_strjoin("./", filename);
	else
		res = ft_strdup(filename);
	if (res && ft_strlen(res) > 1 && res[ft_strlen(res) - 1] == '/')
		res[ft_strlen(res) - 1] = '\0';
	return (res);
}

void		handle_next_dir(char *filename, char *path, int *cursor, int *i)
{
	if (ft_strnequ("../", filename + *i, 3) ||
			(ft_strnequ("..", filename + *i, 2) && filename[*i + 2] == '\0'))
	{
		*(ft_strrchr(path, '/')) = '\0';
		while (*cursor > 0 && path[*cursor])
			path[(*cursor)--] = '\0';
		if (*cursor)
			(*cursor)--;
		*i += 2 + (path[*i + 2] == '/');
	}
	else
		handle_next_dir2(filename, path, cursor, i);
	if (path[0] == '\0')
	{
		ft_bzero(path, MAXPATHLEN);
		*cursor = 0;
		path[0] = '/';
	}
}

int			cat_until_slash(char *dst, char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (dst[j])
		j++;
	if (src[i] && j && dst[j - 1] != '/')
		dst[j++] = '/';
	while (src[i] && src[i] != '/')
	{
		dst[i + j] = src[i];
		++i;
	}
	if (src[i] != '\0')
		return (i + 1);
	return (i);
}

void		handle_next_dir2(char *filename, char *path, int *cursor, int *i)
{
	if (ft_strnequ("./", filename + *i, 2))
		*i += 2;
	else if ((filename[*i] == '.' && filename[*i + 1] == '\0') ||
			filename[*i] == '/')
		++(*i);
	else
	{
		*i += cat_until_slash(path, filename + *i);
		while (path[*cursor])
			(*cursor)++;
	}
}

char		*build_path(char *filename)
{
	int		lol[2];
	char	path_build[MAXPATHLEN];
	char	*tmp;
	char	*pwd;

	lol[1] = 0;
	if (access(filename, F_OK))
		return (NULL);
	while (filename[0] == '/' && filename[1] && filename[1] == '/')
		filename++;
	if (filename[0] == '/' && chdir("/") == 0)
	{
		free(g_shell->pwd);
		g_shell->pwd = ft_strdup("/");
		return (build_path(filename + 1));
	}
	pwd = ft_strdup(g_shell->pwd);
	tmp = rel_path(pwd);
	free(pwd);
	ft_strncpy(path_build, tmp, MAXPATHLEN);
	lol[0] = ft_strlen(path_build) - 1;
	while (filename[lol[1]])
		handle_next_dir(filename, path_build, &lol[0], &lol[1]);
	free(tmp);
	return (ft_strdup(path_build));
}
