/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:01:44 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/13 17:59:06 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"

t_test	*new_test(char *name, void *function)
{
	t_test		*new_test;

	new_test = (t_test*)malloc(sizeof(t_test) * 1);
	if (!new_test)
		return (NULL);
	new_test->name = ft_strdup(name);
	new_test->function = function;
	new_test->next = NULL;
	new_test->result = NULL;
	return (new_test);
}

void	add_test(t_test **l_tests, char *name, int (*test)(void))
{
	t_test		*tmp;

	tmp = *l_tests;
	if (!tmp)
		*l_tests = new_test(name, *&test);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_test(name, *&test);
	}
}

void	launch_test(t_test *test)
{
	int			res;

	res = test->function();
	if (res == RET_SUCCESSFUL)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}

int		launch_list_of_tests(t_test *l_tests)
{
	t_test		*tmp;
	pid_t		pid;
	int			status;

	tmp = l_tests;
	while (tmp)
	{
		pid = fork();
		if (pid < 0)
			tmp->result = ft_strdup("[KO]");
		else if (pid == 0)
			launch_test(tmp);
		else
		{
			wait(&status);
			if (WIFSIGNALED(status))
				tmp->result = not_proper_exit(status);
			else
				tmp->result = proper_exit(status);
			tmp = tmp->next;
		}
	}
	return (print_list_of_tests(l_tests));
}
