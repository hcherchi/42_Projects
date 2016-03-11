/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 14:13:00 by bgantelm          #+#    #+#             */
/*   Updated: 2015/11/29 15:21:38 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	else if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		list->content = malloc(sizeof(content));
		if (list->content == NULL)
			return (NULL);
		ft_memcpy((list->content), content, ft_strlen((char *)content));
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
