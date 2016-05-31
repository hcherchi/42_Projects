/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 19:31:59 by vnguyen           #+#    #+#             */
/*   Updated: 2016/05/31 21:02:31 by fhenri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	parse_camera_suite(t_tool *tools, char **split)
{
	if (str_digit(split[1]) || str_digit(split[2]))
		ft_error(2, tools);
	if (ft_atof(split[1]) > 2000 || ft_atof(split[2]) > 1300)
		ft_error(13, tools);
	if (ft_atoi(split[1]) < 0 || ft_atoi(split[2]) < 0)
		ft_error(8, tools);
	tools->rt->x_res = ft_atoi(split[1]);
	tools->rt->y_res = ft_atoi(split[2]);
}

void	parse_camera(t_tool *tools, int fd)
{
	char	**split;
	char	*line;

	while (get_next_line(fd, &line) > 0 && ft_strcmp(line, "}"))
	{
		split = ft_strsplit(line, ' ');
		if (ft_strstr(line, "pos:"))
			tools->rt->pos = fill_pos(split, tools);
		else if (ft_strstr(line, "res:"))
		{
			if (ft_tablen(split) == 3)
				parse_camera_suite(tools, split);
			else
				ft_error(7, tools);
		}
		else
			parse_camera2(line, tools, split);
		clean_tab(split);
		free(line);
	}
}

void	parse_camera2(char *line, t_tool *tools, char **split)
{
	if (ft_strstr(line, "lumamb:"))
	{
		if (ft_tablen(split) == 2)
			tools->rt->lumamb = ft_atof(split[1]);
		else
			ft_error(7, tools);
	}
	else if (ft_strstr(line, "vect:"))
	{
		tools->rt->vect = fill_pos(split, tools);
	}
	else if (ft_strstr(line, "skybox:"))
	{
		if (ft_tablen(split) == 2)
			tools->rt->sky = fill_texture(split[1], tools);
		else
			ft_error(7, tools);
	}
	else if (ft_strcmp(line, "{"))
		ft_error(1, tools);
}

int		roud_boucle(t_tool *tools, int c, int fd, char *line)
{
	if (!ft_strcmp(line, "camera"))
	{
		c++;
		free(line);
		parse_camera(tools, fd);
	}
	else if (!ft_strcmp(line, "light"))
	{
		free(line);
		parse_light(tools, fd);
	}
	else if (!ft_strcmp(line, "object"))
	{
		free(line);
		parse_object(tools, fd);
	}
	return (c);
}

void	parser(int fd, t_tool *tools)
{
	char	*line;
	int		c;
	int		ret;

	c = 0;
	tools->rt = malloc(sizeof(t_rt));
	tools->rt->l_objects = NULL;
	tools->rt->l_lights = NULL;
	tools->rt->mlx_win = NULL;
	init_camera(tools);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		c = roud_boucle(tools, c, fd, line);
	}
	if (ret == -1)
		ft_error(10, tools);
	if (c != 1)
		ft_error(6, tools);
}
