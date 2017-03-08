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

int count_inversions(int **grid, int size)
{
  int *flat_grid;
  int i;
  int count;

  i = 0;
  count = 0;
  flat_grid = get_flat_grid(grid, size);
  while (i < size * size - 1)
  {
    if (flat_grid[i] > flat_grid[i + 1])
    {
      swap(flat_grid, i, i + 1);
      i = 0;
      count++;
    }
    else
      i++;
  }
  return (count);
}

int is_solvable(int **start, int **end, int size)
{
  int start_invertions;
  int end_invertions;

  start_invertions = count_inversions(start, size);
  end_invertions = count_inversions(end, size);

  if (!size % 2)
  {
    start_invertions += start_invertions / size;
    end_invertions += end_invertions / size;
  }

  if  (start_invertions % 2 == end_invertions % 2)
    return (1);
  else
    return (0);
}
