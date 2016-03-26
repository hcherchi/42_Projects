/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 15:49:14 by hcherchi          #+#    #+#             */
/*   Updated: 2016/03/26 11:45:33 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	parse_light2(t_light *light, char **split, char *line)
{
	if (ft_strstr(line, "pos:"))
		light->o = fill_pos(split);
	else if (ft_strstr(line, "color:"))
		light->color = fill_color(split);
	else if (ft_strstr(line, "dist:"))
	{
		if (ft_tablen(split) != 2)
			ft_error(7);
		if (str_digit(split[1]))
			ft_error(2);
		light->dist = ft_atof(split[1]);
	}
	else if (ft_strstr(line, "LumDiff:"))
	{
		if (ft_tablen(split) != 2)
			ft_error(7);
		light->lumdiff = ft_atof(split[1]);
	}
	else if (ft_strcmp(line, "{"))
		ft_error(3);
}

void	parse_light(t_tool *tools, int fd)
{
	char	**split;
	char	*line;
	t_light	*light;

	light = malloc(sizeof(*light));
	light->next = NULL;
	init_light(light);
	while (get_next_line(fd, &line) > 0 && !ft_strstr(line, "}"))
	{
		split = ft_strsplit(line, ' ');
		parse_light2(light, split, line);
	}
	add_light(&tools->l_lights, light);
}
