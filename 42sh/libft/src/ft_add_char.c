/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/19 20:34:12 by hcherchi          #+#    #+#             */
/*   Updated: 2016/02/19 20:46:10 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*add_char(char *line, char c)
{
	char *res;

	res = malloc(sizeof(*res) * (ft_strlen(line) + 2));
	ft_strcpy(res, line);
	res[ft_strlen(line)] = c;
	res[ft_strlen(line) + 1] = 0;
	free(line);
	return (res);
}

char	*add_str(char *line, char *str)
{
	char *res;

	res = malloc(sizeof(*res) * (ft_strlen(line) + ft_strlen(str) + 1));
	ft_strcpy(res, line);
	ft_strcpy(res + ft_strlen(line), str);
	res[ft_strlen(line) + ft_strlen(str)] = 0;
	free(line);
	free(str);
	return (res);
}
