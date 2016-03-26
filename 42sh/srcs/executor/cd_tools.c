/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:25:51 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/05 19:17:55 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include <sys/param.h>
#include "libft.h"
#include <errno.h>

int		get_stderr(t_node_cmd *node)
{
	t_connect	*co;
	int			res;

	co = node->connect;
	res = STDERR_FILENO;
	while (co)
	{
		if (co->from == STDERR_FILENO)
			res = co->to;
		co = co->next;
	}
	return (res);
}

int		get_stdout(t_node_cmd *node)
{
	t_connect	*co;
	int			res;

	co = node->connect;
	res = STDOUT_FILENO;
	while (co)
	{
		if (co->from == STDOUT_FILENO)
			res = co->to;
		co = co->next;
	}
	return (res);
}
