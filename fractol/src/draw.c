#include "fractol.h"

void    pixel_put_to_image(unsigned long color, t_tool *tools, int x, int y)
{
  char *data;
  int bpp;
  int size_line;
  int     endian;
  unsigned char r;
  unsigned char g;
  unsigned char b;

  data = mlx_get_data_addr(tools->mlx_img, &bpp, &size_line, &endian);
  r = ((color & 0xFF0000) >> 16);
  g = ((color & 0xFF00) >> 8);
  b = ((color & 0xFF));
  data[x * bpp / 8 + y * size_line] = b;
  data[x * bpp / 8 + 1 + y * size_line] = g;
  data[x * bpp / 8 + 2 + y * size_line] = r;
}

void    light_pixel_mandelbrot(t_tool *tools, int x, int y)
{
  t_complex       z;
  t_complex       c;
  t_complex       tmp;
  int i;
  int color;

  color = 0x990000;
  i = 0;
  c.x = (long double)x / (tools->image_x / (tools->x2 - tools->x1)) + tools->x1;
  c.y = (long double)y / (tools->image_y / (tools->y2 - tools->y1)) + tools->y1;
  z.x = 0.0;
  z.y = 0.0;

  while (((z.x * z.x) + (z.y * z.y)) < 4 && i < tools->i)
    {
      tmp.x = z.x;
      tmp.y = z.y;
      z.x = tmp.x * tmp.x - tmp.y * tmp.y + c.x;
      z.y = 2 * tmp.x * tmp.y + c.y;
      i += 1;
    }
  if (i == tools->i)
    pixel_put_to_image(mlx_get_color_value(tools->mlx_ptr, 0x990000), tools, x, y);
  else
    pixel_put_to_image(mlx_get_color_value(tools->mlx_ptr, 0x990000 + (10000 * i)), tools, x, y);
}
