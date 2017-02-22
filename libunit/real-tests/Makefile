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

NAME = test_launcher
INC_DIR = includes
C_DIRS = $(shell find . -type d -follow -print | grep -v obj | grep -v includes)
C_FILES = $(shell find . -type f -follow -print | grep "\.c")

O_DIR =	obj
O_DIRS = $(C_DIRS:.%=$(O_DIR)%)
O_FILES = $(C_FILES:.%.c=$(O_DIR)%.o)

IFLAGS = -I $(INC_DIR) -I ../includes -I ../libft/includes
FLAGS = -Wall -Werror -Wextra

CC = gcc $(FLAGS)
LIBFLAGS = -L../libft -lft -L../ -lunit
RM = /bin/rm -f

all: $(NAME)

test:
	@make
	./$(NAME)

$(NAME) : $(O_FILES)
	@make -C ../libft
	@make -C ../
	@echo "Make Objects :\033[1;32m DONE !\033[m"
	@$(CC) -o $@ $^ $(LIBFLAGS)
	@echo "Make $(NAME) :\033[1;32m DONE !\033[m"

$(O_DIR)/%.o: ./%.c
	@mkdir -p $(O_DIRS)
	@$(CC) $(IFLAGS) -o $@ -c $<

clean:
	@make -C ../libft clean
	@make -C ../ clean
	@$(RM) -r $(O_DIR)
	@echo "Make clean :\033[1;31m DONE !\033[m"

fclean : clean
	@$(RM) $(NAME)
	@make -C ../libft fclean
	@make -C ../ fclean
	@echo "Make fclean :\033[1;31m DONE !\033[m"

re: fclean all

.PHONY: all clean fclean re test obj
