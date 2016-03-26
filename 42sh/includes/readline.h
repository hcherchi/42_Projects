/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:27:32 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/14 13:07:06 by sdelardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H
# include <libft.h>
# include <term.h>
# include <curses.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>

typedef struct		s_com
{
	int				size;
	int				index;
	int				dir;
	char			*name;
	struct s_com	*next;
}					t_com;

typedef struct		s_completion
{
	t_com			*head;
	t_com			*tail;
	int				max;
}					t_completion;

typedef struct		s_his
{
	int				index;
	char			*cmd;
	struct s_his	*next;
	struct s_his	*prev;
}					t_his;

typedef struct		s_history
{
	t_his			*head;
	t_his			*tail;
}					t_history;

typedef struct		s_readline
{
	t_completion	*completion;
	t_his			*current;
	size_t			i;
	char			*line;
	char			*line_before;
	char			*save;
	int				width;
	char			*prompt;
	int				comp;
}					t_readline;

/*
**History
*/
void				ft_sig_int(int sig);
void				keyboard_cut(t_readline *r);
void				keyboard_copy(t_readline *r);
void				keyboard_paste(t_readline *r);
void				keyboard_print(long key, t_readline *r);
char				*add_char_to_str(t_readline *r, long key);
t_history			*init_history(void);
t_his				*create_history(int i, char **line);
t_his				*read_history(t_his **head, t_his *tail);
int					save_history(t_his *head);

t_readline			*init_readline(char *prompt);
char				*ft_readline(t_readline *r);
int					ft_outc(int c);
void				default_terminal_mode(void);
int					raw_term_mode(void);
void				delete_reader(void);

void				del_char_to_str(t_readline *r);
int					is_special_key(long key);
void				controller_key(t_readline *r, long key);
int					ft_outc(int c);
void				default_terminal_mode(void);
int					raw_term_mode(void);
void				keyboard_left(t_readline *r);
void				keyboard_right(t_readline *r);
void				keyboard_delete(t_readline *r);
void				keyboard_ctrlc(t_readline *r);
void				keyboard_home(t_readline *r);
void				keyboard_ctrld(t_readline *r);
void				keyboard_end(t_readline *r);
void				keyboard_left_word(t_readline *r);
void				keyboard_right_word(t_readline *r);
void				up_arrow(t_readline *r);
void				down_arrow(t_readline *r);
int					is_quote_r(char c);
int					quotes(t_readline *r);
char				*add_char_without_print(t_readline *r, long key);
int					return_line(t_readline *r);
void				go_up(t_readline *r);
void				go_down(t_readline *r);
void				clean_line(t_readline *r);
void				go_to_end(t_readline *r);
void				newline_history(t_history *history);
char				*line_proper(char **str);
void				print_line(t_readline *r);
void				resize(int status);
void				reprint_resize(t_readline *r);
void				replace_line(t_readline *r);
void				reset_reader(t_readline *r);
int					last_line(t_readline *r);
int					detect_identical_lines(void);
int					count_backslash(t_readline *r);
int					only_b(t_readline *r);
int					is_escaped(t_readline *r, int i);

/*
**Completion
*/
void				completion(t_readline *r);
int					is_special_char(char c);
t_com				*new_maillon_completion(char *name);
void				clear_completion_list(t_readline *r);
void				print_completion_list(t_readline *r);
void				print_completion(t_readline *r);
int					remplissage_completion(char *s, char *p, t_readline *r);
char				*create_part_of_line(t_readline *r);
char				*part_of_line(t_readline *r);
char				*string_sub_path(char *str, int j);
char				*string_sub_str(char *str, int j);
char				*search_path(char **str);
int					is_dir(char *path, char *name);

/*
**Resize
*/
void				add_newline_str(t_readline *r, long key, int i);
int					max_line_size(t_readline *r, int *i);

#endif
