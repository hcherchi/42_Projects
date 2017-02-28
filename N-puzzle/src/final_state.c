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

int **rotate(int **grid, int size)
{
  int **newgrid;
  int i;
  int j;

  i = 0;
  newgrid = new_grid(size);
  while (i < size)
  {
    j = 0;
    while (j < size)
    {
      newgrid[i][j] = grid[j][size - i - 1];
      j++;
    }
    i++;
  }
  return (newgrid);
}

int **get_final_grid(int size)
{
  int curnb;
  int **grid;
  int depth;
  int j;
  int count;

  count = 0;
  grid = new_grid(size);
  curnb = 1;
  depth = 0;
  j = 0;
  while (curnb < size * size)
  {
    if (j + depth < size && grid[depth][j] == 0)
    {
      grid[depth][j] = curnb;
      curnb++;
      j++;
    }
    else
    {
      if (j + depth < size)
      {
        depth++;
        j = depth;
      }
      else
        j = depth + 1;
      grid = rotate(grid, size);
      count++;
    }
  }
  while (count % 4 != 0)
  {
    grid = rotate(grid, size);
    count++;
  }
  return (grid);
}
