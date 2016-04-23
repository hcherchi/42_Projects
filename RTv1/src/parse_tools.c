#include <rtv1.h>

t_image     *fill_texture(char *file, t_tool *t)
{
    t_image *texture;
    
    texture = malloc(sizeof(t_image));
    texture->texture = ft_strdup(file);
    texture->mlx_img = mlx_xpm_file_to_image(t->mlx_ptr, texture->texture, &texture->width, &texture->height);
    if (texture->mlx_img == NULL)
    {
        ft_error(11, t);
        return (NULL);
    }
    texture->data = mlx_get_data_addr(texture->mlx_img, &texture->bpp, &texture->size_line, &texture->endian);
    return (texture);
}

int		object_type(char **split, t_tool *tools)
{
	if (ft_tablen(split) == 2)
	{
		if (!ft_strcmp(split[1], "SPHERE"))
			return (0);
		else if (!ft_strcmp(split[1], "CYL"))
			return (1);
		else if (!ft_strcmp(split[1], "CONE"))
			return (2);
		else if (!ft_strcmp(split[1], "PLAN"))
			return (3);
    	else if (!ft_strcmp(split[1], "PARA"))
    	    return (4);
		else
			ft_error(5, tools);
	}
	else
		ft_error(7, tools);
	return (0);
}

int		light_type(char **split, t_tool *tools)
{
    if (ft_tablen(split) == 2)
    {
    	if (!ft_strcmp(split[1], "SUN"))
    	    return (SUN);
    	else if (!ft_strcmp(split[1], "LIGHTPLAN"))
    	    return (LIGHTPLAN);
    	else if (!ft_strcmp(split[1], "SPOT"))
    	    return (SPOT);
    	else
    	    ft_error(12, tools);
    }
    else
        ft_error(7, tools);
    return (0);
}

t_color	*fill_color(char **split, t_tool *tools)
{
	t_color	*color;

	color = malloc(sizeof(t_color));
	if (ft_tablen(split) == 4)
	{
		if (str_digit(split[1]) || str_digit(split[2])
			|| str_digit(split[3]))
			ft_error(2, tools);
			color->r = ft_atof(split[1]);
		color->g = ft_atof(split[2]);
		color->b = ft_atof(split[3]);
	}
	else
		ft_error(7, tools);
	return (color);
}

t_pos	*fill_pos(char **split, t_tool *tools)
{
	t_pos	*pos;

	pos = malloc(sizeof(t_pos));
	if (ft_tablen(split) == 4)
	{
		if (str_digit(split[1]) || str_digit(split[2])
			|| str_digit(split[3]))
			ft_error(2, tools);
		pos->x = ft_atof(split[1]);
		pos->y = ft_atof(split[2]);
		pos->z = ft_atof(split[3]);
	}
	else
		ft_error(7, tools);
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
