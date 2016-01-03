/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:03:56 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/30 17:39:17 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <sys/types.h>
# include <grp.h>
# include <time.h>
# include <string.h>

typedef struct		s_data
{
	char			*path;
	char			*mod;
	char			*nblink;
	char			*uid;
	char			*gid;
	char			*nboct;
	long long		nb_blocks;
	char			*name;
	time_t			time;
	char			*namelk;
}					t_data;

typedef struct		s_file
{
	t_data			*data;
	struct s_file	*next;
}					t_file;

typedef struct		s_option
{
	int	rmaj;
	int	l;
	int a;
	int	r;
	int	t;
	int	p;
	int	f;
	int g;
	int	h;
}					t_option;

typedef struct		s_args
{
	t_option		*opt;
	t_file			*files;
	t_file			*dirs;
	int				onlyonedir;
	int				nofile;
	int				error;
}					t_args;

void				hoption(void);
void				putlink(t_file *l_files);
void				putpath(t_file *l_files);
void				argsdel(t_args *args);
void				ft_error3(char *path);
void				check_file(char *av, t_args *args);
void				init_args(t_args *args);
void				print_files(t_file *l_files, t_option *opt);
void				check_options(char *av, t_args *args);
void				modif_options(char *av, t_args *args);
void				ft_error(char c);
void				ft_error2(char *av);
void				recursive(char *path, t_option *opt);
void				extend_print(t_file *l_files, t_option *opt);
void				basic_print(t_file *l_files, t_option *opt);
char				*getlink(t_file *file);
t_file				*init_files(char *path, t_option *opt);
void				add_file(t_file **alist, t_file *new);
t_file				*new_file(char *path);
t_file				*fill_file(struct stat *stats, t_file *new);
char				*add_path(char *path, char *name);
void				l_filesdel(t_file *l_files);
void				delone(t_file **l_files);
void				ft_putstrsp(char *str);
int					instr(char *str, char c);
void				swap_files(t_file *f1, t_file *f2);
void				reverse(t_file **l_files);
void				sort_time(t_file **l_files);
void				choose_sort(t_file **l_files, t_option *opt);
void				ft_ls_files(t_args *args);
void				ft_ls_dirs(t_args *args);
t_file				*split(t_file *l_files);
t_file				*fusion_ascii(t_file *lg, t_file *ld);
t_file				*fusion_time(t_file *lg, t_file *ld);
void				sort_ascii(t_file **l_files);

#endif
