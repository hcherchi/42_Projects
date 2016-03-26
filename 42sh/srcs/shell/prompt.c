/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 19:56:10 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/24 15:30:21 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <executor.h>

static char	*get_directory(void)
{
	int		i;
	char	*tmp;
	char	*home;

	tmp = g_shell->pwd;
	home = get_env(g_shell->env, "HOME", 0);
	if (!tmp)
		return (NULL);
	if (!home)
		return (ft_strdup(tmp));
	i = 0;
	if (ft_strncmp(tmp, home, ft_strlen(home)))
		return (ft_strdup(tmp));
	while (home[i])
		i++;
	return (ft_strjoin("~", tmp + i));
}

int			print_prompt(void)
{
	char *user;
	char *dir;

	dir = get_directory();
	user = get_env(g_shell->env, "USER", 0);
	if (user)
		ft_printf("\n{PLRED}%s{PLYELLOW} in {EOC}", user);
	ft_printf("{PGREEN}%s{EOC}\n", dir);
	if (dir)
		ft_strdel(&dir);
	return (1);
}
