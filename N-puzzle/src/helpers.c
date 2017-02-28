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

int **grid_copy(int **grid, int size)
{
  int **newgrid;
  int i;
  int j;

  newgrid = new_grid(size);
  i = 0;
  while (i < size)
  {
    j = 0;
    while (j < size)
    {
      newgrid[i][j] = grid[i][j];
      j++;
    }
    i++;
  }
  return (newgrid);
}
