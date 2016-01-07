/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 17:05:56 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/07 17:06:37 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>

void	ft_setenv(char ***myenv, char *av1, char *av2);
char	**add_tab(char **tab, char *elem);
void	ft_unsetenv(char ***myenv, char **av);
char	**remove_tab(char **tab, char *elem);
void	ft_cd(char ***myenv, char **av);
char	*cdsplit(char *cdsplit, char *home);
void	cd_error(char *newpath, char **home);
void	execute(char **myenv, char **av, char *good_path);
void	set_commands(char ***myenv, char **av);
void	run_command(char *command, char ***myenv, char **av);
void	select_command(char **av, char ***myenv);
char	*get_elem(char **env, char *elem);
int		select_path(char *paths, char *elem, char **good_path);
char	*get_name(char *line);
void	lvlup(char ***myenv);
char	*strchange(char *str, char c, char *str2);
int		permission(char *path);
char	*add_path(char *p, char *n, char c);
char	*del_path(char *s);
void	ft_puttab(char **tab);
int		tablen(char **tab);
char	**tab_dup(char **env);
void	tabdel(char ***tab);
void	prompt(char *home);
#endif
