/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:26:07 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/05 19:14:58 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "executor.h"

int		echo_builtin(t_node_cmd *node)
{
	char	n_opt_flag;
	int		i;
	int		out_fd;

	out_fd = get_stdout(node);
	i = 1;
	if (!node->cmd || !node->cmd[0])
		return (FAILURE);
	n_opt_flag = 0;
	if (node->cmd[i] && ft_strcmp(node->cmd[i], "-n") == 0 && ++i)
		n_opt_flag = 1;
	else if (node->cmd[i] && ft_strcmp(node->cmd[i], "-") == 0)
		++i;
	while (node->cmd[i])
	{
		write(out_fd, node->cmd[i], ft_strlen(node->cmd[i]));
		if (node->cmd[i + 1])
			write(out_fd, " ", 1);
		++i;
	}
	if (!n_opt_flag)
		write(out_fd, "\n", 1);
	return (SUCCESS);
}
