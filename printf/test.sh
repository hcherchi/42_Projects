rm test_printf
make
gcc -I includes/ -c main_gavizet.c
gcc -o test_printf main_gavizet.o -L./ -lftprintf
make fclean
rm main_gavizet.o
./test_printf
