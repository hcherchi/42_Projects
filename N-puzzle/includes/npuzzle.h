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

#ifndef TEST_H
# define TEST_H

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct s_pos
{
  int i;
  int j;
}               t_pos;

typedef struct s_state
{
  int   **grid;
  int   h;
  int   g;
  int size;
  int index;
  t_pos *pos;
  struct s_state *next;
  struct s_state *parent;
}               t_state;

int *new_tab(int size);
void ft_exit(char *str);

int is_comment(char *str);
int is_number(char *nbr);
int is_good_number(int nb, int *tab, int size);

void skip_comments(int fd, char **line);

int check_line(char *line, int size, int *tab);
int check_first_line(char *line);
int check_input(int fd);

int **get_grid(int fd, int size);
int *get_line(char *line, int size);
int **get_final_grid(int size);

int **new_grid(int size);
int *new_tab(int size);

void clean_tab(char **tab);

int **grid_copy(int **grid, int size);

void print_grid(int **grid, int size);
void print_state(t_state *state);

t_state *search_best(t_state *l_states);
int   is_same(t_state *state1, int **grid);
t_state *new_state(int **grid, t_state *parent, t_state *end);
void add_state(t_state **l_states, t_state *to_add);
t_state *is_in(t_state *l_states, int **grid);
void clean_state(t_state *state);
void remove_state(t_state **l_states, int index);

int get_dist(int nb, t_state *state, t_state *end);
int h_man(t_state *state, t_state *end);
t_pos *get_pos(int nb, t_state *state);

void resolve(t_state *start, t_state *end);
int ***expand(t_state *state);
void print_list(t_state *l_states);

#endif
