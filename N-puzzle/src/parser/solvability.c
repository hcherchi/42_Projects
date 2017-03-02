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

int is_solvable(t_param *params)
{
  int *start;
  int i;
  int count;

  count = 0;
  i = 0;
  start = get_flat_grid(params->start->grid, params->size);
  while (i < params->size * params->size - 1)
  {
    if ((start[i] > start[i + 1] && start[i + 1] != 0) || start[i] == 0)
    {
      swap(start, i, i + 1);
      i = 0;
      count++;
    }
    else
      i++;
  }
  free(start);
  ft_putnbr(count);
  if (count % 2 == 1)
    return (0);
  else
    return (1);
}
