/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:05:04 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/13 23:10:59 by hcherchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>
# define RET_SUCCESSFUL 0
# define RET_FAILURE -1

typedef struct	s_test
{
	int				(*function) (void);
	char			*name;
	char			*result;
	struct s_test	*next;
}				t_test;

t_test			*new_test(char *name, void *function);
void			add_test(t_test **l_tests, char *name, int(*test)(void));
int				launch_list_of_tests(t_test *l_tests);
void			launch_test(t_test *test);
char			*ft_strdup(char *str);
void			ft_putstr(char *str);
int				ft_strlen(const char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strcpy(char *dst, char *src);
char			*ft_strcat(char *s1, char *s2);
void			ft_putnbr(int n);
void			ft_putchar(char c);
void			ft_printname(char *str);
int				print_list_of_tests(t_test *l_tests);
void			print_test(t_test *test);
char			*proper_exit(int signal);
char			*not_proper_exit(int signal);

#endif
