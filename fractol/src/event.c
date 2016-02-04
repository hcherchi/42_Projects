#include "fractol.h"
#include <stdio.h>

int             key_press(int key, t_tool *tools)
{
  printf("Bouton : %d\n", key);
  if (key == 53)
    exit(0);
  else if (key == 78)
    tools->i -= 20;
  else if (key == 69)
    tools->i += 20;
  mlx_destroy_image(tools->mlx_ptr, tools->mlx_img);
  run_through(tools, light_pixel_mandelbrot);
  return(0);
}

int             mouse_hook(int button, int x, int y, t_tool *tools)
{
  long double newx;
  long double newy;
  long double xspan;
  long double yspan;
  long double tmp;

  xspan = tools->x2 - tools->x1;
  yspan = tools->y2 - tools->y1;
  newx = x / (tools->image_x / (tools->x2 - tools->x1)) + tools->x1;
  newy = y / (tools->image_y / (tools->y2 - tools->y1)) + tools->y1;
  printf("Bouton : %d, x : %d / y : %d\n", button, x, y);
  if (button == 5)
    {
      tmp = tools->x1;
      tools->x1 = (newx + (tools->x2 + tools->x1)/2) /2 - (xspan * 0.4);
      tools->x2 = (newx + (tools->x2 + tmp)/2) /2 + (xspan * 0.4);
      tmp = tools->y1;
      tools->y1 = (newy + (tools->y2 + tools->y1)/2) /2 - (yspan * 0.4);
      tools->y2 = (newy + (tools->y2 + tmp)/2) /2 + (yspan *0.4);
    }
  else if (button == 4)
    {
      tools->x1 = tools->x1 - (xspan * 0.52);
      tools->x2 = tools->x2 + (xspan * 0.52);
      tools->y1 = tools->y1 - (yspan * 0.52);
      tools->y2 = tools->y2 + (yspan *0.52);
    }
  mlx_destroy_image(tools->mlx_ptr, tools->mlx_img);
  run_through(tools, light_pixel_mandelbrot);
  return(0);
}
