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
			object->type = object_type(split, tools);
		else if (ft_strstr(line, "rayon:"))
		{
            if (ft_tablen(split) == 2)
            {
                if (str_digit(split[1]))
                    ft_error(2, tools);
                object->rad = ft_atof(split[1]);
            }
            else
                ft_error(7, tools);
		}
        else
            parse_object2(line, object, split, tools);
        if (object->mirror + object->transp > 1)
            ft_error(15, tools);
        clean_tab(split);
        free(line);
	}
    vectornorm(object->d);
	add_object(&tools->rt->l_objects, object);
}

void    parse_object2(char *line, t_object *object, char **split, t_tool *tools)
{
    if (ft_strstr(line, "mirror:"))
    {
        if (ft_tablen(split) == 2)
        {
            if (str_digit(split[1]))
                ft_error(2, tools);
            if (ft_atof(split[1]) > 1 || ft_atof(split[1]) < 0)
                ft_error(14, tools);
            object->mirror = ft_atof(split[1]);
        }
        else
            ft_error(7, tools);
    }
    else if (ft_strstr(line, "refract:"))
    {
        if (ft_tablen(split) == 2)
        {     
            if (str_digit(split[1]))
                ft_error(2, tools);
            object->refract = ft_atof(split[1]);
        }
        else
            ft_error(7, tools);
    }
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

void    parse_object3(char *line, t_object *object, char **split, t_tool *tools)
{
    if (ft_strstr(line, "texture:"))
    {
        if (ft_tablen(split) == 3)
        {
            object->texture = fill_texture(split[1], tools);
            if (str_digit(split[2]))
                ft_error(2, tools);
            object->texture_zoom = ft_atof(split[2]);
        }
        else
            ft_error(7, tools);
    }
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

void    parse_object4(char *line, t_object *object, char **split, t_tool *tools)
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




