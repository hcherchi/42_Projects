/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 17:06:49 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/07 18:47:07 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	char	**myenv;

	if (ac == 1)
	{
		myenv = tab_dup(env);
		lvlup(&myenv);
		set_commands(&myenv, av);
	}
	else
		ft_putendl("Error");
	return (0);
}
