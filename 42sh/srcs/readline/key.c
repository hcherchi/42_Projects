/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 14:36:42 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/18 16:53:47 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int				is_special_key(long key)
{
	if (key == 127 || key == 0x445b1b || key == 0x435b1b ||
		key == 0x44323b315b1b || key == 0x43323b315b1b ||
		key == 0x415b1b || key == 0x425b1b || key == 0x485b1b ||
		key == 0x465b1b || key == 8948194 || key == 42947
		|| key == 10127586 || key == 0x41323b315b1b || key == 0x42323b315b1b ||
		key == 04 || key == 9)
		return (1);
	return (0);
}

static void		controller_key_bis(t_readline *r, long key)
{
	if (key == 10127586)
		keyboard_paste(r);
	if (key == 0x41323b315b1b)
		go_up(r);
	if (key == 0x42323b315b1b)
		go_down(r);
	if (key == 0x05)
		keyboard_ctrlc(r);
	if (key == 04)
		keyboard_ctrld(r);
	if (key == 9)
		completion(r);
}

void			controller_key(t_readline *r, long key)
{
	if (key == 0x445b1b)
		keyboard_left(r);
	if (key == 0x435b1b)
		keyboard_right(r);
	if (key == 0x44323b315b1b)
		keyboard_left_word(r);
	if (key == 0x43323b315b1b)
		keyboard_right_word(r);
	if (key == 0x415b1b)
		up_arrow(r);
	if (key == 0x425b1b)
		down_arrow(r);
	if (key == 127)
		keyboard_delete(r);
	if (key == 0x485b1b)
		keyboard_home(r);
	if (key == 0x465b1b)
		keyboard_end(r);
	if (key == 8948194)
		keyboard_cut(r);
	if (key == 42947)
		keyboard_copy(r);
	controller_key_bis(r, key);
}
