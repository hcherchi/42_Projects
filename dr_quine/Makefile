#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/18 17:05:54 by hcherchi          #+#    #+#              #
#    Updated: 2016/06/01 15:15:17 by hcherchi         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: colleen sully grace

colleen:
		clang -Wall -Wextra -Werror Colleen.c -o Colleen

sully:
		clang -Wall -Wextra -Werror Sully.c -o Sully

grace:
		clang -Wall -Wextra -Werror Grace.c -o Grace

clean:
		rm -rf Grace_kid.c Sully_5 Sully_4 Sully_3 Sully_2 Sully_1 Sully_0 Sully_5.c Sully_4.c Sully_3.c Sully_2.c Sully_1.c Sully_0.c

fclean: clean
		rm -f Colleen Sully Grace
re: fclean all

.PHONY: all clean fclean re
