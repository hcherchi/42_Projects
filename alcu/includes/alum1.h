/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjean-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 00:30:05 by wjean-ma          #+#    #+#             */
/*   Updated: 2015/12/21 18:48:29 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# define BUF_SIZE 4096

typedef struct		s_line
{
	int				nb;
	struct s_line	*next;
}					t_line;

int					ft_menu(void);
int					valid_file(char *buf);
int					check_digit(char *buf, int i);
void				add_line(t_line **alist, int nb);
int					nb_lines(char *buf);
t_line				*init_lines(char *buf);
void				print_lines(t_line **lines);
void				reverse(t_line **lines);
int					ask_nb(t_line *lines);
void				multiputstr(char *str, int nb);
void				play(t_line *lines, int i);
void				delone(t_line **alines);
void				remove_al(t_line **lines, int nb);
int					al_count(t_line *lines);
void				print_name(int i);
void				playia(t_line *lines);
void				player(t_line *lines);
int					ia(t_line *lines);
char				*read_file(ssize_t buf_size, char *av);
ssize_t				get_ssize_file(char *av);
char				*standard_input(void);

#endif
