/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:29:17 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/24 10:12:50 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	clear_opt(t_read_opt *opt)
{
	int i;

	i = 0;
	if (opt->a)
		free(opt->a);
	if (opt->p)
		free(opt->p);
	if (opt->name)
	{
		while (opt->name[i])
		{
			free(opt->name[i]);
			i++;
		}
		free(opt->name);
	}
	free(opt);
}

void	fill_read_opt(t_read_opt *opt, t_node_cmd *node)
{
	opt->s = 0;
	opt->r = 0;
	opt->a = NULL;
	opt->p = NULL;
	opt->n = -1;
	opt->d = '\n';
	opt->error = 0;
	opt->k = 1;
	check_options_read(opt, node);
}

void	check_options_read(t_read_opt *opt, t_node_cmd *node)
{
	int	i;
	int	j;

	i = 1;
	while (i < node->ac && node->cmd[i][0] == '-')
	{
		j = 1;
		while (node->cmd[i][j])
		{
			if (node->cmd[i][j] != 's' && node->cmd[i][j] != 'r'
				&& node->cmd[i][j] != 'a' && node->cmd[i][j] != 'p'
				&& node->cmd[i][j] != 'n' && node->cmd[i][j] != 'd')
				opt->error = 1;
			j++;
		}
		if (j == 1)
			opt->error = 1;
		i++;
	}
	if (opt->error)
		return ;
	modif_option_read(opt, node);
}

void	spot_opt(t_read_opt *opt, t_node_cmd *node, int i, int j)
{
	if (node->cmd[i][j] == 'a' && i + opt->k < node->ac
			&& node->cmd[i + opt->k][0] != '-')
	{
		opt->a = ft_strdup(node->cmd[i + opt->k]);
		opt->k++;
	}
	if (node->cmd[i][j] == 'p' && i + opt->k < node->ac
			&& node->cmd[i + opt->k][0] != '-')
	{
		opt->p = ft_strdup(node->cmd[i + opt->k]);
		opt->k++;
	}
	if (node->cmd[i][j] == 'n' && i + opt->k < node->ac
			&& node->cmd[i + opt->k][0] != '-')
	{
		opt->n = ft_atoi(node->cmd[i + opt->k]);
		opt->k++;
	}
	if (node->cmd[i][j] == 'd' && i + opt->k < node->ac
			&& node->cmd[i + opt->k][0] != '-')
	{
		opt->d = node->cmd[i + opt->k][0];
		opt->k++;
	}
}

void	modif_option_read(t_read_opt *opt, t_node_cmd *node)
{
	int i;
	int j;

	i = 1;
	while (i < node->ac && node->cmd[i][0] == '-' && (j = 1))
	{
		opt->k = 1;
		while (node->cmd[i][j])
		{
			opt->s = node->cmd[i][j] == 's' ? 1 : opt->s;
			opt->r = node->cmd[i][j] == 'r' ? 1 : opt->r;
			spot_opt(opt, node, i, j);
			j++;
		}
		i = i + opt->k;
	}
	j = 0;
	opt->name = malloc(sizeof(char *) * (node->ac - i + 1));
	while (i < node->ac)
	{
		opt->name[j] = ft_strdup(node->cmd[i]);
		j++;
		i++;
	}
	opt->name[j] = NULL;
}
