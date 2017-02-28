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

int *get_line(char *line, int size)
{
  int j;
  char **split;
  int *grid_line;

  grid_line = malloc(sizeof(int) * size);
  split = ft_strsplit(line, ' ');
  free(line);
  j = 0;
  while (j < size)
  {
    grid_line[j] = ft_atoi(split[j]);
    j++;
  }
  clean_tab(split);
  return (grid_line);
}

int **get_grid(int fd, int size)
{
  int **grid;
  char *line;
  int ret;
  int i;

  i = 0;
  line = NULL;
  grid = malloc(sizeof(int *) * size);
  skip_comments(fd, &line);
  while (i < size)
  {
    ret = get_next_line(fd, &line);
    if (ret == -1)
      ft_exit("Error while reading file.");
    grid[i] = get_line(line, size);
    i++;
  }
  close(fd);
  return (grid);
}
