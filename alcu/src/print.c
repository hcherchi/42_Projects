/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjean-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 00:11:51 by wjean-ma          #+#    #+#             */
/*   Updated: 2015/12/21 00:41:16 by wjean-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void	print_lines(t_line **lines)
{
	t_line *cur;

	reverse(lines);
	cur = *lines;
	ft_putchar('\n');
	while (cur)
	{
		if (cur->nb > 30)
		{
			ft_putnbr(cur->nb);
			ft_putchar('\n');
		}
		else
		{
			multiputstr("| ", cur->nb);
			ft_putchar('\n');
		}
		cur = cur->next;
	}
	ft_putchar('\n');
	reverse(lines);
}

void	multiputstr(char *str, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		ft_putstr(str);
		i++;
	}
}
