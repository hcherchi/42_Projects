/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 11:51:23 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/30 17:36:55 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*split(t_file *l_files)
{
	t_file	*aux;

	if (l_files == NULL)
		return (NULL);
	else if (l_files->next == NULL)
		return (NULL);
	else
	{
		aux = l_files->next;
		l_files->next = aux->next;
		aux->next = split(aux->next);
		return (aux);
	}
}

t_file	*fusion_ascii(t_file *lg, t_file *ld)
{
	if (lg == NULL)
		return (ld);
	else if (ld == NULL)
		return (lg);
	else if (ft_strcmp(lg->data->path, ld->data->path) < 0)
	{
		lg->next = fusion_ascii(lg->next, ld);
		return (lg);
	}
	else
	{
		ld->next = fusion_ascii(lg, ld->next);
		return (ld);
	}
}

t_file	*fusion_time(t_file *lg, t_file *ld)
{
	if (lg == NULL)
		return (ld);
	else if (ld == NULL)
		return (lg);
	else if (lg->data->time >= ld->data->time)
	{
		lg->next = fusion_time(lg->next, ld);
		return (lg);
	}
	else
	{
		ld->next = fusion_time(lg, ld->next);
		return (ld);
	}
}

void	sort_time(t_file **l_files)
{
	t_file *aux;

	if (*l_files != NULL)
		if ((*l_files)->next != NULL)
		{
			aux = split(*l_files);
			sort_time(l_files);
			sort_time(&aux);
			*l_files = fusion_time(*l_files, aux);
		}
}

void	sort_ascii(t_file **l_files)
{
	t_file *aux;

	if (*l_files != NULL)
		if ((*l_files)->next != NULL)
		{
			aux = split(*l_files);
			sort_ascii(l_files);
			sort_ascii(&aux);
			*l_files = fusion_ascii(*l_files, aux);
		}
}
