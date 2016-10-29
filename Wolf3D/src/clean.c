/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 19:45:08 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/01 12:17:02 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void clean(t_tool *tools)
{
  int i;

  i = 0;
  free(tools->pos);
  free(tools->mlx_ptr);
  free(tools->mlx_win);
  free(tools->mlx_img);
  while (i < tools->nbline)
  {
    free(tools->grid[i]);
    i++;
  }
  free(tools->grid);
  free(tools);
}

void cleanTab(char **tab)
{
  int i;
  int len;

  i = 0;
  len = ft_tablen(tab);
  while (i < len)
  {
    free(tab[i]);
    i++;
  }
  free(tab);
}
