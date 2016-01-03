/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_second.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 11:11:45 by hcherchi          #+#    #+#             */
/*   Updated: 2015/12/30 17:37:09 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

void	choose_sort(t_file **l_files, t_option *opt)
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

void	putpath(t_file *l_files)
{
	t_file	*cur;

	cur = l_files;
	ft_putchar('\n');
	ft_putstr(cur->data->path);
	ft_putstr(":\n");
}

void	putlink(t_file *l_files)
{
	t_file	*cur;

	cur = l_files;
	ft_putstr(" -> ");
	ft_putstr(cur->data->namelk);
}

void	hoption(void)
{
	ft_putstr("--R afficher récursivement les sous-répertoires.\n");
	ft_putstr("--l utiliser un format d’affichage long.\n");
	ft_putstr("--a inclure les entrées débutant par « . ».\n");
	ft_putstr("--r inverser l'ordre du tri.\n");
	ft_putstr("--t trier selon la date de modification.\n");
	ft_putstr("--p ajouter l’indicateur « / » aux répertoires.\n");
	ft_putstr("--f ne pas trier, activer les options -aU et");
	ft_putstr(" désactiver les  options -ls --color.\n");
	ft_putstr("--g identique à -l mais sans afficher le propriétaire.\n");
	ft_putstr("--h aide pour les options.\n");
}
