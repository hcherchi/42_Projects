# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcherchi <hcherchi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 18:24:56 by hcherchi          #+#    #+#              #
#    Updated: 2017/04/08 15:27:23 by tvisenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro
INC_DIR = includes
SRC_DIR = srcs
C_DIRS = $(shell find $(SRC_DIR) -type d -follow -print)
C_FILES = $(shell find $(SRC_DIR) -type f -follow -print)

O_DIR =	.obj
O_DIRS = $(C_DIRS:$(SRC_DIR)%=$(O_DIR)%)
O_FILES = $(C_FILES:$(SRC_DIR)%.cpp=$(O_DIR)%.o)

IFLAGS = -I $(INC_DIR)
FLAGS = -Wall -Werror -Wextra

CC = g++ $(FLAGS)
RM = /bin/rm -f

all: $(NAME)

$(NAME) : $(O_FILES)
	@echo "Make Objects :\033[1;32m DONE !\033[m"
	@$(CC) -lncurses -o $@ $^
	@echo "Make $(NAME) :\033[1;32m DONE !\033[m"

$(O_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(O_DIRS)
	@$(CC) $(IFLAGS) -o $@ -c $<

clean:
	@$(RM) -r $(O_DIR)
	@echo "Make clean :\033[1;31m DONE !\033[m"

fclean : clean
	@$(RM) $(NAME)
	@echo "Make fclean :\033[1;31m DONE !\033[m"

re: fclean all

.PHONY: all clean fclean re test obj
