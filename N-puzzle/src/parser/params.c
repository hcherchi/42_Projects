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

int extract_size(char ***input)
{
  int i;
  int size;
  char **grid;

  i = 0;
  grid = NULL;
  while ((*input)[i] && is_comment((*input)[i]))
    i++;
  if (!((*input)[i]) || !is_number((*input)[i]))
    ft_exit("Invalid input");
  size = ft_atoi((*input)[i]);
  i++;
  while ((*input)[i])
  {
    add_to_tab(&grid, ft_strdup((*input)[i]));
    i++;
  }
  clean_tab(*input);
  *input = grid;
  if (size < 3)
    ft_exit("Invalid input");
  return (size);
}

t_param *get_params(int ac, char **av)
{
  int i;
  int fd;
  int ret;
  t_param *params;
  char **split;
  char *line;

  params = NULL;
  params = malloc(sizeof(t_param));
  params->input = NULL;
  params->size = 0;
  params->heuristic = 0;
  i = 1;
  while (i < ac)
  {
    split = ft_strsplit(av[i], '=');
    if (ft_tablen(split) != 2)
    {
      ft_putstr("Bad parameters: ");
      ft_putendl(av[i]);
      ft_exit("Usage: ./npuzzle (size=[3-∞] OR file=[filename]) AND heuristic=[123]");
    }
    if (!ft_strcmp(split[0], "size"))
    {
      if (!is_number(split[1]) || (params->size = ft_atoi(split[1])) < 3)
      {
        ft_putstr("Bad parameter size, should be a number upper than 3: ");
        ft_putendl(split[1]);
        ft_exit("Usage: ./npuzzle (size=[3-∞] OR file=[filename]) AND heuristic=[123]");
      }
    }
    else if (!ft_strcmp(split[0], "file"))
    {
      if ((fd = open(split[1], O_RDONLY)) == -1)
      {
        ft_putstr("Invalid file name: ");
        ft_exit(split[1]);
      }
      while ((ret = get_next_line(fd, &line)) == 1)
        add_to_tab(&params->input, line);
      if (ret == -1)
        ft_exit("Unexpected error while reading file.");
      params->size = extract_size(&params->input);
    }
    else if (!ft_strcmp(split[0], "heuristic"))
    {
      if (!is_number(split[1]) || (params->heuristic = ft_atoi(split[1])) > 3 || params->heuristic < 1)
      {
        ft_putstr("Bad parameter heuristic, should be a number between 1 and 3: ");
        ft_putendl(split[1]);
        ft_exit("Usage: ./npuzzle (size=[3-∞] OR file=[filename]) AND heuristic=[123]");
      }
    }
    else
    {
        ft_putstr("Illegal option: ");
        ft_putendl(av[i]);
        ft_exit("Usage: ./npuzzle (size=[3-∞] OR file=[filename]) AND heuristic=[123]");
    }
    clean_tab(split);
    i++;
  }
  if (!params->size && !params->input)
  {
    ft_putendl("Parameter size missing.");
    ft_exit("Usage: ./npuzzle (size=[3-∞] OR file=[filename]) AND heuristic=[123]");
  }
  else if (!params->heuristic)
  {
    ft_putendl("Parameter heuristic missing.");
    ft_exit("Usage: ./npuzzle (size=[3-∞] OR file=[filename]) AND heuristic=[123]");
  }
  return (params);
}
