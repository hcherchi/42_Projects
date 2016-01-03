#include "get_next_line.h"
#include <fcntl.h>

int main(int ac, char **av)
{
    char *line;
    int fd;
    
    if (ac == 1)
    {
        while (get_next_line(0, &line) == 1)
		{
            ft_putendl(line);
			free(line);
		}
    }
    else if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        while (get_next_line(fd, &line) == 1)
        {
            ft_putendl(line);
			free(line);
        }
    }
    else
        ft_putendl("Error");
    return (0);
}
