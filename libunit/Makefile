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
NAME = libunit.a
INC_DIR = includes
SRC_DIR = framework
OBJ_DIR = obj

SRCS = $(shell find $(SRC_DIR) -type f -follow -print | grep "\.c")

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

IFLAGS = -I $(INC_DIR) -I./libft/includes
FLAGS = -Wall -Werror -Wextra

CC = gcc $(FLAGS)
RM = /bin/rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Make $(NAME) :\033[1;32m DONE !\033[m"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(IFLAGS) -o $@ -c $<

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
