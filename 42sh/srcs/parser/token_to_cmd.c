/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoudan <jhoudan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 19:14:29 by jhoudan           #+#    #+#             */
/*   Updated: 2016/03/14 10:50:44 by jhoudan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parser.h"
#include "lexer.h"

static int	look_for_var(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == '$' && (!i || str[i - 1] != '\\'))
			str[i] = -4;
	return (1);
}

static int	concat_string(char **s1, char *s2)
{
	char *tmp;

	tmp = *s1;
	*s1 = ft_strjoin(*s1, s2);
	ft_strdel(&tmp);
	return (1);
}

static char	*parent_str(t_token **liste)
{
	char	*str;
	t_token	*ptr;

	str = NULL;
	ptr = (*liste)->next;
	while (ptr && !parser_is_parent(ptr->type) && ptr->type == WORD)
	{
		if (!str)
			str = ft_strdup(ptr->content);
		else
			concat_string(&str, ptr->content);
		ptr = ptr->next;
	}
	if (str)
		escape_char_without_quote(str);
	*liste = ptr;
	return (str);
}

static void	add_arg_string(t_token *liste, t_arg **head)
{
	t_arg	*ptr;

	ptr = new_arg(STRING, ft_strdup((char*)(liste->content)));
	look_for_var(ptr->data);
	escape_char_without_quote((char*)(ptr->data));
	add_arg(head, ptr);
}

t_arg		*token_to_cmd(t_token *liste)
{
	t_arg	*head;

	head = NULL;
	while (liste && liste->type != ENDL)
	{
		while (liste && liste->type != WORD && !parser_is_quote(liste->type))
			liste = liste->next;
		if (!liste)
			break ;
		else if (liste->type == BACK_QUOTE)
		{
			add_arg(&head, bquote_controller(&liste));
			continue;
		}
		else if (parser_is_parent(liste->type))
			add_arg(&head, new_arg(STRING, parent_str(&liste)));
		else
			add_arg_string(liste, &head);
		liste = (liste) ? liste->next : liste;
	}
	return (head);
}
