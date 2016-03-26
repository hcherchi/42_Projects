/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:08:29 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/20 13:08:08 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTSH_H
# define FTSH_H
# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline.h>
# include <lexer.h>
# define DEFAULT_TERM "xterm-256color"

typedef struct		s_env
{
	char			*key;
	char			*val;
	struct s_env	*next;
}					t_env;

typedef struct		s_shell
{
	t_readline		*reader;
	int				running;
	int				exit_value;
	t_env			*env;
	t_env			*l_env;
	t_env			*aliases;
	t_history		*history;
	char			*pwd;
}					t_shell;

extern t_shell		*g_shell;

int					init_shell(void);
int					exit_shell(void);
int					print_prompt(void);

int					load_init_file(char *filename);
void				read_init_file(int fd);
int					get_init_file(char *filename);
int					process_cmd(t_token *token_l);
void				sigint_child(int signum);
void				sigint_handler(int signum);
#endif
