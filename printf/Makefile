# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/03 14:53:02 by hcherchi          #+#    #+#              #
#    Updated: 2017/01/03 14:56:22 by hcherchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
INC_DIR = includes
SRC_DIR = src
OBJ_DIR = obj

SRCS = src/ft_printf.c src/print.c src/parser.c src/utils.c src/convert.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

IFLAGS = -I $(INC_DIR)
FLAGS = -Wall -Werror -Wextra

CC = gcc $(FLAGS)
RM = /bin/rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	@echo "Make Objects :\033[1;32m DONE !\033[m"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Make $(NAME) :\033[1;32m DONE !\033[m"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(IFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJS)
	@echo "Make clean :\033[1;31m DONE !\033[m"

fclean : clean
	@$(RM) $(NAME)
	@echo "Make fclean :\033[1;31m DONE !\033[m"

re: fclean all

.PHONY: all clean fclean re
