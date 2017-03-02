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

int   get_out_row_column(int i, int **grid1, int **grid2, int size)
{
  t_pos *p1;
  t_pos *p2;
  int out_row;
  int out_column;

  p1 = get_pos(i, grid1, size);
  p2 = get_pos(i, grid2, size);

  out_row = 0;
  out_column = 0;
  if (p1->i != p2->i)
    out_row = 1;
  if (p1->j != p2->j)
    out_column = 1;
  free(p1);
  free(p2);
  return (out_column + out_row);
}

int   h_row_column(int **grid1, int **grid2, int size)
{
  int i;
  int res;

  res = 0;
  i = 0;
  while (i < size * size)
  {
    res += get_out_row_column(i, grid1, grid2, size);
    i++;
  }
  return (res);
}
