/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:30:20 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/23 17:51:22 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <executor.h>
#include <stdlib.h>

int		expand_tilde(char **str)
{
	int		i;
	char	*home;

	i = 0;
	home = get_env(g_shell->env, "HOME", 1);
	if (!home)
		return (FAILURE);
	while ((*str)[i])
	{
		while ((*str)[i] == ' ')
			i++;
		if ((*str)[i] == '~')
			insert_string(str, i, i, home);
		while ((*str)[i] && (*str)[i] != ' ' && (*str)[i] != '>')
			i++;
		if ((*str)[i])
			i++;
	}
	free(home);
	return (SUCCESS);
}
