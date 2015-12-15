# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcherchi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 18:24:56 by hcherchi          #+#    #+#              #
#    Updated: 2015/12/15 16:07:43 by hcherchi         ###   ########.fr        #
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
	@echo "Make Objects :\033[1;32m DONE !\033[m"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Make libft.a :\033[1;32m DONE !\033[m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -o $@ -c $<

clean:
	@$(RM) $(OBJS)
	@echo "Make clean :\033[1;32m DONE !\033[m"

fclean : clean
	@$(RM) $(NAME)
	@echo "Make fclean :\033[1;32m DONE !\033[m"

re: fclean all

.PHONY: all clean fclean re
