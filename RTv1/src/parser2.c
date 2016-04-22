#include <rtv1.h>

void	parse_light(t_tool *tools, int fd)
{
	char	**split;
	char	*line;
	t_light	*light;

	light = malloc(sizeof(*light));
	init_light(light);
	while (get_next_line(fd, &line) > 0 && !ft_strstr(line, "}"))
	{
		split = ft_strsplit(line, ' ');
        if (ft_strstr(line, "pos:"))
        {
            free(light->o);
            light->o = fill_pos(split, tools);
        }        
        else
            parse_light2(line, light, split, tools);
        clean_tab(split);
        free(line);
	}
    vectornorm(light->d);
	add_light(&tools->rt->l_lights, light);
}

void    parse_light2(char *line, t_light *light, char **split, t_tool *tools)
{
    if (ft_strstr(line, "dir:"))
    {
        free(light->d);
        light->d = fill_pos(split, tools);
    }
    else if (ft_strstr(line, "color:"))
    {
        free(light->color);
        light->color = fill_color(split, tools);
    }
    else if (ft_strstr(line, "lumdiff:"))
    {
        if (ft_tablen(split) == 2)
        {
            if (str_digit(split[1]))
                ft_error(2, tools);
            light->lumdiff = ft_atof(split[1]);
        }
        else
            ft_error(7, tools);
    }
    else
        parse_light3(line, light, split, tools);
}

void    parse_light3(char *line, t_light *light, char **split, t_tool *tools)
{
    if (ft_strstr(line, "h:"))
    {
        if (ft_tablen(split) == 2)
        {
            if (str_digit(split[1]))
                ft_error(2, tools);
            light->h = ft_atof(split[1]);
        }
        else
            ft_error(7, tools);
    }
    else if (ft_strstr(line, "angle:"))
    {
        if (ft_tablen(split) == 2)
        {
            if (str_digit(split[1]))
                ft_error(2, tools);
            light->angle = ft_atof(split[1]);
        }
        else
            ft_error(7, tools);
    }
    else if (ft_strstr(line, "type:"))
        light->type = light_type(split, tools);
    else if (ft_strcmp(line, "{"))
        ft_error(3, tools);
}