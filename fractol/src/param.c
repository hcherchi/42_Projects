#include "fractol.h"

void    init_param_mandelbrot(t_tool *tools)
{
	tools->image_x = 900;
	tools->image_y = 700;
  tools->i = 30;
  tools->x1 = -2;
  tools->x2 = 2;
  tools->y1 = -1.5;
  tools->y2 = 1.5;
}
