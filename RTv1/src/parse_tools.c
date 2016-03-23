/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:40:40 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/23 14:25:32 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int		object_type(char **split)
{
	if (ft_tablen(split) != 2)
		ft_error(7);
	if (!ft_strcmp(split[1], "SPHERE"))
		return (0);
	else if (!ft_strcmp(split[1], "CYL"))
		return (1);
	else if (!ft_strcmp(split[1], "CONE"))
		return (2);
	else if (!ft_strcmp(split[1], "PLAN"))
		return (3);
	else
		ft_error(5);
	return (0);
}

t_color	*fill_color(char **split)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (ft_tablen(split) != 4)
		ft_error(7);
	if (str_digit(split[1]) || str_digit(split[2])
		|| str_digit(split[3]))
		ft_error(2);
	color->r = ft_atof(split[1]);
	color->g = ft_atof(split[2]);
	color->b = ft_atof(split[3]);
	return (color);
}

t_pos	*fill_pos(char **split)
{
	t_pos	*pos;

	pos = malloc(sizeof(t_pos));
	if (ft_tablen(split) != 4)
		ft_error(7);
	if (str_digit(split[1]) || str_digit(split[2])
		|| str_digit(split[3]))
		ft_error(2);
	pos->x = ft_atof(split[1]);
	pos->y = ft_atof(split[2]);
	pos->z = ft_atof(split[3]);
	return (pos);
}

void	add_object(t_object **l_objects, t_object *new)
{
	t_object	*tmp;

	tmp = *l_objects;
	if (*l_objects == NULL)
		*l_objects = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	add_light(t_light **l_lights, t_light *new)
{
	t_light	*tmp;

	tmp = *l_lights;
	if (*l_lights == NULL)
		*l_lights = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
