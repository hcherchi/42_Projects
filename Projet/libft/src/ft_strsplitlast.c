/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 18:38:18 by hcherchi          #+#    #+#             */
/*   Updated: 2016/01/07 18:18:45 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplitlast(char const *str, char c)
{
    char **split;
    int i;
    int len;
    
    i = 0;
    len = 1;
    while (str[i])
        i++;
    if ((str[i - 1] == '1' || str[i - 1] == '2') && str[i - 2] == c)
    	len = 2;
    split = malloc(sizeof(*split) * len + 1);
    if (len == 1)
    {
        split[0] = ft_strdup(str);
        split[1] = NULL;
    }
    else
    {
        split[0] = ft_strsub(str, 0, ft_strlen(str) - 2);
        split[1] = ft_strdup(ft_strrchr(str, ' ') + 1);
        split[2] = NULL;
    }
    return (split);
}