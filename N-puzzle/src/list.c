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

int   is_same(t_state *state1, int **grid)
{
  int i;
  int j;

  i = 0;
  while (i < state1->size)
  {
    j = 0;
    while (j < state1->size)
    {
      if (state1->grid[i][j] != grid[i][j])
        return (0);
      j++;
    }
    i++;
  }
  return (1);
}

t_state *new_state(int **grid, t_state *parent, t_state *end)
{
  static int index = 0;
  t_state *state;

  state = malloc(sizeof(t_state));
  state->next = NULL;
  state->grid = grid;
  state->size = end ? end->size : 0;
  state->parent = parent;
  state->g = parent ? parent->g + 1 : 0;
  state->h = end ? h_man(state, end) : 0;
  state->pos = get_pos(0, state);
  state->index = index;
  index++;
  return (state);
}

void add_state(t_state **l_states, t_state *to_add)
{
  t_state *tmp;

  tmp = *l_states;
  if (!tmp)
    *l_states = to_add;
  else
  {
    while (tmp->next)
      tmp = tmp->next;
    tmp->next = to_add;
    to_add->next = NULL;
  }
}

void remove_state(t_state **l_states, int index)
{
  t_state *tmp;
  t_state *save;

  tmp = *l_states;
  if (tmp && tmp->index == index)
  {
    *l_states = tmp->next;
  }
  while (tmp->next)
  {
    if (tmp->next->index == index)
    {
      save = tmp->next;
      tmp->next = save->next;
      return;
    }
    tmp = tmp->next;
  }
}

t_state   *is_in(t_state *l_states, int **grid)
{
  while (l_states)
  {
    if (is_same(l_states, grid))
      return (l_states);
    l_states = l_states->next;
  }
  return (NULL);
}
