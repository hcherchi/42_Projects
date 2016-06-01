#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgantelm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/18 17:05:54 by bgantelm          #+#    #+#              #
#    Updated: 2016/06/01 15:15:17 by hcherchi         ###   ########.fr        #
#    Updated: 2016/05/31 19:33:49 by vnguyen          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = RT
LIB_NAME = libft/libft.a
INC_DIR = includes
SRC_DIR = src
OBJ_DIR = obj

SRCS = src/main.c src/parse_tools.c src/parser.c src/draw.c src/inter.c src/normal.c src/vector.c src/color.c src/error.c src/init.c src/vector2.c src/illuminate.c src/key.c src/clean.c src/clean2.c src/clean3.c src/parser2.c src/rays.c src/inter2.c src/texture.c src/menu.c src/launch.c src/launch2.c src/parser3.c src/key_lights.c src/menu1.c src/color2.c src/key_suite.c src/parse4.c src/flash.c src/pixel_color.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

IFLAGS = -I $(INC_DIR) -I libft/includes -I ~/mlx
FLAGS = -Wall -Werror -Wextra

CC = gcc $(FLAGS)
LIBFLAGS = -Llibft -lft -lmlx -framework OpenGL -framework AppKit
RM = /bin/rm -f

all: $(LIB_NAME) $(NAME)

$(LIB_NAME) :
	@make -C libft re

$(NAME) : $(OBJS)
	@echo "Make Objects :\033[1;32m DONE !\033[m"
	@$(CC) -o $@ $^ $(LIBFLAGS) -O3
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
