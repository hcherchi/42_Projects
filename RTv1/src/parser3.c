#include <rtv1.h>

void	parse_object(t_tool *tools, int fd)
{
	t_object	*object;
	char		*line;
	char		**split;

	object = malloc(sizeof(*object));
	init_object(object);
	while (get_next_line(fd, &line) != 0 && ft_strcmp(line, "}"))
	{
		split = ft_strsplit(line, ' ');
		if (ft_strstr(line, "type:"))
			object->type = object_type(split);
		else if (ft_strstr(line, "rayon:"))
		{
			if (ft_tablen(split) != 2)
				ft_error();
			if (str_digit(split[1]))
				ft_error();
			object->rad = ft_atof(split[1]);
		}
        else
            parse_object2(&line, object, split, tools);
        clean_tab(split);
        free(line);
	}
    vectornorm(object->d);
	add_object(&tools->rt->l_objects, object);
}

void    parse_object2(char **line, t_object *object, char **split, t_tool *tools)
{
    if (ft_strstr(*line, "mirror:"))
    {
        if (ft_tablen(split) != 2)
            ft_error();
        if (str_digit(split[1]))
            ft_error();
        object->mirror = ft_atof(split[1]);
    }
    else if (ft_strstr(*line, "refract:"))
    {
        if (ft_tablen(split) != 2)
            ft_error();
        if (str_digit(split[1]))
            ft_error();
        object->refract = ft_atof(split[1]);
    }
    else if (ft_strstr(*line, "transp:"))
    {
        if (ft_tablen(split) != 2)
            ft_error();
        if (str_digit(split[1]))
            ft_error();
        object->transp = ft_atof(split[1]);
    }
    else
        parse_object3(line, object, split, tools);
}

void    parse_object3(char **line, t_object *object, char **split, t_tool *tools)
{
    if (ft_strstr(*line, "texture:"))
    {
        if (ft_tablen(split) != 2)
            ft_error();
        object->texture = fill_texture(split[1], tools);
    }
    else if (ft_strstr(*line, "pos:"))
    {
        free(object->o);
        object->o = fill_pos(split);
    }
    else if (ft_strstr(*line, "dir:"))
    {
        free(object->d);
        object->d = fill_pos(split);
    }
    else if (ft_strstr(*line, "color:"))
    {
        free(object->color);
        object->color = fill_color(split);
    }
    else
        parse_object4(line, object, split);
}

void    parse_object4(char **line, t_object *object, char **split)
{
    if (ft_strstr(*line, "h:"))
    {
        if (ft_tablen(split) != 2)
            ft_error();
        if (str_digit(split[1]))
            ft_error();
        object->h = ft_atof(split[1]);
    }
    else if (ft_strstr(*line, "shiny:"))
    {
        if (ft_tablen(split) != 2)
            ft_error();
        if (str_digit(split[1]))
            ft_error();
        object->shiny = ft_atof(split[1]);
    }
    else if (ft_strcmp(*line, "{"))
        ft_error();
}




