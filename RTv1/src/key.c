#include <Rtv1.h>

int		event(int keycode, t_tool *t)
{
    if (keycode == 53 && t)
        exit(0);
    if (keycode == 123)
    {
        t->cam->vect->x = 1;
        t->cam->vect->z = 0;
        vectorNorm(t->cam->vect);
        t->cam->pos = vectorNew(-2.9, 0, 5);
        run_through(t);
    }
    else if (keycode == 124)
    {
        t->cam->vect->x = -1;
        t->cam->vect->z = 0;
        vectorNorm(t->cam->vect);
        t->cam->pos = vectorNew(2.9, 0, 5);
        run_through(t);
    }
    else if (keycode == 125)
    {
        t->cam->vect->x = 0;
        t->cam->vect->z = 1;
        vectorNorm(t->cam->vect);
        t->cam->pos = vectorNew(0, 0, 0);
        run_through(t);
    }
    ft_putnbr(keycode);
    return (0);
}