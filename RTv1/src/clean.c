#include <rtv1.h>

void    clean_tools(t_tool **tools)
{
    if ((*tools)->m)
        clean_menu(&(*tools)->m);
    if ((*tools)->rt)
        clean_rt(&(*tools)->rt);
    if ((*tools)->mlx_ptr)
    {
        free((*tools)->mlx_ptr);
        (*tools)->mlx_ptr = NULL;
    }
    if (*tools)
    {
        free(*tools);
        *tools = NULL;
    }
}

void    clean_menu(t_menu **m)
{
    if ((*m)->mlx_win)
    {
        free((*m)->mlx_win);
        (*m)->mlx_win = NULL;
    }
    if ((*m)->bg)
        clean_image(&(*m)->bg);
    if (*m)
    {
        free(*m);
        *m = NULL;
    }
}

void	clean_ray(t_ray **ray)
{
    if ((*ray)->o)
    {
    	free((*ray)->o);
        (*ray)->o = NULL;
    }
    if ((*ray)->d)
    {
        free((*ray)->d);
        (*ray)->d = NULL;
    }
	if (*ray)
    {
        free(*ray);
        *ray = NULL;
    }
}

void	clean_rt(t_rt **rt)
{
    if ((*rt)->sky)
        clean_image(&(*rt)->sky);
    if ((*rt)->image)
        clean_image(&(*rt)->image);
	if ((*rt)->l_objects)
        clean_obj(&(*rt)->l_objects);
	if ((*rt)->l_lights)
        clean_lights(&(*rt)->l_lights);
    if ((*rt)->upcams)
        clean_cams(&(*rt)->upcams, 4);
    if ((*rt)->middlecams)
        clean_cams(&(*rt)->middlecams, 5);
    *rt = NULL;
}

void    clean_image(t_image **image)
{
    if ((*image)->data)
    {
        free((*image)->data);
        (*image)->data = NULL;
    }
    if ((*image)->mlx_img)
    {
        free((*image)->mlx_img);
        (*image)->mlx_img = NULL;
    }
    if ((*image)->texture)
    {
        free((*image)->texture);
        (*image)->texture = NULL;
    }
    if ((*image)->screen)
    {
        free((*image)->screen);
        (*image)->screen = NULL;
    }
    if (*image)
    {
        free(*image);
        *image = NULL;
    }
}

void    clean_colors(t_colors **colors)
{
    if ((*colors)->base)
    {
        free((*colors)->base);
        (*colors)->base = NULL;
    }
    if ((*colors)->refract)
    {
        free((*colors)->refract);
        (*colors)->refract = NULL;
    }
    if ((*colors)->reflect)
    {
        free((*colors)->reflect);
        (*colors)->reflect = NULL;
    }
    if (*colors)
    {
        free(*colors);
        *colors = NULL;
    }
}

void    clean_cams(t_cam ***cams, int nb)
{
    int i;

    i = 0;
    while (i < nb)
    {
        clean_cam(&(*cams)[i]);
        i++;
    }
}

void	clean_cam(t_cam **cam)
{
    if ((*cam)->pos)
    {
    	free((*cam)->pos);
        (*cam)->pos = NULL;
    }
    if ((*cam)->vect)
    {
    	free((*cam)->vect);
        (*cam)->vect = NULL;
    }
    if ((*cam)->h_vect)
    {
    	free((*cam)->h_vect);
        (*cam)->h_vect = NULL;
    }
    if ((*cam)->r_vect)
    {
    	free((*cam)->r_vect);
        (*cam)->r_vect = NULL;
    }
    if ((*cam)->upleft)
    {
    	free((*cam)->upleft);
        (*cam)->upleft = NULL;
    }
    if (*cam)
    {
    	free(*cam);
        *cam = NULL;
    }
}

void	clean_lights(t_light **l_lights)
{
	t_light	*tmp;

	while (*l_lights)
	{
		tmp = *l_lights;
		*l_lights = (*l_lights)->next;
        if (tmp->color)
        {
    		free(tmp->color);
            tmp->color = NULL;
        }
        if (tmp->o)
        {
    		free(tmp->o);
            tmp->o = NULL;
        }
        if (tmp->d)
        {
            free(tmp->d);
            tmp->d = NULL;
        }
        if (tmp)
        {
		  free(tmp);
          tmp = NULL;
        }
	}
}

void	clean_obj(t_object **l_objects)
{
	t_object	*tmp;

	while (*l_objects)
	{
		tmp = *l_objects;
		*l_objects = (*l_objects)->next;
        if (tmp->color)
        {
    		free(tmp->color);
            tmp->color = NULL;
        }
        if (tmp->o)
        {
    		free(tmp->o);
            tmp->o = NULL;
        }
        if (tmp->d)
        {
    		free(tmp->d);
            tmp->d = NULL;
        }
        if (tmp->texture)
        {
            clean_image(&tmp->texture);
        }
        if (tmp)
        {
    		free(tmp);
            tmp = NULL;
        }
	}
}

void    clean_tab(char **tab)
{
    int i;
    
    i = 0;
    if (tab)
    {
        while (tab[i])
        {
            if (tab[i])
            {
                free(tab[i]);
                tab[i] = NULL;
            }
            i++;
        }
        if (tab)
        {
            free(tab);
            tab = NULL;
        }
    }
}
