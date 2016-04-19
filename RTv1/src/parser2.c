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
            light->o = fill_pos(split);
        }        
        else
            parse_light2(line, light, split);
        clean_tab(split);
        free(line);
	}
    vectornorm(light->d);
	add_light(&tools->rt->l_lights, light);
}

void    parse_light2(char *line, t_light *light, char **split)
{
    if (ft_strstr(line, "dir:"))
    {
        free(light->d);
        light->d = fill_pos(split);
    }
    else if (ft_strstr(line, "color:"))
    {
        free(light->color);
        light->color = fill_color(split);
    }
    else if (ft_strstr(line, "lumdiff:"))
    {
        if (ft_tablen(split) != 2)
            ft_error(7);
        if (str_digit(split[1]))
            ft_error(2);
        light->lumdiff = ft_atof(split[1]);
    }
    else
        parse_light3(line, light, split);
}

void    parse_light3(char *line, t_light *light, char **split)
{
    if (ft_strstr(line, "h:"))
    {
        if (ft_tablen(split) != 2)
            ft_error(7);
        if (str_digit(split[1]))
            ft_error(2);
        light->h = ft_atof(split[1]);
    }
    else if (ft_strstr(line, "angle:"))
    {
        if (ft_tablen(split) != 2)
            ft_error(7);
        if (str_digit(split[1]))
            ft_error(2);
        light->angle = ft_atof(split[1]);
    }
    else if (ft_strstr(line, "type:"))
        light->type = light_type(split);
    else if (ft_strcmp(line, "{"))
        ft_error(3);
}