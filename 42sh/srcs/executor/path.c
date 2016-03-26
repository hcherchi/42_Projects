/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:29:27 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/19 20:29:29 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "parser.h"
#include <sys/stat.h>

char	*relative_path(char *cmd)
{
	char	*fullpath;

	fullpath = build_path(cmd);
	if (access(cmd, F_OK) == 0 && is_exec(fullpath))
		return (fullpath);
	free(fullpath);
	return (NULL);
}

int		is_exec(char *filename)
{
	struct stat		st;

	if (stat(filename, &st) != 0)
		return (0);
	if (st.st_mode & (S_IXUSR))
		return (1);
	return (0);
}

char	*find_cmd_in_path(char *cmd, char **path)
{
	int		i;
	char	*tmp;
	char	*cmd_path_cat;

	i = 0;
	while (path[i])
	{
		if (path[i][ft_strlen(path[i]) - 1] == '/')
			tmp = ft_strdup(path[i]);
		else
			tmp = ft_strjoin(path[i], "/");
		cmd_path_cat = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(cmd_path_cat, F_OK) == 0 && is_exec(cmd_path_cat))
		{
			ft_tabdel((void ***)&path);
			return (cmd_path_cat);
		}
		free(cmd_path_cat);
		++i;
	}
	ft_tabdel((void***)&path);
	return (NULL);
}

char	*get_path(t_node_cmd *node)
{
	char	*path_env;
	char	**split_path;

	if (ft_strnequ(node->cmd[0], "../", 3) ||
			ft_strnequ(node->cmd[0], "./", 2) ||
			ft_strnequ(node->cmd[0], "/", 1))
		return (relative_path(node->cmd[0]));
	if (!(path_env = get_env(node->env, "PATH", 0)))
		return (NULL);
	split_path = ft_strsplit(path_env, ':');
	return (find_cmd_in_path(node->cmd[0], split_path));
}
