NAME = libft.a
SRC_NAME = btree_apply_infix.c btree_apply_prefix.c btree_apply_suffix.c btree_create_node.c \
		   btree_insert_data.c btree_level_count.c btree_search_item.c ft_atoi.c ft_bsort.c \
		   ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		   ft_isspace.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
		   ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
		   ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
		   ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
		   ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
		   ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
		   ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
		   ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c \
		   ft_toupper.c ft_lst_push_back.c ft_lst_strsplit.c ft_itoa_base.c ft_uitoa_base.c \
		   ft_putwchar.c ft_strlen_wchar.c ft_round.c get_next_line.c ft_isnumber.c ft_tabdel.c \
		   ft_strlower.c ft_strupper.c \
		   ft_printf.c ft_get_index.c ft_init_char_tab.c ft_realloc.c match.c \
		   ptf_booleans.c ptf_put_colors.c ptf_hour_controller.c ptf_process_instruction.c ptf_process_conversion.c \
		   ptf_preci_field_controller.c ptf_flag_controller.c ptf_modifier_controller.c ptf_controller_di.c \
		   ptf_controller_o.c ptf_controller_xp.c ptf_controller_cs.c ptf_controller_u.c ptf_controller_b.c \
		   ptf_controller_f.c ptf_controller_n.c ptf_controller_a.c ptf_controller_e.c ptf_padding_ws.c \
		   ptf_padding_c.c ptf_padding_e.c ptf_padding_f.c ft_strnsplit.c read_next_line.c ft_add_char.c
OBJ_NAME = $(SRC_NAME:.c=.o) 
OBJ_PATH = obj/
SRC_PATH = src/
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
SRCI = libft.h
FLAGS = -Wall -Werror -Wextra
INC = -Iinclude

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all : $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	gcc $(FLAGS) -o $@ -c $< $(INC)
clean :
	@rm -rf $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean : clean
	@rm -rf $(OBJ) $(NAME)

re : fclean all

.PHONY : all clean fclean re
