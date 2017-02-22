/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_small_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 20:24:04 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/14 20:24:06 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			atoi_small_int_test(void)
{
	char	*str;
	int		result;

	str = "12";
	result = ft_atoi(str);
	if (result == 12)
		return (0);
	else
		return (-1);
}

int			atoi_small_int(void)
{
	if (atoi_small_int_test() == 0)
		return (0);
	else
		return (-1);
}
