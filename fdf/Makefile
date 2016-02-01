# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 18:24:56 by hcherchi          #+#    #+#              #
#    Updated: 2016/02/01 12:11:00 by hcherchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIB_NAME = libft/libft.a
INC_DIR = includes
SRC_DIR = src
OBJ_DIR = obj

SRCS = src/draw.c src/error.c src/main.c src/point_handling.c src/set_fdf.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

IFLAGS = -I $(INC_DIR) -I libft/includes
FLAGS = -Wall -Werror -Wextra

CC = gcc $(FLAGS)
LIBFLAGS = -Llibft -lft -lmlx -framework OpenGL -framework AppKit
RM = /bin/rm -f

all: $(LIB_NAME) $(NAME)

$(LIB_NAME) :
	@make -C libft re

$(NAME) : $(OBJS)
	@echo "Make Objects :\033[1;32m DONE !\033[m"
	@$(CC) -o $@ $^ $(LIBFLAGS)
	@echo "Make $(NAME) :\033[1;32m DONE !\033[m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(IFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJS)
	@make -C libft clean
	@echo "Make clean :\033[1;31m DONE !\033[m"

fclean : clean
	@$(RM) $(NAME)
	@make -C libft fclean
	@echo "Make fclean :\033[1;31m DONE !\033[m"

re: fclean all

.PHONY: all clean fclean re
