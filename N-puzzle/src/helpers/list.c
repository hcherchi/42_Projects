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

t_state *new_state(int **grid, t_state *parent, t_param *params)
{
  static int index = 0;
  t_state *state;

  state = malloc(sizeof(t_state));
  state->next = NULL;
  state->grid = grid;
  state->parent = parent;
  state->g = parent ? parent->g + 1 : 0;
  if (params->end)
  {
    if (params->heuristic == 1)
      state->h = h_man(state->grid, params->end->grid, params->size);
    else if (params->heuristic == 2)
      state->h = h_row_column(state->grid, params->end->grid, params->size);
    else if (params->heuristic == 3)
      state->h = h_misplaced(state->grid, params->end->grid, params->size);
  }
  state->pos = get_pos(0, state->grid, params->size);
  state->index = index;
  index++;
  return (state);
}

int list_size(t_state *l_states)
{
  int count;

  count = 0;
  while (l_states)
  {
    count++;
    l_states = l_states->next;
  }
  return (count);
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