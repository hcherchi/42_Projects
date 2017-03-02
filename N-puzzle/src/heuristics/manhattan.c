/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:06:59 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/11 18:07:03 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "npuzzle.h"

int get_dist(int nb, int **grid1, int **grid2, int size)
{
  t_pos *p1;
  t_pos *p2;
  int dist;

  p1 = get_pos(nb, grid1, size);
  p2 = get_pos(nb, grid2, size);
  dist = abs(p2->i - p1->i) + abs(p2->j - p1->j);
  free(p1);
  free(p2);
  return (dist);
}

int h_man(int **grid1, int **grid2, int size)
{
  int res;
  int i;

  i = 0;
  res = 0;
  while (i < size * size)
  {
    res += get_dist(i, grid1, grid2, size);
    i++;
  }
  return (res);
}
