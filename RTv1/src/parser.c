#include <rtv1.h>


// FONCTION A RAJOUTER POUR REMPLACER TOUS LES TEST TABLEN ET STRDIGIT.
void	parse_camera(t_tool *tools, int fd)
{
	char	**split;
	char	*line;

	tools->rt->lumamb = 0.1;
    tools->rt->x_res = 1000;
    tools->rt->y_res = 800;
    tools->rt->sky = NULL;
    tools->rt->vect = NULL;
    tools->rt->pos = NULL;
	while (get_next_line(fd, &line) > 0 && ft_strcmp(line, "}"))
	{
		split = ft_strsplit(line, ' ');
		if (ft_strstr(line, "pos:"))
			tools->rt->pos = fill_pos(split);
		else if (ft_strstr(line, "res:"))
		{
			if (ft_tablen(split) != 3)
				ft_error();
			if (str_digit(split[1]) || str_digit(split[2]))
				ft_error();
			if (ft_atoi(split[1]) < 0 || ft_atoi(split[2]) < 0)
				ft_error();
			tools->rt->x_res = ft_atoi(split[1]);
			tools->rt->y_res = ft_atoi(split[2]);
		}
        else if (ft_strstr(line, "lumamb:"))
        {
            if (ft_tablen(split) != 2)
                ft_error();
            tools->rt->lumamb = ft_atof(split[1]);
        }
        else if (ft_strstr(line, "vect:"))
        {
            tools->rt->vect = fill_pos(split);
        }
		else if (ft_strstr(line, "skybox:"))
		{
			if (ft_tablen(split) != 2)
				ft_error();
			tools->rt->sky = fill_texture(split[1], tools);
		}
        else if (ft_strcmp(line, "{"))
            ft_error();
        clean_tab(split);
        free(line);
	}
}

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
        else if (ft_strstr(line, "mirror:"))
        {
            if (ft_tablen(split) != 2)
                ft_error();
            if (str_digit(split[1]))
                ft_error();
            object->mirror = ft_atof(split[1]);
        }
        else if (ft_strstr(line, "refract:"))
        {
            if (ft_tablen(split) != 2)
                ft_error();
            if (str_digit(split[1]))
                ft_error();
            object->refract = ft_atof(split[1]);
        }
        else if (ft_strstr(line, "transp:"))
        {
            if (ft_tablen(split) != 2)
                ft_error();
            if (str_digit(split[1]))
                ft_error();
            object->transp = ft_atof(split[1]);
        }
        else if (ft_strstr(line, "texture:"))
        {
            if (ft_tablen(split) != 2)
                ft_error();
            object->texture = fill_texture(split[1], tools);
        }
        else if (ft_strstr(line, "pos:"))
        {
            free(object->o);
            object->o = fill_pos(split);
        }
        else if (ft_strstr(line, "dir:"))
        {
            free(object->d);
            object->d = fill_pos(split);
        }
        else if (ft_strstr(line, "color:"))
        {
            free(object->color);
            object->color = fill_color(split);
        }
        else if (ft_strstr(line, "h:"))
        {
            if (ft_tablen(split) != 2)
                ft_error();
            if (str_digit(split[1]))
                ft_error();
            object->h = ft_atof(split[1]);
        }
        else if (ft_strstr(line, "shiny:"))
        {
            if (ft_tablen(split) != 2)
                ft_error();
            if (str_digit(split[1]))
                ft_error();
            object->shiny = ft_atof(split[1]);
        }
        else if (ft_strcmp(line, "{"))
            ft_error();
        clean_tab(split);
        free(line);
	}
    vectornorm(object->d);
	add_object(&tools->rt->l_objects, object);
}

void	parser(int fd, t_tool *tools)
{
	char	*line;
	int		c;
	int		ret;

	c = 0;
    tools->rt = malloc(sizeof(t_rt));
    tools->rt->l_objects = NULL;
    tools->rt->l_lights = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!ft_strcmp(line, "camera"))
		{
			c++;
            free(line);
			parse_camera(tools, fd);
		}
		else if (!ft_strcmp(line, "light"))
        {
            free(line);
			parse_light(tools, fd);
        }
		else if (!ft_strcmp(line, "object"))
        {
            free(line);
			parse_object(tools, fd);
        }
	}
	if (ret == -1)
		ft_error();
	if (c != 1)
		ft_error();
}
