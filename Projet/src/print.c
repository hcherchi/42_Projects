/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:24:00 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 19:24:01 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	prompt(char *home)
{
	if (home)
	{
		ft_putstr("\n\033[1;32m");
		ft_putstr(home);
		ft_putstr("\033[m");
	}
	ft_putstr("\033[1;36m~> \033[m");
}

void	ft_puttab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}
