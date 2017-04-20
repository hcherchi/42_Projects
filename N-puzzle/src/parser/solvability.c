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

int get_flat_pos(int nb, int **grid, int size)
{
  int t;
  int i;
  int j;

  i = 0;
  t = 0;
  while (i < size)
  {
    j = 0;
    while (j < size)
    {
      if (grid[i][j] == nb)
        return (t);
      t++;
      j++;
    }
    i++;
  }
  return (-1);
}

int count_inversions(int **grid, int size, int *blank)
{
  int *flat_grid;
  int i;
  int count;

  i = 0;
  count = 0;
  *blank = get_flat_pos(0, grid, size);
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
  int blank_end;
  int blank_start;

  start_invertions = count_inversions(start, size, &blank_start);
  end_invertions = count_inversions(end, size, &blank_end);
  ft_putnbr(blank_end);
  ft_putnbr(blank_start);
  ft_putchar('\n');
  ft_putnbr(end_invertions);
  ft_putchar(' ');
  ft_putnbr(start_invertions);

  if (!size % 2)
  {
    start_invertions += blank_start / size;
    end_invertions += blank_end / size;
  }

  if  (start_invertions % 2 == end_invertions % 2)
    return (1);
  else
    return (0);
}
