/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:21:56 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 21:37:57 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	lvlup(char ***myenv)
{
	char	*newlvl;
	char	*lvl;

	lvl = get_elem(*myenv, "SHLVL=");
	if (lvl == NULL)
	{
		ft_setenv(myenv, "SHLVL", "1", NULL);
		return ;
	}
	newlvl = ft_itoa(ft_atoi(lvl) + 1);
	ft_setenv(myenv, "SHLVL", newlvl, NULL);
	free(lvl);
	free(newlvl);
}

int		main(int ac, char **av, char **env)
{
	char	**myenv;
	char	*home;
	size_t	len_prompt;

	myenv = tab_dup(env);
	lvlup(&myenv);
	if (ac == 1 && av)
	{
		home = get_elem(env, "PWD=");
		prompt(home);
		len_prompt = ft_strlen(home) + 2;
		ft_test(myenv, len_prompt);
	}
	else
		ft_putendl("No arguments needed.");
	return (0);
}
