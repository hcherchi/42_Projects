/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_negative_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 20:31:21 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/14 20:31:22 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	atoi_min_int_test(void)
{
	char	*str;
	int		result;

	str = "-2147483649";
	result = ft_atoi(str);
	if (result == 0)
		return (0);
	else
		return (-1);
}

int			atoi_min_int(void)
{
	if (atoi_min_int_test() == 0)
		return (0);
	else
		return (-1);
}
