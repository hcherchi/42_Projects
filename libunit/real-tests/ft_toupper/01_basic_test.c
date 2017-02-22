/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 21:50:56 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/13 11:25:01 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_return(void)
{
	int		a;
	int		res;

	a = 97;
	res = ft_toupper(a);
	if (res == 65)
		return (0);
	else
		return (-1);
}

int			basic_test_to_upper(void)
{
	if (ft_check_return() == 0)
		return (0);
	else
		return (-1);
}
