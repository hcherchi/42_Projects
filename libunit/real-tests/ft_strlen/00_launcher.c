/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:08:51 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/11 18:08:58 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libunit.h"
#include "../../real-tests/includes/test.h"

int			strlen_launcher(void)
{
	t_test	*l_tests;

	l_tests = NULL;
	ft_printname("FT_STRLEN");
	add_test(&l_tests, "01_basic_test", &basic_test);
	add_test(&l_tests, "02_null_string", &null_string);
	add_test(&l_tests, "03_empty_string", &null_string);
	add_test(&l_tests, "04_utf8_string", &utf8_string);
	return (launch_list_of_tests(l_tests));
}
