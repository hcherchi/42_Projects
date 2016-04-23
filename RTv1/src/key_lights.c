#include <rtv1.h>

void	modif_all_lights(t_tool *k, double value)
{
	t_light *ptr;

	ptr = k->rt->l_lights;
	if (k->rt->l_lights == NULL)
		return;
	while (ptr != NULL)
	{
		ptr->lumdiff += value;
		ptr = ptr->next;
	}
}

void	modif_lumamb(t_tool *k, double value)
{
	k->rt->lumamb += value;
}

void	update_loading_menu(t_tool *t, int y)
{
	char *str;

	y = y / 10;
	if (y < 0 )
		return;
	str = (char*)malloc(sizeof(char) * 30);
	ft_strcpy(str, "RT is loading..");
	ft_strcat(str, ft_itoa(y));
	ft_putstr(str);
	ft_putchar('\n');
	mlx_destroy_window(t->mlx_ptr, t->rt->mlx_win);
	t->rt->mlx_win = mlx_new_window(t->mlx_ptr, t->rt->x_res, t->rt->y_res, "RT");
	mlx_string_put(t->mlx_ptr, t->rt->mlx_win, t->rt->x_res/2 - 50, t->rt->y_res/2, 0xFFFFFFFF, str);
	mlx_put_image_to_window(t->mlx_ptr, t->rt->mlx_win, t->rt->image_loading->mlx_img, 0, 0);
}
