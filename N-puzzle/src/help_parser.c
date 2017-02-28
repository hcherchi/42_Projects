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

int is_comment(char *str)
{
  if (str && str[0] == '#')
    return (1);
  return (0);
}

void skip_comments(int fd, char **line)
{
  int ret;

  while (is_comment(*line) || !*line)
  {
    ret = get_next_line(fd, line);
    if (ret == -1)
      ft_exit("Error while reading file");
    else if (ret == 0)
      ft_exit("Incomplete file");
  }
}

int is_good_number(int nb, int *tab, int size)
{
  if (nb >= 0 && nb < size * size && tab[nb] == 0)
  {
    tab[nb] = 1;
    return (1);
  }
  return (0);
}

int is_number(char *nbr)
{
  while (*nbr)
  {
    if (*nbr < '0' || *nbr > '9')
      return (0);
    nbr++;
  }
  return (1);
}
