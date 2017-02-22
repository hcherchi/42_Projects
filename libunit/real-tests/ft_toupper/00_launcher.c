/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 19:52:16 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/13 23:11:56 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libunit.h"
#include "../../real-tests/includes/test.h"

int		toupper_launcher(void)
{
	t_test	*l_tests;

	l_tests = NULL;
	ft_printname("FT_TO_UPPER");
	add_test(&l_tests, "01_basic_test", &basic_test_to_upper);
	return (launch_list_of_tests(l_tests));
}
