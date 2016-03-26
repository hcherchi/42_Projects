/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 19:55:54 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/20 14:17:37 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <parser.h>
#include <lexer.h>
#include <executor.h>

int		get_init_file(char *filename)
{
	char	*init_files;
	int		init_fd;

	if (!get_env(g_shell->env, "HOME", 0))
		return (-1);
	if (filename == NULL)
		init_files = ft_strjoin(get_env(g_shell->env, "HOME", 0), "/.42shrc");
	else
		init_files = ft_strdup(filename);
	if (init_files == NULL)
		return (-1);
	init_fd = open(init_files, O_RDONLY);
	free(init_files);
	return (init_fd);
}

void	read_init_file(int fd)
{
	char	*line;
	t_token	*token_l;
	int		i;
	char	*nbr;

	i = 1;
	while (get_next_line(fd, &line) == 1)
	{
		token_l = NULL;
		fill_token_list(line, &token_l);
		if (process_cmd(token_l) != 0)
		{
			ft_putstr_fd("42sh: error in init_file at line ", STDERR_FILENO);
			nbr = ft_itoa(i);
			ft_putendl_fd(nbr, STDERR_FILENO);
			free(nbr);
			ft_putendl_fd(line, STDERR_FILENO);
		}
		free(line);
		++i;
	}
}

int		load_init_file(char *filename)
{
	int		fd;

	if ((fd = get_init_file(filename)) != -1)
		read_init_file(fd);
	else
		return (FAILURE);
	return (SUCCESS);
}
