/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:24:55 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/23 17:50:08 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ftsh.h>
#include <executor.h>
#include <parser.h>
#include <libft.h>

char	*get_alias(char *cmd)
{
	t_env	*aliases;

	aliases = g_shell->aliases;
	while (aliases)
	{
		if (ft_strequ(aliases->key, cmd))
			return (ft_strdup(aliases->val));
		aliases = aliases->next;
	}
	return (cmd);
}

void	print_alias(char *key)
{
	t_env	*aliases;

	aliases = g_shell->aliases;
	while (aliases)
	{
		if (ft_strequ(aliases->key, key))
			ft_printf("alias %s='%s'\n", aliases->val, aliases->val);
		aliases = aliases->next;
	}
}

int		insert_string(char **str, int beg, int end, char *insert)
{
	char	*res;
	size_t	begsize;
	size_t	ins_size;

	begsize = ft_strlen(*str) - (end - beg + 1);
	ins_size = ft_strlen(insert);
	if (!(res = ft_strnew(sizeof(*res) * (begsize + ins_size + 10))))
		return (-1);
	ft_strncpy(res, *str, beg);
	ft_strcpy(res + beg, insert);
	ft_strcpy(res + beg + ins_size, *str + end + 1);
	free(*str);
	*str = res;
	return (0);
}

void	add_tab_to_list(t_arg **list, char **tabs)
{
	int		i;

	i = 0;
	while (tabs && tabs[i])
	{
		add_arg_to_list(list, tabs[i], 0);
		i++;
	}
}
