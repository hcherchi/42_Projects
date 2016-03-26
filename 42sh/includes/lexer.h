/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 20:45:33 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/15 12:47:04 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include <libft.h>

typedef enum			e_enum_token
{
	WORD,
	SEMI,
	OR,
	AND,
	REDIR,
	PIPE,
	BACK_QUOTE,
	PARENT_O,
	PARENT_C,
	SIMPLE_QUOTE,
	DOUBLE_QUOTE,
	ENDL,
	END_OF_TOKEN
}						t_enum_token;

typedef struct			s_matcher
{
	t_enum_token		type;
	int					(*match_token)(char *);
}						t_matcher;

typedef enum			e_enum_redir
{
	R_SIMPLE = 1,
	R_DOUBLE = 2,
	L_SIMPLE = 3,
	L_DOUBLE = 4,
}						t_enum_redir;

typedef struct			s_redir
{
	int					type;
	int					from;
}						t_redir;

typedef struct			s_token
{
	t_enum_token		type;
	void				*content;
	struct s_token		*next;
	struct s_token		*prev;
}						t_token;

int						check_match_quote(char *str);

void					add_token(t_token **t, void *cont, t_enum_token tp);
void					push_valid_token(t_token **head, t_token *new_token);
t_redir					*parse_new_redir(char *str);
t_redir					*new_redir(int from, t_enum_redir type);
int						parse_token_quote(t_token **token_l,
						char *line, int i);

int						is_semi(char *line);
int						is_or(char *line);
int						is_pipe(char *line);
int						is_and(char *line);
int						is_back_quote(char *line);
int						is_parent_c(char *line);
int						is_parent_o(char *line);
int						is_simple_quote(char *line);
int						is_double_quote(char *line);

int						is_redir(char *line);
int						is_r_simple(char *line);
int						is_r_double(char *line);
int						is_l_simple(char *line);
int						is_l_double(char *line);

int						backquote_ctrl(t_token *token);
int						parenthesis_ctrl(t_token *token);
int						is_token(char *str);
int						parse_token(t_token **token_list, char *str);
void					cut_word(t_token **token_list, char *line, int lenght);
void					fill_token_list(char *line, t_token **token_list);

int						check_lexer(t_token *token_list);
int						syn_error(t_enum_token type);
int						syn_redir(t_token *token);

t_token					*rebuild_quotes(t_token *head);

#endif
