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

int *get_line(char *line, int size, int *tab)
{
  int j;
  char **split;
  char **subsplit;
  int *grid_line;
  int nb;

  grid_line = malloc(sizeof(int) * size);
  split = ft_strsplit(line, '#');
  subsplit = ft_strsplit(split[0], ' ');
  if (ft_tablen(subsplit) != size)
    ft_exit("Invalid input");
  j = 0;
  while (j < size)
  {
    nb = ft_atoi(subsplit[j]);
    if (tab[nb])
      ft_exit("invalid input");
    tab[nb] = 1;
    grid_line[j] = nb;
    j++;
  }
  clean_tab(subsplit);
  clean_tab(split);
  return (grid_line);
}

int **get_grid(char **input, int size)
{
  int **grid;
  int i;
  int *tab;

  tab = new_tab(size * size, 0);

  if (ft_tablen(input) != size)
    ft_exit("Invalid input");
  grid = malloc(sizeof(int *) * size);
  i = 0;
  while (i < size)
  {
    grid[i] = get_line(input[i], size, tab);
    i++;
  }
  free(tab);
  return (grid);
}
