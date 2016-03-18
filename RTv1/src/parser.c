#include <RTv1.h>

void    parse_camera(t_tool *tools, int fd)
{
	char    **split;
	char	*line;

    tools->cam = malloc(sizeof(t_cam));
	while (get_next_line(fd, &line) > 0 && ft_strcmp(line, "}"))
	{
	    split = ft_strsplit(line, ' ');
		if (ft_strstr(line, "pos:"))
			tools->cam->pos = fill_pos(split);
		if (ft_strstr(line, "res:"))
		{
			tools->cam->x_res = ft_atoi(split[1]);
			tools->cam->y_res = ft_atoi(split[2]);
		}
	}
}

void    parse_object(t_tool *tools, int fd)
{
    t_object *object;
    char *line;
    char **split;

    object = malloc(sizeof(*object));
    object->next = NULL;
    while (get_next_line(fd, &line) != 0 && ft_strcmp(line, "}"))
    {
        split = ft_strsplit(line, ' ');
        if (ft_strstr(line, "type:"))
            object->type = object_type(split);
        else if (ft_strstr(line, "pos:"))
            object->O = fill_pos(split);
        else if (ft_strstr(line, "dir:"))
            object->D = fill_pos(split);
        else if (ft_strstr(line, "rayon:"))
            object->rad = ft_atof(split[1]);
        else if (ft_strstr(line, "color:"))
            object->color = fill_color(split);
        else if (ft_strstr(line, "h:"))
            object->h = ft_atof(split[1]);
        else if (ft_strstr(line, "shiny:"))
            object->shiny = ft_atof(split[1]);
    }
    add_object(&tools->l_objects, object);
}

void    parse_light(t_tool *tools, int fd)
{
    char    **split;
    char    *line;
    t_light *light;
    
    light = malloc(sizeof(*light));
    light->next = NULL;
    while (get_next_line(fd, &line) > 0 && !ft_strstr(line, "}"))
    {
        split = ft_strsplit(line, ' ');
        if (ft_strstr(line, "pos:"))
        {
            light->O = fill_pos(split);
        }
        else if (ft_strstr(line, "color:"))
        {
            light->color = fill_color(split);
        }
        else if (ft_strstr(line, "dist:"))
            light->dist = ft_atof(split[1]);
    }
    add_light(&tools->l_lights, light);
}

t_tool      *parser(int fd)
{
    t_tool *tools;
    char    *line;
    
    tools = malloc(sizeof(*tools));
    tools->l_objects = NULL;
    tools->l_lights = NULL;
    while (get_next_line(fd, &line) != 0)
    {
        if (ft_strstr(line, "camera"))
            parse_camera(tools, fd);
        else if (ft_strstr(line, "light"))
            parse_light(tools, fd);
        else if (ft_strstr(line, "object"))
            parse_object(tools, fd);
    }
    return (tools);
}