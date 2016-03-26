/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 19:56:18 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/05 13:26:34 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <readline.h>
#include <executor.h>
#include <sys/param.h>

int			init_shell(void)
{
	extern char **environ;

	if (!(g_shell = malloc(sizeof(t_shell))))
		return (-1);
	g_shell->running = 1;
	g_shell->history = init_history();
	add_his(new_his_node(-1, NULL));
	g_shell->env = env_tab_to_lst(environ);
	set_env(&g_shell->env, "HISTFILE", ft_strdup(".history"));
	g_shell->l_env = NULL;
	g_shell->pwd = getcwd(NULL, MAXPATHLEN);
	g_shell->aliases = NULL;
	g_shell->reader = NULL;
	g_shell->exit_value = 0;
	return (0);
}

int			exit_shell(void)
{
	int ret;

	ret = 0;
	if (!g_shell)
		return (1);
	ret = g_shell->exit_value;
	if (g_shell->reader)
		delete_reader();
	if (g_shell->history)
		save_history(g_shell->history->head);
	del_env(&g_shell->env);
	del_env(&g_shell->l_env);
	del_env(&g_shell->aliases);
	if (g_shell->pwd)
		free(g_shell->pwd);
	free(g_shell);
	return (ret);
}
