#include <rtv1.h>

int		event(int keycode, t_tool *t)
{
    ft_putnbr(keycode);
	if (keycode == 53 && t)
	{
		clean_tools(t);
		exit(0);
	}
    else if (keycode == 82)
        t->cam = t->middlecams[5];
    else if (keycode == 84)
        t->cam = t->upcams[0];
    else if (keycode == 86)
        t->cam = t->upcams[1];
    else if (keycode == 87)
        t->cam = t->upcams[4];
    else if (keycode == 88)
        t->cam = t->upcams[2];
    else if (keycode == 91)
        t->cam = t->upcams[3];
    else if (keycode == 126 && t->cam->nb != 5)
        t->cam = t->upcams[t->cam->nb];
    else if (keycode == 125 && t->cam->nb != 5)
        t->cam = t->middlecams[t->cam->nb];
    run_through(t);
	return (0);
}