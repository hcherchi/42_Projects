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

int is_comment(char *str)
{
  if (str && str[0] == '#')
    return (1);
  return (0);
}

void ft_exit(char *str)
{
  ft_putendl(str);
  exit(1);
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


void add_to_tab(char ***tab, char *to_add)
{
  char **newtab;
  int i;
  int len;

  len = ft_tablen(*tab);
  newtab = malloc(sizeof(char *) * (len + 2));
  i = 0;
  while (i < len)
  {
    newtab[i] = (*tab)[i];
    i++;
  }
  newtab[i] = to_add;
  newtab[i + 1] = NULL;
  free(*tab);
  *tab = newtab;
}
