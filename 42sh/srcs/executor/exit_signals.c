/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:27:15 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/19 20:27:17 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <executor.h>
#include <parser.h>
#include <libft.h>

void	handle_child_ret(int ret)
{
	if (ret == SIGSEGV)
		ft_putstr("42sh: segmentation fault ");
	else if (ret == SIGABRT)
		ft_putstr("42sh: abort ");
	else if (ret == SIGBUS)
		ft_putstr("42sh: bus error ");
}
