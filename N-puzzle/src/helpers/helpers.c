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
  clean_grid(grid, size);
  return (newgrid);
}

int in_tab(int *tab, int size, int nb)
{
  int i;

  i = 0;
  while (i < size)
  {
    if (tab[i] == nb)
      return (1);
    i++;
  }
  return (0);
}

int *get_flat_grid(int **grid, int size)
{
  int i;
  int j;
  int tmp;
  int *res;

  res = new_tab(size * size - 1, 0);
  tmp = 0;
  i = 0;
  while (i < size)
  {
    j = 0;
    while (j < size)
    {
      if (grid[i][j] != 0)
      {
        res[tmp] = grid[i][j];
        tmp++;
      }
      j++;
    }
    i++;
  }
  return (res);
}

void swap(int *tab, int a, int b)
{
  int c;

  c = tab[a];
  tab[a] = tab[b];
  tab[b] = c;
}

int   is_same(int **grid1, int **grid2, int size)
{
  int i;
  int j;

  i = 0;
  while (i < size)
  {
    j = 0;
    while (j < size)
    {
      if (grid1[i][j] != grid2[i][j])
        return (0);
      j++;
    }
    i++;
  }
  return (1);
}

t_state   *find_in(t_state *l_states, int **grid, int size)
{
  while (l_states)
  {
    if (is_same(l_states->grid, grid, size))
      return (l_states);
    l_states = l_states->next;
  }
  return (NULL);
}

t_pos *get_pos(int nb, int **grid, int size)
{
  int i;
  int j;
  t_pos *pos;

  pos = malloc(sizeof(t_pos *));
  i = 0;
  while (i < size)
  {
    j = 0;
    while (j < size)
    {
      if (grid[i][j] == nb)
      {
        pos->i = i;
        pos->j = j;
        return (pos);
      }
      j++;
    }
    i++;
  }
  return (NULL);
}
