/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:27:23 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/19 20:27:25 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
#include <executor.h>

int		export_builtin(t_node_cmd *node)
{
	int		i;
	char	**split;
	int		res;

	i = 1;
	while (node->cmd[i])
	{
		if (node->cmd[i][0] == '=' || node->cmd[1][0] == '\0')
			res = export_bad_id(node, i);
		else
		{
			split = ft_strsplit(node->cmd[i], '=');
			res = export_var(split[0], split[1]);
			ft_tabdel((void ***)&split);
		}
		i++;
	}
	if (i == 1 && (res = SUCCESS) == SUCCESS)
		print_vars(node);
	return (res);
}

int		export_bad_id(t_node_cmd *node, int i)
{
	int		err_fd;

	err_fd = get_stderr(node);
	ft_putstr_fd("42sh: export: bad delimiter: ", err_fd);
	ft_putendl_fd(node->cmd[i], err_fd);
	return (FAILURE);
}
