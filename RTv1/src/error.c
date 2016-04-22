#include <rtv1.h>

void	ft_error(int i, t_tool *tools)
{
	ft_putendl("lol");
	if (i == 1)
		ft_putstr("Error, bad argument in camera. use just pos, res, vect, lumamb and skybox.\n");
	else if (i == 2)
		ft_putstr("Error, arguments need numbers.\n");
	else if (i == 3)
	{
		ft_putstr("Error, bad argument in light. ");
		ft_putstr("use just pos color, h, type, lumdiff.\n");
	}
	else if (i == 4)
	{
		ft_putstr("Error, bad argument in object, ");
		ft_putstr("use just type, pos, dir, rayon, color, h, shiny, mirror, refract, texture.\n");
	}
	else if (i == 5)
		ft_putstr("Error, bad type of object.\n");
	else if (i == 6)
		ft_putstr("Error, you need one and only one camera.\n");
	else if (i == 7)
		ft_putstr("Error, bad numbers of argument.\n");
	else if (i == 8)
		ft_putstr("Error, window can not be negative.\n");
	else if (i == 9)
		ft_putstr("Error parser object.\n");
    else if (i == 10)
        ft_putstr("Invalid File.\n");
    else if (i == 11)
        ft_putendl("Invalid texture");
    else if (i == 12)
        ft_putendl("Error, bad type of object.\n");
    tools->error = 1;
    tools->no_error = 1;
}