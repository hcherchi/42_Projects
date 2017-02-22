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

static int	atoi_nondigit_after_test(void)
{
	char	*str;
	int		result;

	str = "10asd";
	result = ft_atoi(str);
	if (result == 10)
		return (0);
	else
		return (-1);
}

int			atoi_nondigit_after(void)
{
	if (atoi_nondigit_after_test() == 0)
		return (0);
	else
		return (-1);
}
