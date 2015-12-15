/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:02:06 by bgantelm          #+#    #+#             */
/*   Updated: 2015/12/14 16:22:13 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(int i, char c)
{
	if (i == 0)
	{
		ft_putstr("ls: illegal option -- ");
		ft_putchar(c);
		ft_putstr("\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n");
		exit(1);
	}
	if (i == 1)
	{
		ft_putstr("ls: ");
		ft_putchar(c);
		ft_putstr(": No such file or directory\n");
		return ;
	}

}
