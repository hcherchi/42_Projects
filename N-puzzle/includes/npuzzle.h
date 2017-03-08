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
#include <time.h>

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
  int index;
  t_pos *pos;
  struct s_state *next;
  struct s_state *parent;
  struct s_state *child;
}               t_state;

typedef struct s_param
{
  char **input;
  int size;
  t_state *start;
  t_state *end;
  int heuristic;
}             t_param;



/* PARAMS HANDLING */

t_param *get_params(int ac, char **av);
int extract_size(char ***input);

/* PARSING */

int **get_grid(char **input, int size);
int *get_line(char *line, int size, int *tab);
int is_solvable(int **start, int **end, int size);

/* ALGO */

void resolve(t_param *params);
t_state *search_best(t_state *l_states);
int ***expand(t_state *state, int size);
t_state *get_final_path(t_state *l_states);

/* HEURISTICS */

int h_man(int **grid1, int **grid2, int size);
int h_misplaced(int **grid1, int **grid2, int size);
int   h_row_column(int **grid1, int **grid2, int size);

/* FINAL STATE */

int **get_final_grid(int size);

/* GRID GENERATOR */

int **get_random_grid(int size);

/* HELP PARSING */

void ft_exit(char *str);
int is_good_number(int nb, int *tab, int size);
int is_number(char *nbr);
int is_comment(char *str);
void add_to_tab(char ***tab, char *to_add);

/* PRINTING */

void print_statistics(int max, int nbstates, int moves);
void print_state(t_state *state, int size);
void print_list(t_state *l_states, int size);
void print_solution(t_state *l_states, int size);

/* INITIALIZATION */

int *new_tab(int size, int nb);
int **new_grid(int size);

/* CLEANING */

void clean_state(t_state *state, int size);
void clean_tab(char **tab);
void clean_grid(int **grid, int size);
void clean_params(t_param *params);
void clean_list(t_state *l_state, int size);
void clean_state(t_state *state, int size);

/* LIST HANDLING */

t_state *new_state(int **grid, t_state *parent, t_param *params);
int list_size(t_state *l_states);
void add_state(t_state **l_states, t_state *to_add);
int remove_state(t_state **l_states, int index);
void add_state_to_begin(t_state **l_states, t_state *to_add);

/* HELPERS */

int **grid_copy(int **grid, int size);
int *get_flat_grid(int **grid, int size);
t_pos *get_pos(int nb, int **grid, int size);
int   is_same(int **grid1, int **grid2, int size);
t_state   *find_in(t_state *l_states, int **grid, int size);
int **rotate(int **grid, int size);
void swap(int *tab, int a, int b);


#endif
