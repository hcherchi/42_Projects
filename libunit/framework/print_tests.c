/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:01:03 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/13 23:09:57 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"

char		*green(char *str)
{
	char	*beg;
	char	*result;

	beg = ft_strjoin("\x1b[32m", str);
	free(str);
	result = ft_strjoin(beg, "\x1b[0m");
	free(beg);
	return (result);
}

char		*red(char *str)
{
	char	*beg;
	char	*result;

	beg = ft_strjoin("\x1b[31m", str);
	free(str);
	result = ft_strjoin(beg, "\x1b[0m");
	free(beg);
	return (result);
}

void		print_test(t_test *test)
{
	ft_putstr(test->name);
	free(test->name);
	ft_putstr(" -> ");
	if (!ft_strcmp(test->result, "[OK]\n"))
	{
		test->result = green(test->result);
		ft_putstr(test->result);
		free(test->result);
	}
	else
	{
		test->result = red(test->result);
		ft_putstr(test->result);
		free(test->result);
	}
}

int			print_list_of_tests(t_test *l_tests)
{
	int		count;
	int		ok;
	t_test	*tmp;

	ok = 0;
	count = 0;
	while (l_tests)
	{
		count++;
		if (ft_strcmp(l_tests->result, "[OK]\n") == 0)
			ok++;
		print_test(l_tests);
		tmp = l_tests;
		l_tests = l_tests->next;
		free(tmp);
	}
	ft_putstr("\nTOTAL: ");
	ft_putnbr(ok);
	ft_putchar('/');
	ft_putnbr(count);
	ft_putstr(" tests passed");
	return (count == ok) ? 0 : -1;
}
