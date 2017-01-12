rm test_printf
make
gcc -Iincludes/ -c main.c
gcc -o test_printf main.o -L./ -lftprintf
make fclean
rm main.o
./test_printf
