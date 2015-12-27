/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 15:55:49 by bgantelm          #+#    #+#             */
/*   Updated: 2015/11/29 19:13:01 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*list;
	t_list	*res;
	t_list	*cur;

	res = NULL;
	if (lst && (*f))
	{
		res = (*f)(lst);
		list = res;
		lst = lst->next;
		while (lst)
		{
			cur = (*f)(lst);
			list->next = cur;
			list = cur;
			lst = lst->next;
		}
		list->next = NULL;
	}
	return (res);
}
