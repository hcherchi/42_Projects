/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 20:21:49 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/14 20:21:56 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libunit.h"
#include "../../real-tests/includes/test.h"

int			atoi_launcher(void)
{
	t_test	*l_tests;

	l_tests = NULL;
	ft_printname("FT_ATOI");
	add_test(&l_tests, "01_small_int", &atoi_small_int);
	add_test(&l_tests, "02_negative_int", &atoi_negative_int);
	add_test(&l_tests, "03_zero", &atoi_zero);
	add_test(&l_tests, "04_double_zero", &atoi_double_zero);
	add_test(&l_tests, "05_null_string", &atoi_null_string);
	add_test(&l_tests, "06_max_int", &atoi_max_int);
	add_test(&l_tests, "07_min_int", &atoi_min_int);
	add_test(&l_tests, "08_double_minus", &atoi_double_minus);
	add_test(&l_tests, "09_minus_plus", &atoi_minus_plus);
	add_test(&l_tests, "10_plus_minus", &atoi_plus_minus);
	add_test(&l_tests, "11_space_before", &atoi_space_before);
	add_test(&l_tests, "12_space_after", &atoi_space_after);
	add_test(&l_tests, "13_nondigit", &atoi_nondigit);
	add_test(&l_tests, "14_nondigit_after", &atoi_nondigit_after);
	add_test(&l_tests, "15_many_spaces", &atoi_many_spaces);
	add_test(&l_tests, "16_empty_string", &atoi_empty_string);
	return (launch_list_of_tests(l_tests));
}
