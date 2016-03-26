/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_setters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:26:27 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/05 12:47:59 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "libft.h"
#include "executor.h"
#include "ftsh.h"
#include "parser.h"

t_env	*new_entry(char *key, char *val)
{
	t_env	*new;

	if (!(new = (t_env *)malloc(sizeof(*new))))
	{
		errno = ENOMEM;
		return (NULL);
	}
	new->key = key;
	new->val = val;
	new->next = NULL;
	return (new);
}

/*
** VAL MUST BE ALLOCATED OR NULL, KEY SHOULD NOT
** IF KEY IS ALLOC YOU'LL HAVE TO FREE IT AFTER
*/

int		set_env(t_env **env, char *key, char *val)
{
	t_env	*tmp;

	tmp = *env;
	if (val == NULL)
		val = ft_strnew(0);
	if (*env == NULL)
	{
		*env = new_entry(ft_strdup(key), val);
		return (SUCCESS);
	}
	while (tmp->next && ft_strcmp(tmp->key, key) != 0)
		tmp = tmp->next;
	if (ft_strcmp(tmp->key, key) == 0)
	{
		free(tmp->val);
		tmp->val = val;
		return (SUCCESS);
	}
	tmp->next = new_entry(ft_strdup(key), val);
	return (SUCCESS);
}

int		unset_env(t_env **env, char *key)
{
	t_env	*tmp;
	t_env	*del;

	if (env == NULL || *env == NULL)
		return (SUCCESS);
	tmp = *env;
	if (ft_strcmp(tmp->key, key) == 0)
	{
		free(tmp->key);
		free(tmp->val);
		*env = tmp->next;
		free(tmp);
		return (SUCCESS);
	}
	while (tmp->next && ft_strcmp(tmp->next->key, key) != 0)
		tmp = tmp->next;
	if (tmp->next == NULL)
		return (FAILURE);
	del = tmp->next;
	free(del->key);
	free(del->val);
	tmp->next = del->next;
	free(del);
	return (SUCCESS);
}

char	*get_env(t_env *env, char *key, int dup)
{
	while (env && ft_strcmp(key, env->key) != 0)
		env = env->next;
	if (!env)
		return (NULL);
	if (dup)
		return (ft_strdup(env->val));
	return (env->val);
}
