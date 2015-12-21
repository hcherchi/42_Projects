/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 19:45:54 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/22 00:05:35 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file *split(t_file *l_files)
{
    t_file *aux;
 
 if (l_files == NULL)
   return(NULL);
 else if (l_files->next == NULL)
   return(NULL);
 else
   {
     aux = l_files->next;
     l_files->next = aux->next;
     aux->next=split(aux->next);
     return(aux);
   }
}

t_file *fusion_ascii(t_file *lg,t_file *ld)
{
  if (lg == NULL)
    return(ld);
  else if (ld == NULL)
    return(lg);
  else if (ft_strcmp(lg->data->path, ld->data->path) < 0)
    {
      lg->next = fusion_ascii(lg->next,ld);
      return(lg);
    }
  else
    {
      ld->next = fusion_ascii(lg,ld->next);
      return(ld);
    }
}

t_file *fusion_time(t_file *lg,t_file *ld)
{
  if (lg == NULL)
    return(ld);
  else if (ld == NULL)
    return(lg);
  else if (lg->data->time >= ld->data->time)
    {
      lg->next = fusion_time(lg->next,ld);
      return(lg);
    }
  else
    {
      ld->next = fusion_time(lg,ld->next);
      return(ld);
    }
}

void	sort_time(t_file **l_files)
{
		t_file *aux;
 
 if (*l_files != NULL)
   if ((*l_files)->next != NULL) 
     {
       aux=split(*l_files);
       sort_time(l_files);
       sort_time(&aux);
       	*l_files = fusion_time(*l_files, aux);
     }
}

void sort_ascii(t_file **l_files)
{
	t_file *aux;
 
 if (*l_files != NULL)
   if ((*l_files)->next != NULL) 
     {
       aux=split(*l_files);
       sort_ascii(l_files);
       sort_ascii(&aux);
       *l_files=fusion_ascii(*l_files, aux);
     }
}

void	reverse(t_file **l_files)
{
	t_file	*inv;
	t_file	*cur;

	cur = *l_files;
	inv = NULL;
	if (!*l_files)
		return ;
	else
	{
		while ((*l_files)->next)
		{
			while (cur->next->next)
			{
				cur = cur->next;
			}
			add_file(&inv, cur->next);
			cur->next = NULL;
			cur = *l_files;
		}
		add_file(&inv, *l_files);
	}
	*l_files = inv;
}

void	choose_sort(t_file **l_files, t_option	*opt)
{
	if (opt->f == 0)
	{
		sort_ascii(l_files);
		if (opt->t)
			sort_time(l_files);
		if (opt->r)
			reverse(l_files);
	}
}
