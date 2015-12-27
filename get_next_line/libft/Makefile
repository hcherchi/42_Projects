# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 18:24:56 by hcherchi          #+#    #+#              #
#    Updated: 2015/12/08 14:24:04 by hcherchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INC_DIR = includes
SRC_DIR = src
OBJ_DIR = obj

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

FLAGS = -I $(INC_DIR) -Wall -Werror -Wextra

CC = gcc $(FLAGS)

RM = /bin/rm -f

all: $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Make libft.a :\033[1;32m DONE !\033[m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -o $@ -c $<

clean:
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
