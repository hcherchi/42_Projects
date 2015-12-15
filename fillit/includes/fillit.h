/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:22:10 by bgantelm          #+#    #+#             */
/*   Updated: 2015/12/09 15:34:47 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define BUF_SIZE 4096

typedef struct	s_clean
{
	int			w;
	int			h;
	char		**tab_piece;
	char		let;
	int			x;
	int			y;
}				t_clean;

int				countdieze(char *pieces, int i);
int				test_nbline(char *piece);
int				test_nbcol(char *piece);
int				test_sizemin(char *pieces, size_t i);
int				test_struct(char *pieces);
int				test_char(char *pieces);
int				test_forme(char *pieces);
char			*test_file(char *str);
int				test_general(char *pieces);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putstr(char *str);
void			ft_putchar(char c);
void			ft_putnbr(int n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				width(int *lim_upleft, char **tab_piece);
int				height(int *lim_upleft, char **tab_piece);
char			**split_piece(char *piece);
char			***split_pieces(char *pieces);
int				nb_pieces(char *pieces);
t_clean			cut_piece(char **tab_piece);
t_clean			*init_struct(char *pieces, int nb);
char			**init_sol(int size);
int				start_square(t_clean *struct_pieces, int nb);
int				find_sqroot(int n);
t_clean			*init_struct(char *pieces, int nb);
int				avance(t_clean *struct_pieces, int size, int i, char **sol);
int				ok_toput(char **sol, t_clean cut_piece);
void			put_piece(char **sol, t_clean cut_piece);
void			clean(char **sol, char c, int size);
void			resol(char **sol, t_clean *struct_pieces, int nb, int size);
void			ft_print_sol(char **sol, int size);

#endif
