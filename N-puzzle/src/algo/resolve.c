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

t_state *get_final_path(t_state *state)
{
  t_state *tmp;
  t_state *path;

  tmp = state;
  path = NULL;
  while (tmp)
  {
      tmp->child = path;
      path = tmp;
      tmp = tmp->parent;
  }
  return (path);
}

t_state *search_best(t_state *l_states)
{
  t_state *best;

  best = l_states;
  while (l_states)
  {
    if (l_states->h + l_states->g <= best->h + best->g)
      best = l_states;
    l_states = l_states->next;
  }
  return (best);
}

void resolve(t_param *params)
{
    t_state *opened;
    t_state *closed;
    t_state *best;
    t_state *found;
    t_state *solution;
    int ***expanded;
    int success;
    int max;
    int size;
    int i;

    max = 0;
    expanded = NULL;
    success = 0;
    opened = params->start;
    closed = NULL;
    while (opened != NULL && !success)
    {
      if ((size = list_size(opened)) > max)
        max = size;
      best = opened;
      //print_state(best, params->size);
      if (is_same(best->grid, params->end->grid, params->size))
        success = 1;
      else
      {
        opened = opened->next;
        add_state_to_begin(&closed, best);
        expanded = expand(best, params->size);
        i = 0;
        while (expanded[i])
        {
          if (!(found = find_in(opened, expanded[i], params->size)) && !(found = find_in(closed, expanded[i], params->size)))
            add_state(&opened, new_state(expanded[i], best, params));
          else
          {
            clean_grid(expanded[i], params->size);
            if (found->g > best->g + 1)
            {
               found->g = best->g + 1;
               found->parent = best;
               if (remove_state(&closed, found->index))
                 add_state(&opened, found);
            }
          }
          i++;
        }
        free(expanded);
      }
    }
    if (success)
    {
      ft_putendl("SOLUTION");
      solution = get_final_path(best);
      print_solution(solution, params->size);
      print_statistics(max, best->index, best->g);
      clean_list(opened, params->size);
      clean_list(closed, params->size);
    }
}
