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

void resolve(t_state *start, t_state *end)
{
    t_state *opened;
    t_state *closed;
    t_state *best;
    t_state *found;
    int ***expanded;
    int success;

    expanded = NULL;
    success = 0;
    opened = start;
    closed = NULL;
    while (opened != NULL && !success)
    {
      //sleep(1);
      //ft_putendl("OPENED");
      //print_list(opened);
      //ft_putendl("BEST");
      best = search_best(opened);
      print_state(best);
      if (is_same(best, end->grid))
      {
        ft_putendl("--- THE END ---");
        success = 1;
      }
      else
      {
        remove_state(&opened, best->index);
        add_state(&closed, best);
        expanded = expand(best);
        //ft_putendl("EXPANSION");
        while (*expanded)
        {
          if (!(found = is_in(opened, *expanded)) && !(found = is_in(closed, *expanded)))
          {
            //ft_putendl("Brand new state");
            found = new_state(*expanded, best, end);
            add_state(&opened, found);
          }
          else
          {
            //ft_putendl("State already found");
            if (found->g + found->h > found->h + best->g + 1)
            {
               //ft_putendl("But better");
               found->g = found->h + best->g + 1;
               found->parent = best;
               if (is_in(closed, found->grid))
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
          expanded++;
        }
      }
    }
}
