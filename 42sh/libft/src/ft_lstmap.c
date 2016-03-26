/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 11:54:13 by jhoudan           #+#    #+#             */
/*   Updated: 2015/11/23 18:52:26 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *current;
	t_list *temp;

	head = NULL;
	if (lst)
	{
		head = ft_lstnew(lst->content, lst->content_size);
		head = f(head);
		lst = lst->next;
	}
	current = head;
	while (lst)
	{
		temp = ft_lstnew(lst->content, lst->content_size);
		temp = f(temp);
		current->next = temp;
		current = temp;
		lst = lst->next;
	}
	return (head);
}
