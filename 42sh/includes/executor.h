/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:08:20 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/14 10:56:50 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H
# include "parser.h"
# include "ftsh.h"
# define SUCCESS		0
# define FAILURE		1
# define CD_ERR_OPTION	1
# define CD_ERR_OLDPWD	2
# define CD_ERR_HOME	3
# define CD_ERR			4

typedef	struct		s_read_opt
{
	int				s;
	int				r;
	char			*a;
	char			*p;
	int				n;
	char			d;
	char			**name;
	int				error;
	int				k;
}					t_read_opt;

/*
** BUILTINS
*/
int					exec_builtin(t_parser *parser);
int					is_builtin(t_node_cmd *node);
int					echo_builtin(t_node_cmd *node);
int					exit_builtin(t_node_cmd *node);
int					cd_builtin(t_node_cmd *node);
int					env_builtin(t_parser *parser);
int					unsetenv_builtin(t_node_cmd *node_cmd);
int					setenv_builtin(t_node_cmd *node_cmd);
int					localvar_builtin(t_parser *parser);
int					history_builtin(t_node_cmd *cmd);
int					read_builtin(t_node_cmd *cmd);

/*
** READ
*/
char				*set_line(t_read_opt *opt);
char				*get_line(t_read_opt *opt);
void				array_mode(t_read_opt *opt, char *line);
void				simple_mode(t_read_opt *opt, char *line);
void				check_options_read(t_read_opt *opt, t_node_cmd *node);
void				fill_read_opt(t_read_opt *opt, t_node_cmd *node);
char				*add_char(char *str, char c);
void				modif_option_read(t_read_opt *opt, t_node_cmd *node);

/*
** ENV
*/
t_env				*new_entry(char *key, char *val);
int					set_env(t_env **env, char *key, char *val);
void				set_env_keyval(t_env **env, char *keyval);
int					unset_env(t_env **env, char *key);
char				*get_env(t_env *env, char *key, int dup);
void				print_env(t_node_cmd *node, t_env *env);
void				print_env_usage(t_node_cmd *node);
t_env				*env_tab_to_lst(char **tabs);
char				**env_lst_to_tab(t_env *env);
void				del_env(t_env **env);
t_env				*dup_env(t_env *env);

/*
** ENV BUILTIN
*/
char				**update_cmd(char **old_cmd, int command_index);
int					handle_env_opt(t_node_cmd *node, int *it);
int					is_env_opt(char *arg);
int					print_setenv_usage(t_node_cmd *node);

/*
** HISTORY
*/
t_his				*new_his_node(int index, char *cmd);
void				add_his(t_his *new);
int					del_his(void);
void				pop_his_node(t_his *node);
int					print_history(void);
int					recu_print_his(int index, t_his *ptr);
int					history_d(char *str);
int					history_a(char **cmd, int *i);
int					history_w(char **cmd, int *i);
int					history_r(t_node_cmd *node, int *i);
int					history_s(t_node_cmd *node);

/*
** EXPORT
*/
int					export_builtin(t_node_cmd *node);
int					set_local_var(char *var, char *val, int dup);
int					unset_var(char *key);
int					print_vars(t_node_cmd *node);
int					export_var(char *var, char *val);
int					export_bad_id(t_node_cmd *node, int i);
int					unset_builtin(t_node_cmd *node);
int					bad_delim(t_node_cmd *cmd, int i);

/*
** CD BUILTIN
*/
char				*build_path(char *filename);
void				handle_next_dir2(char *filename,
						char *path, int *cursor, int *i);
void				handle_next_dir(char *filename,
						char *path, int *cursor, int *i);
char				*rel_path(char *filename);
int					cat_until_slash(char *dst, char *src);

int					cd_error_msg(t_node_cmd *node, int err, char *msg);
int					cd_to_home(t_node_cmd *node);
int					cd_to_old_pwd(t_node_cmd *node);
int					cd_to_dir(t_node_cmd *node, int argindex, char opt);

/*
** EXCLAMATION MARK
*/
int					mark_checker(void);
int					mark_controller(char *instr, char **src);
char				*mark_substitution(char **instr, char **cmd);
char				*mark_event_designator(char *str, char *src);
char				*mark_word_designator(char **instr, char *cmd);
char				*mark_modifier(char **instr, char **cmd);
char				*histo_match(char *str);

/*
** EXEC
*/
int					exec_node(t_parser *parser);
int					exec_fork(t_parser *parser);
int					exec_child(t_parser *parser);
int					exec_pipe(t_parser *parser);
void				connect(int pipefd[2], int father);

int					redirections(t_connect *connect, int dup);
void				handle_connect(t_connect *connect);
void				handle_r_simple(t_connect *connect);
void				handle_r_double(t_connect *connect);
void				handle_l_simple(t_connect *connect);
int					is_aggr(char *word);

int					get_stderr(t_node_cmd *node);
int					get_stdout(t_node_cmd *node);

char				*relative_path(char *cmd);
int					is_exec(char *filename);
char				*find_cmd_in_path(char *cmd, char **path);
char				*get_path(t_node_cmd *node);
int					err_cmd_not_found(t_node_cmd *node);
void				handle_child_ret(int ret);

/*
** ARGS
*/
char				**tab_from_arglist(t_arg *arglist);
t_arg				*new_cmd_arg(char *arg);
void				stick_end_list(t_arg **list_to_iter, t_arg *rest);
void				rebuild_arglist(t_node_cmd *node);
int					replace_env_var(char **str);

t_arg				*list_from_backquote(t_parser *backquote);
void				add_tab_to_list(t_arg **list, char **tabs);
void				add_arg_to_list(t_arg **list, char *arg, int reset);
int					tabsize(char	**tabs);
t_arg				*args_from_string(char *word);
t_arg				*alias_arglist(t_arg *cmd, t_arg *next);
void				handle_closes(t_connect *connect);

/*
** ALIAS
*/
int					alias_builtin(t_node_cmd *node);
int					print_aliases(void);
int					update_alias(char *key, char *val);
int					set_alias(char *arg);
void				print_alias(char *key);
char				*get_alias(char *cmd);
int					unalias_builtin(t_node_cmd *node);

int					expand_tilde(char **str);

int					insert_string(char **str, int beg, int end, char *insert);
void				move_to_next_cmd(char *str, int *i);
int					expand_alias(char **str, int i, char *expanded);
char				*get_next_word(char *str, int beg);
int					expand_aliases(char **str, int i);
int					is_special(char c);
#endif
