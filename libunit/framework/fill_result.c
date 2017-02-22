/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:12:11 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/13 11:28:56 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"

char	*proper_exit(int status)
{
	status = WEXITSTATUS(status);
	if (status == 0)
		return (ft_strdup("[OK]\n"));
	else
		return (ft_strdup("[KO]\n"));
}

char	*not_proper_exit(int status)
{
	if (status == SIGSEGV)
		return (ft_strdup("[SEGV]\n"));
	else if (status == SIGBUS)
		return (ft_strdup("[BUSE]\n"));
	else
		return (ft_strdup("[KO]\n"));
}
