#include "fdf.h"

int		check_error(char **split)
{
	int i;
	int j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if (!(ft_isdigit(split[i][j]) != 0 || (j == 0 && split[i][j] == '-')))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int		fill_tools(t_tool *tools, char *filename)
{
	char *line;
	int ret;
	int fd;
	char **split;

	line = NULL;
	fd = open(filename, O_RDONLY);
	tools->nbcol = 0;
	tools->nbline = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		tools->nbline += 1;
		split = ft_strsplit(line, ' ');
		if (tools->nbcol == 0)
			tools->nbcol = tablen(split);
		else
		{
			if (tools->nbcol != tablen(split))
				return (-1);
		}
		if (check_error(split) == -1)
			return (-1);
	}
	close(fd);
	return (ret);
}
