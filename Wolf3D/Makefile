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

NAME = wolf3d
LIB_NAME = ../libft/libft.a
INC_DIR = includes
SRC_DIR = src
OBJ_DIR = obj

SRCS = src/main.c src/draw.c src/vertical.c src/horizontal.c src/util.c src/parser.c src/clean.c src/event.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

IFLAGS = -I $(INC_DIR) -I ../libft/includes -I ../mlx
FLAGS = -Wall -Werror -Wextra

CC = gcc $(FLAGS)
LIBFLAGS = -L../libft -L../mlx -lft -lmlx -framework OpenGL -framework AppKit
RM = /bin/rm -f

all: $(LIB_NAME) $(NAME)

$(LIB_NAME) :
	@make -C ../libft

$(NAME) : $(OBJS)
	@echo "Make Objects :\033[1;32m DONE !\033[m"
	@$(CC) -o $@ $^ $(LIBFLAGS)
	@echo "Make $(NAME) :\033[1;32m DONE !\033[m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(IFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJS)
	@make -C ../libft clean
	@echo "Make clean :\033[1;31m DONE !\033[m"

fclean : clean
	@$(RM) $(NAME)
	@make -C ../libft fclean
	@echo "Make fclean :\033[1;31m DONE !\033[m"

re: fclean all

.PHONY: all clean fclean re
