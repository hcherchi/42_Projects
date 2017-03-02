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

int **get_random_grid(int size)
{
  int **newgrid;
  int i;
  int j;
  int random;
  int *tab;

  tab = new_tab(size * size, 0);
  newgrid = new_grid(size);
  i = 0;
  while (i < size)
  {
    j = 0;
    while (j < size)
    {
      random = rand() % (size * size);
      while (tab[random])
        random = rand() % (size * size);
      tab[random] = 1;
      newgrid[i][j] = random;
      j++;
    }
    i++;
  }
  free(tab);
  return (newgrid);
}
