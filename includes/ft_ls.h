/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 16:03:56 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/15 12:15:13 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../libft/includes/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <sys/types.h>
# include <grp.h>
# include <time.h>
# include <string.h>
# include <bsd/string.h>

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
	char			*time;
	char			*namelk;
}	t_data;

typedef struct		s_file
{	
	t_data			*data;
	struct s_file	*next;
	struct s_file	*prev;
}					t_file;
void				ft_error(int i, char c);
void				print_files(t_file *t_files, char *option);
void				ft_ls(char *path, char *options);
void				extend_print(t_file *l_files);
void				basic_print(t_file *l_files);
char				*getlink(t_file *file);
t_file				*init_files(char *path, char *options);
void				add_file(t_file **alist, t_file *new);
t_file				*new_file(struct dirent *info, char *path);
char				*add_path(char *path, char *name);
void				l_filesdel(t_file *l_files);
void				delone(t_file **l_files);
void				ft_putstrsp(char *str);
int					instr(char *str, char c);
void				swap_files(t_file *f1, t_file *f2);
t_file 				*sort_ascii(t_file * l_files);
#endif
