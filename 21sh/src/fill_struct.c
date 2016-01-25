/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:10:39 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 19:56:08 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	fill_struct(t_command *new, char *subcommand, char *paths)
{
	char	*subcmdl;
	char	*subcmdr;
	int		*piperight;

	piperight = malloc(sizeof(*piperight) * 2);
	split_redir(subcommand, &subcmdl, &subcmdr);
	new->piperight = piperight;
	new->args = ft_supersplit(subcmdl, ' ', '\t');
	fill_path(new, subcommand, paths);
	new->input = NULL;
	new->output = NULL;
	if (subcmdr)
	{
		fill_input(new, subcmdr);
		fill_output(new, subcmdr);
	}
	fill_close_stand(new, subcmdr);
	fill_close(new, subcmdr);
	fill_fdredir(new, subcmdr);
	pipe(piperight);
}

void	fill_path(t_command *new, char *subcommand, char *paths)
{
	char	*good_path;
	char	*bin;

	bin = get_firstword(subcommand);
	select_path(paths, bin, &good_path);
	if (!good_path)
		new->path = bin;
	else
		new->path = good_path;
}

void	split_redir(char *subcommand, char **subcmdl, char **subcmdr)
{
	int	i;

	i = 0;
	while (subcommand[i])
	{
		if (subcommand[i] == '>' || subcommand[i] == '<')
		{
			if (ft_isdigit(subcommand[i - 1]) && (subcommand[i - 2] == ' '
				|| subcommand[i - 2] == '\t') && i > 2)
				i--;
			*subcmdl = ft_strsub(subcommand, 0, i);
			*subcmdr = ft_strsub(subcommand, i, ft_strlen(subcommand + i));
			return ;
		}
		i++;
	}
	*subcmdl = subcommand;
	*subcmdr = NULL;
	return ;
}

void	fill_close(t_command *new, char *subcmdr)
{
	int	tab[2];

	tab[0] = 0;
	tab[1] = 0;
	while ((ft_strstr(subcmdr, ">&-")))
	{
		if (!ft_strcmp(ft_strstr(subcmdr, ">&-"), subcmdr))
			tab[0] = 1;
		else if (*(ft_strstr(subcmdr, ">&-") - 1) == '2')
			tab[1] = 1;
		else if (*(ft_strstr(subcmdr, ">&-") - 1) == '1')
			tab[0] = 1;
		subcmdr = ft_strstr(subcmdr, ">&-") + 2;
	}
	new->close[0] = tab[0];
	new->close[1] = tab[1];
}

void	fill_fdredir(t_command *new, char *subcmdr)
{
	new->fdredir[0] = 0;
	new->fdredir[1] = 0;
	while (ft_strstr(subcmdr, ">&"))
	{
		if ((ft_strstr(subcmdr, ">&"))[2] == '1')
		{
			new->fdredir[0] = 2;
			new->fdredir[1] = 1;
		}
		else if ((ft_strstr(subcmdr, ">&"))[2] == '2')
		{
			new->fdredir[0] = 1;
			new->fdredir[1] = 2;
		}
		subcmdr = ft_strstr(subcmdr, ">&") + 2;
	}
}
