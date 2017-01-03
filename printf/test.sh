rm main.o
rm test_printf
make fclean
make
gcc -Wall -Wextra -Werror -Iincludes/ -c main.c
gcc -o test_printf main.o -L./ -lftprintf
