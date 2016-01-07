# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 18:24:56 by hcherchi          #+#    #+#              #
#    Updated: 2016/01/07 16:44:00 by hcherchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIB_NAME = libft/libft.a
INC_DIR = includes
SRC_DIR = src
OBJ_DIR = obj

SRCS = src/aux.c src/main.c src/cd.c src/path_handling.c src/set_commands.c src/tab_handling.c src/unsetenv.c src/setenv.c
	
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

IFLAGS = -I $(INC_DIR) -I libft/includes
FLAGS = -Wall -Werror -Wextra

CC = gcc $(FLAGS)
LIBFLAGS = -Llibft -lft
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
