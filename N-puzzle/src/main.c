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

void ft_exit(char *str)
{
  ft_putendl(str);
  exit(1);
}

int main(int ac, char **av)
{
  int size;
  int fd;
  t_state *start;
  t_state *end;

  if (ac != 2)
    ft_exit("Bad number of arguments.");
  if ((fd = open(av[1], O_RDONLY)) == -1)
    ft_exit("Error while reading file.");
  size = check_input(fd);
  if ((fd = open(av[1], O_RDONLY)) == -1)
    ft_exit("Error while reading file.");
  ft_putendl("--- CHECK OK ---\n");
  end = new_state(get_final_grid(size), NULL, NULL);
  end->size = size;
  start = new_state(get_grid(fd, size), NULL, end);
  ft_putendl("START STATE");
  print_state(start);
  ft_putendl("END STATE");
  print_state(end);
  resolve(start, end);
  return (0);
}
