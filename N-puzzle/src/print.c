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

void print_list(t_state *l_states)
{
  if (!l_states)
  {
    ft_putendl("----");
    ft_putendl("EMPTY");
    ft_putendl("----");
  }
  while (l_states)
  {
    print_state(l_states);
    l_states = l_states->next;
  }
}

void print_grid(int **grid, int size)
{
  int i;
  int j;

  i = 0;
  while (i < size)
  {
    j = 0;
    while (j < size)
    {
      ft_putnbr(grid[i][j]);
      ft_putchar(' ');
      j++;
    }
    ft_putchar('\n');
    i++;
  }
  ft_putchar('\n');
}

void print_state(t_state *state)
{
  int i;
  int j;
  i = 0;
  ft_putchar('\n');
  ft_putendl("------");
  ft_putstr("State: ");
  ft_putnbr(state->index);
  ft_putstr(" - Score: ");
  ft_putnbr(state->g);
  ft_putchar('\n');
  while (i < state->size)
  {
    j = 0;
    while (j < state->size)
    {
      ft_putnbr(state->grid[i][j]);
      if (j == state->size - 1)
        ft_putchar('\n');
      else
        ft_putchar(' ');
      j++;
    }
    i++;
  }
  ft_putendl("------");
  ft_putchar('\n');
}
