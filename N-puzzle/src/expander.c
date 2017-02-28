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

int **get_up_move(t_state *state)
{
  int **grid;

  grid = grid_copy(state->grid, state->size);
  if (state->pos->i - 1 < 0 || (state->parent && state->parent->pos->i == state->pos->i - 1))
    return (NULL);
  grid[state->pos->i][state->pos->j] = grid[state->pos->i - 1][state->pos->j];
  grid[state->pos->i - 1][state->pos->j] = 0;
  return (grid);
}

int **get_right_move(t_state *state)
{
  int **grid;

  grid = grid_copy(state->grid, state->size);
  if (state->pos->j + 1 >= state->size || (state->parent && state->parent->pos->j == state->pos->j + 1))
    return (NULL);
  grid[state->pos->i][state->pos->j] = grid[state->pos->i][state->pos->j + 1];
  grid[state->pos->i][state->pos->j + 1] = 0;
  return (grid);
}

int **get_left_move(t_state *state)
{
  int **grid;

  grid = grid_copy(state->grid, state->size);
  if (state->pos->j - 1 < 0 || (state->parent && state->parent->pos->j == state->pos->j - 1))
    return (NULL);
  grid[state->pos->i][state->pos->j] = grid[state->pos->i][state->pos->j - 1];
  grid[state->pos->i][state->pos->j - 1] = 0;
  return (grid);
}

int **get_down_move(t_state *state)
{
  int **grid;

  grid = grid_copy(state->grid, state->size);
  if (state->pos->i + 1 >= state->size || (state->parent && state->parent->pos->i == state->pos->i + 1))
    return (NULL);
  grid[state->pos->i][state->pos->j] = grid[state->pos->i + 1][state->pos->j];
  grid[state->pos->i + 1][state->pos->j] = 0;
  return (grid);
}


int ***expand(t_state *state)
{
  int i;
  int ***grids;
  int count;
  int **grid;

  i = 0;
  count = 0;
  grids = malloc(sizeof(int **) * 5);
  while (i < 4)
  {
    if (i == 0)
      grid = get_up_move(state);
    else if (i == 1)
      grid = get_right_move(state);
    else if (i == 2)
      grid = get_down_move(state);
    else if (i == 3)
      grid = get_left_move(state);
    if (grid)
    {
      grids[count] = grid;
      count++;
    }
    i++;
  }
  grids[count] = NULL;
  return (grids);
}
