/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalmyko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 18:06:59 by akalmyko          #+#    #+#             */
/*   Updated: 2017/02/11 18:07:03 by akalmyko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H
# define RET_SUCCESSFUL 0
# define RET_FAILURE -1

/*
** ft_strlen
*/

int			strlen_launcher(void);
int			basic_test(void);
int			null_string(void);
int			empty_string(void);
int			utf8_string(void);

/*
** ft_to_upper
*/

int			toupper_launcher(void);
int			basic_test_to_upper(void);

/*
** ft_atoi
*/

int			atoi_launcher(void);
int			atoi_small_int(void);
int			atoi_negative_int(void);
int			atoi_zero(void);
int			atoi_double_zero(void);
int			atoi_null_string(void);
int			atoi_max_int(void);
int			atoi_min_int(void);
int			atoi_double_minus(void);
int			atoi_minus_plus(void);
int			atoi_plus_minus(void);
int			atoi_space_before(void);
int			atoi_space_after(void);
int			atoi_nondigit(void);
int			atoi_nondigit_after(void);
int			atoi_many_spaces(void);
int			atoi_empty_string(void);

#endif
