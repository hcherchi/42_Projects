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

void print_list(t_state *l_states, int size)
{
  if (!l_states)
  {
    ft_putendl("----");
    ft_putendl("EMPTY");
    ft_putendl("----");
  }
  while (l_states)
  {
    print_state(l_states, size);
    l_states = l_states->next;
  }
}

void print_solution(t_state *l_states, int size)
{
  if (!l_states)
  {
    ft_putendl("----");
    ft_putendl("EMPTY");
    ft_putendl("----");
  }
  while (l_states)
  {
    print_state(l_states, size);
    l_states = l_states->child;
  }
}

void print_state(t_state *state, int size)
{
  int i;
  int j;
  i = 0;
  ft_putchar('\n');
  ft_putendl("------");
  ft_putstr("State: ");
  ft_putnbr(state->index);
  ft_putstr(" - Moves: ");
  ft_putnbr(state->g);
  ft_putstr(" - Score: ");
  ft_putnbr(state->h);
  ft_putchar('\n');
  while (i < size)
  {
    j = 0;
    while (j < size)
    {
      ft_putnbr(state->grid[i][j]);
      if (j == size - 1)
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

void print_statistics(int max, int nbstates, int moves)
{
  ft_putstr("Maximum number of opened states at the same time: ");
  ft_putnbr(max);
  ft_putchar('\n');
  ft_putstr("Total number of states ever opened: ");
  ft_putnbr(nbstates);
  ft_putchar('\n');
  ft_putstr("Total number of moves to get to the solution: ");
  ft_putnbr(moves);
  ft_putchar('\n');
}
