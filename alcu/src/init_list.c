/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjean-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 00:05:31 by wjean-ma          #+#    #+#             */
/*   Updated: 2015/12/21 18:18:44 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	add_line(t_line **alist, int nb)
{
	t_line *cur;
	t_line *new;

	if ((new = malloc(sizeof(*new))))
	{
		new->nb = nb;
		new->next = NULL;
		if ((cur = *alist) == NULL)
			*alist = new;
		else
		{
			while (cur->next)
				cur = cur->next;
			cur->next = new;
			new->next = NULL;
		}
	}
}

t_line	*init_lines(char *buf)
{
	t_line	*lines;
	char	**split;
	int		len;
	int		nb;
	int		i;

	lines = NULL;
	i = 0;
	if (buf == NULL || buf[0] == '\0')
		ft_putstr("You just quit the game.. See you soon !\n");
	len = nb_lines(buf);
	split = ft_strsplit(buf, '\n');
	while (i < len)
	{
		nb = ft_atoi(split[i]);
		if (nb < 1 || nb > 10000)
		{
			ft_putstr_fd("Numbers of rows must be between 1 and 10000\n", 2);
			return (NULL);
		}
		add_line(&lines, ft_atoi(split[i]));
		i++;
	}
	return (lines);
}

void	reverse(t_line **lines)
{
	t_line *inv;
	t_line *cur;

	cur = *lines;
	inv = NULL;
	if (*lines)
	{
		while ((*lines)->next)
		{
			while (cur->next->next)
				cur = cur->next;
			add_line(&inv, cur->next->nb);
			cur->next = NULL;
			cur = *lines;
		}
		add_line(&inv, cur->nb);
		*lines = inv;
	}
}
