#include <rtv1.h>

int		event(int k, t_tool *t)
{
	if (k == 53 && t)
	{
		clean_tools(t);
		exit(0);
	}
    else if (k == 82 || k == 84 || k == 86 || k == 87 || k == 88 || k == 91 || k == 126 || k == 125)
    {
        if (k == 82)
            t->cam = t->middlecams[5];
        else if (k == 84)
            t->cam = t->upcams[0];
        else if (k == 86)
            t->cam = t->upcams[1];
        else if (k == 87)
            t->cam = t->upcams[4];
        else if (k == 88)
            t->cam = t->upcams[2];
        else if (k == 91)
            t->cam = t->upcams[3];
        else if (k == 126 && t->cam->nb != 5)
            t->cam = t->upcams[t->cam->nb];
        else if (k == 125 && t->cam->nb != 5)
            t->cam = t->middlecams[t->cam->nb];
        mlx_clear_window(t->mlx_ptr, t->mlx_win);
        run_through(t);
    }
	return (0);
}