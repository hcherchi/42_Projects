#include <RTv1.h>

int    object_type(char **split)
{
    if (!ft_strcmp(split[1], "SPHERE"))
        return 0;
    else if (!ft_strcmp(split[1], "CYL"))
        return 1;
    else if (!ft_strcmp(split[1], "CONE"))
        return 2;
    else if (!ft_strcmp(split[1], "PLAN"))
        return 3;
    return (0);
}

t_color *fill_color(char **split)
{
    t_color *color;
    
    color = malloc(sizeof(t_color));
    color->r = ft_atof(split[1]);
	color->g = ft_atof(split[2]);
	color->b = ft_atof(split[3]);
	return (color);
}

t_pos   *fill_pos(char **split)
{
    t_pos *pos;
    
    pos = malloc(sizeof(t_pos));
    pos->x = ft_atof(split[1]);
	pos->y = ft_atof(split[2]);
	pos->z = ft_atof(split[3]);
	return (pos);
}

void    add_object(t_object **l_objects, t_object *new)
{
    t_object *tmp;
    
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

void    add_light(t_light **l_lights, t_light *new)
{
    t_light *tmp;
    
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