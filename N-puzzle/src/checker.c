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

int check_line(char *line, int size, int *tab)
{
  int count;
  char **split;
  int i;

  i = 0;
  split = ft_strsplit(line, ' ');
  free(line);
  count = 0;
  while (split[i])
  {
    if (is_number(split[i]) && is_good_number(ft_atoi(split[i]), tab, size))
      count++;
    else if (is_comment(split[i]))
      break;
    else
      return (0);
    i++;
  }
  clean_tab(split);
  if (count != size)
    return (0);
  return (1);
}

int check_first_line(char *line)
{
  char **split;
  int size;
  int count;
  int i;

  i = 0;
  split = ft_strsplit(line, ' ');
  free(line);
  count = 0;
  while (split[i])
  {
    if (is_comment(split[i]))
      break;
    size = ft_atoi(split[i]);
    if (is_number(split[i]) && size >= 3)
      count++;
    else
      return (0);
    i++;
  }
  clean_tab(split);
  if (count != 1)
    return (0);
  return (size);
}

int check_input(int fd)
{
  int size;
  int ret;
  char *line;
  int count;
  int *tab;

  count = 0;
  line = NULL;
  skip_comments(fd, &line);
  if (!(size = check_first_line(line)))
    ft_exit("Bad puzzle size.");
  tab = new_tab(size);
  while ((ret = get_next_line(fd, &line)) == 1)
	{
    if (!line || !check_line(line, size, tab))
      ft_exit("Bad puzzle grid.");
    count++;
  }
  if (count != size)
    ft_exit("Bad number of line.");
  if (ret == -1)
    ft_exit("Error while reading file.");
  close(fd);
  return (size);
}
