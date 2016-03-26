/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:13:54 by jhoudan           #+#    #+#             */
/*   Updated: 2016/02/19 20:41:57 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include "read_next_line.h"
# define BUFF_SIZE 32
# define MAX_FD 10
# define PRED "\x1b[31m"
# define PGREEN "\x1b[32m"
# define PYELLOW "\x1b[33m"
# define PBLUE "\x1b[34m"
# define PMAGENTA "\x1b[35m"
# define PCYAN "\x1b[36m"
# define PLRED "\x1b[1;31m"
# define PLGREEN "\x1b[1;32m"
# define PLYELLOW "\x1b[1;33m"
# define PLBLUE "\x1b[1;34m"
# define PLMAGENTA "\x1b[1;35m"
# define PLCYAN "\x1b[1;36m"
# define PRESET "\x1b[0m"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_btree
{
	void			*item;
	struct s_btree	*right;
	struct s_btree	*left;
}					t_btree;

typedef struct		s_input
{
	char			str[BUFF_SIZE + 1];
	int				fd;
}					t_input;

typedef struct		s_part
{
	unsigned long	mantisa : 52;
	unsigned long	exponent : 11;
	unsigned long	sign : 1;
}					t_part;

union				u_double
{
	double			d;
	t_part			parts;
	unsigned long	u;
};

typedef struct		s_printf
{
	char			is_zero;
	size_t			nbr_zero;
	char			is_minus;
	size_t			nbr_minus;
	char			is_plus;
	char			is_space;
	size_t			nbr_space;
	char			is_hash;
	char			is_preci;
	int				nbr_preci;
	char			is_field;
	int				nbr_field;
	char			*modifier;
	char			*instr;
	int				*count;
	char			conversion;
	int				print;
}					t_printf;

/*
** FONCTION DE LISTE
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lst_push_back(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lst_strsplit(char const *s, char c);

/*
** FONCTION ARBRE BINAIRE
*/
t_btree				*btree_create_node(void *item);
int					btree_level_count(t_btree *root);
void				btree_apply_infix(t_btree *root, void (*applyf)(void *));
void				btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void				btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void				btree_insert_data(t_btree **root,
		void *item, int (*cmp)(void*, void*));
void				*btree_search_item(t_btree *root,
		void *data_ref, int (*cmpf)(void *, void*));

/*
** FONCTION STRING
*/
void				ft_strclr(char *s);
void				ft_strdel(char **as);
void				ft_tabdel(void ***tab);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t n);
int					strlen_wchar(wchar_t *str);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_get_index(char *str, char c);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strtrim(char const *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *s, char c);
char				**ft_strnsplit(char const *s, char c, int nbrest);
char				**ft_init_char_tab(int size);
int					ft_strlower(char *str);
int					ft_strupper(char *str);
char				*add_str(char *line, char *str);
char				*add_char(char *line, char c);

/*
** BOOLEENS
*/
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isnumber(char *str);

/*
** FICHIER
*/
int					get_next_line(int const fd, char **line);

/*
** MANIP DE MEMOIRE
*/
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);

/*
** INT AND CO
*/
int					ft_atoi(const char *str);
int					count_nb_octet(wchar_t letter);
int					count_significant_bit(int value);
char				*ft_itoa(int n);
char				*ft_itoa_base(long long int value, int base);
char				*ft_uitoa_base(unsigned long long int value, int base);
void				ft_bsort(int *array, int size);

/*
** AFFICHAGE
*/
int					ft_printf(const char *format, ...);
int					ft_putchar(char c);
int					ft_putstr(const char *s);
int					ft_putwchar(wchar_t letter);
int					ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(const char *s, int fd);
void				ft_putnbr(int n);
void				ft_putendl(const char *s);
void				ft_putnbr_fd(int n, int fd);
int					ft_putendl_fd(const char *s, int fd);

/*
** FONCTIONS POUR PRINTF
*/
int					ptf_process_colors(char *str, int *count);
int					ptf_process_conversion(char *str, va_list ap, int *count);
void				ptf_process_instruction(t_printf *ptr, va_list ap);
int					ptf_flag_control(t_printf *ptr, int index);
int					ptf_preci_field_controller(t_printf *ptr, int index,
		va_list ap);
void				ptf_modifier_controller(t_printf *ptr, char *modif);
void				ptf_controller_di(t_printf *ptr, va_list ap);
void				ptf_controller_u(t_printf *ptr, va_list ap);
void				ptf_controller_b(t_printf *ptr, va_list ap);
void				ptf_controller_o(t_printf *ptr, va_list ap);
void				ptf_controller_xp(t_printf *ptr, va_list ap);
void				ptf_controller_cs(t_printf *ptr, va_list ap);
void				ptf_controller_f(t_printf *ptr, va_list ap);
void				ptf_controller_a(t_printf *ptr, va_list ap);
void				ptf_controller_e(t_printf *ptr, va_list ap);
void				ptf_controller_n(t_printf *ptr,
		va_list ap, int count);
void				ptf_printfwstr(t_printf *ptr, wchar_t *str);
void				ptf_print_f(double nbr, t_printf *ptr);
int					ptf_is_flag(char *instr);
int					ptf_is_preci(char *instr);
int					ptf_is_modifier(char *instr);
void				ptf_print_float(float nbr, t_printf *ptr);
void				ptf_print_field_c(t_printf *ptr);
void				ptf_print_flag_c(t_printf *ptr);
void				ptf_print_field_e(t_printf *ptr, double nbr);
void				ptf_print_flag_e(t_printf *ptr, int *check);
void				ptf_print_field_f(t_printf *ptr, double nbr);
double				ptf_print_flag_f(t_printf *ptr, double nbr);
void				ptf_pad_after(t_printf *ptr, int length);
void				recu_print_time(unsigned long int time,
		int index, t_printf *ptr);
/*
** FONCTIONS POUR 42sh
*/
char				*ft_realloc(char *str, int n);
int					match(char *s1, char *s2);

#endif
