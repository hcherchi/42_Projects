/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 19:45:54 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/15 12:15:09 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
void	swap_files(t_file *f1, t_file *f2)
{
	t_file *tmp;
	
}*/

/*t_file *sort_ascii(t_file * l_files)
{
	t_file *cur;

	cur = l_files;
	while (cur->next != NULL)
	{
		ft_putstr(cur->data->name);
		ft_putstr(" - ");
		ft_putstr(cur->next->data->name);
		ft_putstr("\n");
		if (ft_strcmp(cur->data->name, cur->next->data->name) > 0)
		{
			ft_putstr(cur->data->name);
			ft_putstr(" <-> ");
			ft_putstr(cur->next->data->name);
			ft_putstr("\n");
			swap_files(cur, cur->next);
			ft_putstr("Swap reussi\n");
			cur = l_files;
		}
		else
			cur = cur->next;
	}
	return (l_files);
}
*/