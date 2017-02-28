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

t_pos *get_pos(int nb, t_state *state)
{
  int i;
  int j;
  t_pos *pos;

  pos = malloc(sizeof(t_pos *));
  i = 0;
  while (i < state->size)
  {
    j = 0;
    while (j < state->size)
    {
      if (state->grid[i][j] == nb)
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

int get_dist(int nb, t_state *state, t_state *end)
{
  t_pos *p1;
  t_pos *p2;

  p1 = get_pos(nb, state);
  p2 = get_pos(nb, end);
  return (abs(p2->i - p1->i) + abs(p2->j - p1->j));
}

int h_man(t_state *state, t_state *end)
{
  int res;
  int i;

  i = 0;
  res = 0;
  while (i < end->size * end->size)
  {
    res += get_dist(i, state, end);
    i++;
  }
  return (res);
}
