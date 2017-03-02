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

void clean_tab(char **tab)
{
  int i;

  i = 0;
  while (tab[i])
  {
    free(tab[i]);
    i++;
  }
  free(tab);
}

void clean_grid(int **grid, int size)
{
  int i;

  i = 0;
  while (i < size)
  {
    free(grid[i]);
    i++;
  }
  free(grid);
}

void clean_state(t_state *state, int size)
{
  clean_grid(state->grid, size);
  free(state->pos);
  free(state);
}

void clean_list(t_state *l_state, int size)
{
  t_state *tmp;

  while (l_state)
  {
    tmp = l_state;
    l_state = l_state->next;
    clean_state(tmp, size);
  }
}

void clean_params(t_param *params)
{
    clean_state(params->end, params->size);
    if (params->input)
      clean_tab(params->input);
    free(params);
}
