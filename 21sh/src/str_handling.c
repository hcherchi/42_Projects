/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:35:34 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 19:37:03 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char		*get_elem(char **env, char *elem)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], elem, ft_strlen(elem)) == 0)
			res = ft_strsub(env[i], ft_strlen(elem), ft_strlen(env[i]));
		i++;
	}
	return (res);
}

char		*strchange(char *str, char c, char *str2)
{
	char	*strnew;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str2)
		return (str);
	strnew = ft_strnew(ft_strlen(str) + ft_strlen(str2));
	while (str[i])
	{
		if (str[i] == c && j == 0)
		{
			ft_strcpy(strnew + i, str2);
			j = ft_strlen(str2) - 1;
		}
		else
		{
			strnew[i + j] = str[i];
		}
		i++;
	}
	free(str2);
	free(str);
	return (strnew);
}

char		*del_char_to_str(char *src, unsigned int index)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	if ((dest = ft_strnew(ft_strlen(src))) == NULL)
		return (NULL);
	while (src[j] && index-- > 0)
		dest[i++] = src[j++];
	j++;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	free(src);
	return (dest);
}

char		*add_char_to_str(char *src, char c, unsigned int index)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	if ((dest = ft_strnew(ft_strlen(src) + 2)) == NULL)
		return (NULL);
	while (src[j] && index-- > 0)
		dest[i++] = src[j++];
	dest[i++] = c;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	free(src);
	return (dest);
}

char		*del_backslash(char *str)
{
	size_t	i;
	int		c;
	char	*res;

	c = 0;
	i = 0;
	while (i < ft_strlen(str))
	{
		if (str[i] == '\\')
			c++;
		i++;
	}
	i = 0;
	c = 0;
	res = ft_strnew(ft_strlen(str) - c);
	while (str[i])
	{
		if (str[i] != '\\')
		{
			res[c] = str[i];
			c++;
		}
		i++;
	}
	return (res);
}
