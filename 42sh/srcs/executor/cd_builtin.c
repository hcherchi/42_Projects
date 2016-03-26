/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:25:42 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/14 17:52:33 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include <sys/param.h>
#include "libft.h"
#include <errno.h>

int		cd_error_msg(t_node_cmd *node, int err, char *msg)
{
	int		err_fd;

	err_fd = get_stderr(node);
	ft_putstr_fd("cd: ", err_fd);
	if (err == CD_ERR_OPTION)
	{
		ft_putstr_fd("invalid option: ", err_fd);
		ft_putendl_fd(msg, err_fd);
	}
	(err == CD_ERR_OLDPWD) ? ft_putendl_fd("OLDPWD is not set", err_fd) : (0);
	(err == CD_ERR_HOME) ? ft_putendl_fd("HOME is not set", err_fd) : (0);
	if (err == CD_ERR)
	{
		if (errno == EACCES)
			ft_putstr_fd("permission denied: ", err_fd);
		else if (errno == ENOENT)
			ft_putstr_fd("no such file or directory: ", err_fd);
		else if (errno == ENOTDIR)
			ft_putstr_fd("not a directory: ", err_fd);
		else
			ft_putstr_fd("file name too long: ", err_fd);
		ft_putendl_fd(msg, err_fd);
	}
	return (FAILURE);
}

int		cd_builtin(t_node_cmd *node)
{
	if (node->ac == 1 || (node->ac == 2 && ft_strequ(node->cmd[1], "~")))
		return (cd_to_home(node));
	if (ft_strequ(node->cmd[1], "-"))
		return (cd_to_old_pwd(node));
	else if (node->cmd[1][0] == '-' &&
			node->cmd[1][1] != 'P' && node->cmd[1][1] != 'L')
		return (cd_error_msg(node, CD_ERR_OPTION, node->cmd[1]));
	else if (ft_strequ(node->cmd[1], "-P"))
		return (cd_to_dir(node, 2, 'P'));
	else if (ft_strequ(node->cmd[1], "-L"))
		return (cd_to_dir(node, 2, 'L'));
	else
		return (cd_to_dir(node, 1, 'a'));
}

int		cd_to_home(t_node_cmd *node)
{
	char	*dir;

	dir = get_env(node->env, "HOME", 1);
	if (!dir)
		return (cd_error_msg(node, CD_ERR_HOME, NULL));
	if (chdir(dir) != 0)
		return (cd_error_msg(node, CD_ERR, dir));
	set_env(&g_shell->env, "OLDPWD", get_env(node->env, "PWD", 1));
	set_env(&g_shell->env, "PWD", getcwd(NULL, MAXPATHLEN));
	if (g_shell->pwd)
		free(g_shell->pwd);
	g_shell->pwd = get_env(g_shell->env, "PWD", 1);
	free(dir);
	return (SUCCESS);
}

int		cd_to_old_pwd(t_node_cmd *node)
{
	char	*dir;

	dir = get_env(node->env, "OLDPWD", 0);
	if (!dir)
		return (cd_error_msg(node, CD_ERR_OLDPWD, NULL));
	if (chdir(dir) != 0)
		return (cd_error_msg(node, CD_ERR, dir));
	set_env(&g_shell->env, "PWD", get_env(node->env, "OLDPWD", 1));
	set_env(&g_shell->env, "OLDPWD", ft_strdup(g_shell->pwd));
	if (g_shell->pwd)
		free(g_shell->pwd);
	g_shell->pwd = get_env(g_shell->env, "PWD", 1);
	return (SUCCESS);
}

int		cd_to_dir(t_node_cmd *node, int argindex, char opt)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = ft_strdup(g_shell->pwd);
	if (node->cmd[argindex] == NULL)
		return (cd_to_home(node));
	if (opt != 'P')
		tmp = build_path(node->cmd[argindex]);
	if (chdir(node->cmd[argindex]) != 0)
		return (cd_error_msg(node, CD_ERR, node->cmd[argindex]));
	if (opt == 'P')
		tmp = getcwd(NULL, MAXPATHLEN);
	if (tmp == NULL)
		tmp = ft_strdup(g_shell->pwd);
	set_env(&g_shell->env, "OLDPWD", tmp2);
	set_env(&g_shell->env, "PWD", tmp);
	if (g_shell->pwd)
		free(g_shell->pwd);
	g_shell->pwd = ft_strdup(tmp);
	return (SUCCESS);
}
