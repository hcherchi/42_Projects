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

NAME = npuzzle
INC_DIR = includes
C_DIRS = $(shell find src -type d -follow -print)
C_FILES = $(shell find src -type f -follow -print | grep "\.c")

O_DIR =	obj
O_DIRS = $(C_DIRS:src%=$(O_DIR)%)
O_FILES = $(C_FILES:src%.c=$(O_DIR)%.o)

IFLAGS = -I $(INC_DIR) -I ../libft/includes
FLAGS = -Wall -Werror -Wextra

CC = gcc $(FLAGS)
LIBFLAGS = -L../libft -lft
RM = /bin/rm -f

all: $(NAME)

$(NAME) : $(O_FILES)
	@make -C ../libft
	@echo "Make Objects :\033[1;32m DONE !\033[m"
	@$(CC) -o $@ $^ $(LIBFLAGS)
	@echo "Make $(NAME) :\033[1;32m DONE !\033[m"

$(O_DIR)/%.o: src/%.c
	@mkdir -p $(O_DIRS)
	@$(CC) $(IFLAGS) -o $@ -c $<

clean:
	@make -C ../libft clean
	@$(RM) -r $(O_DIR)
	@echo "Make clean :\033[1;31m DONE !\033[m"

fclean : clean
	@$(RM) $(NAME)
	@make -C ../libft fclean
	@echo "Make fclean :\033[1;31m DONE !\033[m"

re: fclean all

.PHONY: all clean fclean re test obj
