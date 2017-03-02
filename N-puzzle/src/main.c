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

int main(int ac, char **av)
{
  t_param *params;
  int **start_grid;
  int **end_grid;

  srand(time(NULL));
  params = get_params(ac, av);
  params->end = NULL;
  start_grid = (params->input) ? get_grid(params->input, params->size) : get_random_grid(params->size);
  end_grid = get_final_grid(params->size);
  params->end = new_state(end_grid, NULL, params);
  params->start = new_state(start_grid, NULL, params);
  ft_putendl("START STATE");
  print_state(params->start, params->size);
  ft_putendl("END STATE");
  print_state(params->end, params->size);
  //if (is_solvable(params))
    resolve(params);
  //else
    //ft_exit("Grid unsolvable.");
  clean_params(params);
  return (0);
}
