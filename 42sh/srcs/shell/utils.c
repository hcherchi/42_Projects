/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 10:10:09 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/24 10:13:49 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <signal.h>
#include <executor.h>
#include <readline.h>

void		sigint_handler(int signum)
{
	(void)signum;
	keyboard_ctrlc(g_shell->reader);
}

void		sigint_child(int signum)
{
	(void)signum;
}
