/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:26:49 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/19 20:26:51 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"
#include "libft.h"
#include "ftsh.h"

void	set_env_keyval(t_env **env, char *keyval)
{
	char **split;

	if (!keyval)
		return ;
	split = ft_strsplit(keyval, '=');
	if (split[0] == NULL)
	{
		set_env(env, "", ft_strdup(""));
	}
	else
		set_env(env, split[0], split[1]);
	free(split[0]);
	free(split);
}
