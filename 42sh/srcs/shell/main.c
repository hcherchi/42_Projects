/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 19:56:02 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/15 13:26:50 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <parser.h>
#include <lexer.h>
#include <executor.h>
#include <readline.h>

t_shell		*g_shell = NULL;

static int	get_user_cmd(void)
{
	if (isatty(0) == 1)
	{
		print_prompt();
		g_shell->reader = init_readline("> ");
		if (!g_shell->reader)
			return (0);
		g_shell->reader->line = ft_readline(g_shell->reader);
		g_shell->reader->line = line_proper(&(g_shell->reader->line));
	}
	else
	{
		g_shell->reader = init_readline("");
		if (get_next_line(0, &g_shell->reader->line) != 1)
			exit(0);
		g_shell->reader->line = line_proper(&(g_shell->reader->line));
	}
	if (!g_shell->reader->line || (g_shell->reader->line)[0] == '\0')
	{
		delete_reader();
		return (0);
	}
	if (check_match_quote(g_shell->reader->line) || mark_checker())
		return (0);
	return (1);
}

int			process_cmd(t_token *token_l)
{
	t_parser	*parser;
	t_token		*rebuild;
	int			cmd_ret_value;
	int			cmd_ret;

	rebuild = rebuild_quotes(token_l);
	del_token_liste(token_l);
	if (check_lexer(rebuild) == 0)
	{
		if ((parser = parser_controller(rebuild)) == NULL)
			return (0);
		cmd_ret = exec_node(parser);
		if (cmd_ret > 128)
			cmd_ret_value = cmd_ret >> 8;
		else if (cmd_ret > 0)
			cmd_ret_value = 128 + cmd_ret;
		else
			cmd_ret_value = cmd_ret;
		set_env(&g_shell->l_env, "?", ft_itoa(cmd_ret_value));
		del_tree_parser(parser);
		return (0);
	}
	return (1);
}

static void	catch_ctrlz(int status)
{
	status++;
}

static int	expand_cmd(void)
{
	expand_aliases(&g_shell->reader->line, 0);
	expand_tilde(&g_shell->reader->line);
	return (check_match_quote(g_shell->reader->line));
}

int			main(void)
{
	t_token *token_l;

	signal(SIGTSTP, catch_ctrlz);
	signal(SIGQUIT, catch_ctrlz);
	signal(SIGINT, &sigint_handler);
	init_shell();
	load_init_file(NULL);
	while (g_shell->running)
	{
		token_l = NULL;
		if (!get_user_cmd())
			continue ;
		if (isatty(0) == 1)
			newline_history(g_shell->history);
		if (expand_cmd())
			continue ;
		fill_token_list(g_shell->reader->line, &token_l);
		signal(SIGINT, sigint_child);
		process_cmd(token_l);
		signal(SIGINT, &sigint_handler);
		delete_reader();
		reset_reader(g_shell->reader);
	}
	return (exit_shell());
}
