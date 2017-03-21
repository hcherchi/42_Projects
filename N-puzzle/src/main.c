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
  end_grid = get_final_grid(params->size);
  start_grid = (params->input) ? get_grid(params->input, params->size) : get_random_grid(params->size);
  // while (!is_solvable(start_grid, end_grid, params->size) && !params->input)
  // {
  //   clean_grid(start_grid, params->size);
  //   start_grid = get_random_grid(params->size);
  // }
  params->end = new_state(end_grid, NULL, params);
  params->start = new_state(start_grid, NULL, params);
  ft_putendl("START STATE");
  print_state(params->start, params->size);
  ft_putendl("END STATE");
  print_state(params->end, params->size);
  if (is_solvable(start_grid, end_grid, params->size))
  {
    ft_putendl("\n\n--- Grid solvable ---\n\n");
    sleep(1);
    resolve(params);
  }
  else
  {
    ft_putendl("\n\n--- Grid unsolvable. ---\n\n");
    sleep(1);
    resolve(params);
  }
  clean_params(params);
  return (0);
}
