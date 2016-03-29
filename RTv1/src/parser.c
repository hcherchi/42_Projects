/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 12:43:23 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/28 12:02:17 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	parse_camera(t_tool *tools, int fd)
{
	char	**split;
	char	*line;

	tools->lumamb = 0.1;
	tools->cam = malloc(sizeof(t_cam));
	init_camera(tools);
	while (get_next_line(fd, &line) > 0 && ft_strcmp(line, "}"))
	{
		split = ft_strsplit(line, ' ');
		if (ft_strstr(line, "pos:"))
			tools->cam->pos = fill_pos(split);
		else if (ft_strstr(line, "res:"))
		{
			if (ft_tablen(split) != 3)
				ft_error(7);
			if (str_digit(split[1]) || str_digit(split[2]))
				ft_error(2);
			if (ft_atoi(split[1]) < 0 || ft_atoi(split[2]) < 0)
				ft_error(8);
			tools->cam->x_res = ft_atoi(split[1]);
			tools->cam->y_res = ft_atoi(split[2]);
		}
        else if (ft_strstr(line, "lumamb:"))
        {
            if (ft_tablen(split) != 2)
                ft_error(7);
            tools->lumamb = ft_atof(split[1]);
        }
        else if (ft_strstr(line, "vect:"))
        {
            tools->cam->vect = fill_pos(split);
            tools->cam->vect->y = 0;
            vectornorm(tools->cam->vect);
        }
        else if (ft_strcmp(line, "{"))
            ft_error(1);
	}
}

void	parse_object(t_tool *tools, int fd)
{
	t_object	*object;
	char		*line;
	char		**split;

	object = malloc(sizeof(*object));
	object->next = NULL;
	init_object(object);
	while (get_next_line(fd, &line) != 0 && ft_strcmp(line, "}"))
	{
		split = ft_strsplit(line, ' ');
		if (ft_strstr(line, "type:"))
			object->type = object_type(split);
		else if (ft_strstr(line, "rayon:"))
		{
			if (ft_tablen(split) != 2)
				ft_error(7);
			if (str_digit(split[1]))
				ft_error(2);
			object->rad = ft_atof(split[1]);
		}
        else if (ft_strstr(line, "mirror:"))
        {
            if (ft_tablen(split) != 2)
                ft_error(7);
            if (str_digit(split[1]))
                ft_error(2);
            object->mirror = ft_atof(split[1]);
        }
        else if (ft_strstr(line, "refract:"))
        {
            if (ft_tablen(split) != 2)
                ft_error(7);
            if (str_digit(split[1]))
                ft_error(2);
            object->refract = ft_atof(split[1]);
        }
        else if (ft_strstr(line, "transp:"))
        {
            if (ft_tablen(split) != 2)
                ft_error(7);
            if (str_digit(split[1]))
                ft_error(2);
            object->transp = ft_atof(split[1]);
        }
        else if (ft_strstr(line, "texture:"))
        {
            if (ft_tablen(split) != 2)
                ft_error(7);
            object->texture = fill_texture(split[1], tools);
        }
        else if (ft_strstr(line, "pos:"))
            object->o = fill_pos(split);
        else if (ft_strstr(line, "dir:"))
            object->d = fill_pos(split);
        else if (ft_strstr(line, "color:"))
            object->color = fill_color(split);
        else if (ft_strstr(line, "h:"))
        {
            if (ft_tablen(split) != 2)
                ft_error(7);
            if (str_digit(split[1]))
                ft_error(2);
            object->h = ft_atof(split[1]);
        }
        else if (ft_strstr(line, "shiny:"))
        {
            if (ft_tablen(split) != 2)
                ft_error(7);
            if (str_digit(split[1]))
                ft_error(2);
            object->shiny = ft_atof(split[1]);
        }
        else if (ft_strcmp(line, "{"))
            ft_error(4);
	}
    vectornorm(object->d);
	add_object(&tools->l_objects, object);
}

void	parser(int fd, t_tool *tools)
{
	char	*line;
	int		c;
	int		ret;

	c = 0;
	tools->l_objects = NULL;
	tools->l_lights = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!ft_strcmp(line, "camera"))
		{
			c++;
			parse_camera(tools, fd);
		}
		else if (!ft_strcmp(line, "light"))
			parse_light(tools, fd);
		else if (!ft_strcmp(line, "object"))
			parse_object(tools, fd);
	}
	if (ret == -1)
		ft_error(9);
	if (c != 1)
		ft_error(6);
}
