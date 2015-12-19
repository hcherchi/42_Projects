/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 17:49:48 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/19 18:44:53 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(char c)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ls [-Ralrt] [file ...]\n");
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
