/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 11:50:25 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/30 17:35:56 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(char c)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ls [-Ralrtpfgh] [file ...]\n");
	exit(1);
}

void	ft_error2(char *av)
{
	ft_putstr("ls: ");
	ft_putstr(av);
	ft_putstr(": No such file or directory\n");
}

void	ft_error3(char *path)
{
	ft_putstr("ls: ");
	ft_putstr(path);
	ft_putstr(": Permission denied\n");
}
