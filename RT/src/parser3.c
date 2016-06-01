/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:32:41 by vnguyen           #+#    #+#             */
/*   Updated: 2016/06/01 10:39:32 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	parse_object(t_tool *tools, int fd)
{
	t_object	*object;
	char		*line;
	char		**split;

	split = NULL;
	object = malloc(sizeof(*object));
	init_object(object);
	while (get_next_line(fd, &line) != 0 && ft_strcmp(line, "}"))
	{
		suite_parse_object(tools, line, split, object);
	}
	vectornorm(object->d);
	add_object(&tools->rt->l_objects, object);
}

void	parse_object2(char *line, t_object *object, char **split, t_tool *tools)
{
	if (ft_strstr(line, "mirror:"))
		suite_parse_object2(split, tools, object);
	else if (ft_strstr(line, "refract:"))
		suite_parse_object3(split, tools, object);
	else if (ft_strstr(line, "transp:"))
	{
		if (ft_tablen(split) == 2)
		{
			if (str_digit(split[1]))
				ft_error(2, tools);
			if (ft_atof(split[1]) > 1 || ft_atof(split[1]) < 0)
				ft_error(14, tools);
			object->transp = ft_atof(split[1]);
		}
		else
			ft_error(7, tools);
	}
	else
		parse_object3(line, object, split, tools);
}

void	parse_object3(char *line, t_object *object, char **split, t_tool *tools)
{
	if (ft_strstr(line, "texture:"))
		suite_parse_object4(split, tools, object);
	else if (ft_strstr(line, "pos:"))
	{
		free(object->o);
		object->o = fill_pos(split, tools);
	}
	else if (ft_strstr(line, "dir:"))
	{
		free(object->d);
		object->d = fill_pos(split, tools);
	}
	else if (ft_strstr(line, "color:"))
	{
		free(object->color);
		object->color = fill_color(split, tools);
	}
	else
		parse_object4(line, object, split, tools);
}

void	parse_object4(char *line, t_object *object, char **split, t_tool *tools)
{
	if (ft_strstr(line, "h:"))
	{
		if (ft_tablen(split) == 2)
		{
			if (str_digit(split[1]))
				ft_error(2, tools);
			object->h = ft_atof(split[1]);
		}
		else
			ft_error(7, tools);
	}
	else if (ft_strstr(line, "shiny:"))
	{
		if (ft_tablen(split) == 2)
		{
			if (str_digit(split[1]))
				ft_error(2, tools);
			object->shiny = ft_atof(split[1]);
		}
		else
			ft_error(7, tools);
	}
	else if (ft_strcmp(line, "{"))
		ft_error(4, tools);
}
