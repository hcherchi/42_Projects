#include <rtv1.h>

void	clean_ray(t_ray *ray)
{
	free(ray->o);
    free(ray->d);
	free(ray);
}

void	clean_tools(t_tool *tools)
{
	free(tools->mlx_ptr);
	free(tools->mlx_win);
    if (tools->sky)
        clean_image(tools->sky);
    clean_image(tools->image);
	clean_obj(tools->l_objects);
	clean_lights(tools->l_lights);
    clean_cams(tools->upcams, 5);
    clean_cams(tools->middlecams, 6);
}

void    clean_image(t_image *image)
{
    free(image->data);
    free(image->mlx_img);
    if (image->texture)
        free(image->texture);
    free(image);
}

void    clean_colors(t_colors *colors)
{
    free(colors->base);
    free(colors->refract);
    free(colors->reflect);
    free(colors);
}

void    clean_cams(t_cam **cams, int nb)
{
    int i;

    i = 0;
    while (i < nb)
    {
        clean_cam(cams[i]);
        i++;
    }
}

void	clean_cam(t_cam *cam)
{
	free(cam->pos);
	free(cam->vect);
	free(cam->h_vect);
	free(cam->r_vect);
	free(cam->upleft);
	free(cam);
}

void	clean_lights(t_light *l_lights)
{
	t_light	*tmp;

	while (l_lights)
	{
		tmp = l_lights;
		l_lights = l_lights->next;
		free(tmp->color);
		free(tmp->o);
        free(tmp->d);
		free(tmp);
	}
}

void	clean_obj(t_object *l_objects)
{
	t_object	*tmp;

	while (l_objects)
	{
		tmp = l_objects;
		l_objects = l_objects->next;
		free(tmp->color);
		free(tmp->o);
		free(tmp->d);
        if (tmp->texture)
            clean_image(tmp->texture);
		free(tmp);
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
            free(tab[i]);
            i++;
        }
        free(tab);
    }
}
