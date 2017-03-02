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
    if (l_states->h + l_states->g < best->h + best->g)
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
      //sleep(1);
      //ft_putendl("OPENED");
      if ((size = list_size(opened)) > max)
        max = size;
      //print_list(opened);
      //ft_putendl("BEST");
      best = search_best(opened);
      //print_state(best, params->size);
      if (is_same(best->grid, params->end->grid, params->size))
        success = 1;
      else
      {
        remove_state(&opened, best->index);
        add_state(&closed, best);
        expanded = expand(best, params->size);
        i = 0;
        //ft_putendl("EXPANSION");
        while (expanded[i])
        {
          if (!(found = find_in(opened, expanded[i], params->size)) && !(found = find_in(closed, expanded[i], params->size)))
          {
            //ft_putendl("Brand new state");
            found = new_state(expanded[i], best, params);
            add_state(&opened, found);
          }
          else
          {
            clean_grid(expanded[i], params->size);
            //ft_putendl("State already found");
            if (found->g + found->h > found->h + best->g + 1)
            {
               //ft_putendl("But better");
               found->g = found->h + best->g + 1;
               found->parent = best;
               if (find_in(closed, found->grid, params->size))
               {
                 remove_state(&closed, found->index);
                 add_state(&opened, found);
               }
            }
            else
            {
              //ft_putendl("But not better");
            }
          }
          //print_state(found);
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
