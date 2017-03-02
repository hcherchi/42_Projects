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

int *new_tab(int size, int nb)
{
  int *tab;
  int i;

  i = 0;
  tab = malloc(sizeof(int) * size * size);
  while (i < size * size)
  {
    tab[i] = nb;
    i++;
  }
  return (tab);
}

int **new_grid(int size)
{
  int **grid;
  int i;
  int j;

  i = 0;
  grid = malloc(sizeof(int *) * size);
  while (i < size)
  {
    j = 0;
    grid[i] = malloc(sizeof(int *) * size);
    while (j < size)
    {
      grid[i][j] = 0;
      j++;
    }
    i++;
  }
  return (grid);
}
