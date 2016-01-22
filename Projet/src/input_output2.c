/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 19:20:40 by bgantelm          #+#    #+#             */
/*   Updated: 2016/01/22 19:21:22 by bgantelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	fill_close_stand(t_command *new, char *subcmdr)
{
	new->close_stand = 0;
	if (ft_strstr(subcmdr, "<&-"))
		new->close_stand = 1;
}
