/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 16:26:36 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/17 15:31:51 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_NEXT_LINE_H
# define READ_NEXT_LINE_H

typedef struct			s_buffline
{
	char				*buff;
	int					fd;
	struct s_buffline	*next;
}						t_buffline;
t_buffline				*new_buff(int const fd, t_buffline *next);
void					get_buffer(int const fd, t_buffline **first);
int						read_next_line(int const fd, char **line, char sep);
int						gnl(int const fd, char **line, t_buffline *b, char sep);
#endif
