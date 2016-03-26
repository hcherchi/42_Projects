/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:08:57 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/06 17:11:18 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "lexer.h"
# include "ftsh.h"

typedef enum			e_node_type
{
	NODE_SEP_AND,
	NODE_SEP_NOR,
	NODE_SEP_THEN,
	NODE_CMD,
	NODE_PIPE,
	NODE_SUBSHELL,
	NODE_HEREDOC
}						t_node_type;

# define REDIR_MODE_APPEND 0xF0
# define REDIR_MODE_TRUNCAT 0xF
# define RIGHT 0
# define LEFT 1
# define B_QUOTE 1
# define STRING 2

typedef	struct			s_connect
{
	t_enum_redir		type;
	int					fd;
	char				*label;
	int					from;
	int					to;
	struct s_connect	*next;
}						t_connect;

typedef	struct			s_arg
{
	int					type;
	void				*data;
	struct s_arg		*next;
	struct s_arg		*prev;
}						t_arg;

typedef struct			s_node_cmd
{
	char				**cmd;
	int					ac;
	t_arg				*arg;
	t_env				*env;
	t_connect			*connect;
}						t_node_cmd;

typedef struct			s_parser
{
	t_node_type			type;
	void				*data;
	struct s_parser		*left;
	struct s_parser		*right;
}						t_parser;

t_parser				*parser_controller(t_token *tail);
/*
** func for build and free the parser tree
*/
t_node_cmd				*new_node_cmd(t_arg *arg_liste, t_connect *connec);
t_parser				*new_node_parser(int type, void *data);
void					add_node_parser(t_parser **h, t_parser *n, char mod);
int						del_tree_parser(t_parser *ptr);
int						del_one_parser(t_parser **ptr);
int						built_parser_tree(t_token *head);
t_parser				*read_token(t_token *ptr);
void					read_untill_cmd(t_token **ptr, t_parser **new);

/*
** func for struct arg
*/
t_arg					*new_arg(int type, void *content);
void					add_arg(t_arg **head, t_arg *new);
t_arg					*bquote_controller(t_token **ptr);

/*
** func for struct connect
*/
int						is_aggr(char *word);
void					redir_spotted(t_token **ptr,
							t_connect **connect_l, t_token **token_l);
t_connect				*new_connect_l(t_token **ptr);
void					add_connect(t_connect **connect_l,
							t_redir *redir, char *label);

/*
** functions to build a node of parser from a liste of token
*/
t_arg					*token_to_cmd(t_token *ptr);
int						escape_char_in_quote(char *str);
int						escape_char_without_quote(char *str);
char					*quotes_concat(t_token **token_liste);

/*
** booleans
*/
int						is_separator(int type);
int						parser_is_quote(int type);
int						parser_is_parent(int type);
int						is_simp_doub_quote(t_token *x);
int						is_quote_sticky(t_token *x);

/*
** tools
*/
int						go_tail(t_token **ptr);
int						go_head(t_token **ptr);
int						del_token_liste(t_token *head);
int						del_one_token(t_token *ptr);
int						split_liste(t_token **head, t_token **r, t_token **l);
int						cmd_wiv_bquote(t_arg *ptr);
t_parser				*parenthesis_controller(t_token **liste);
int						display_arg_list(t_arg *arg);
int						display_parser_level(t_parser *parser, int level);
int						display_token_liste(t_token *ptr);

#endif
