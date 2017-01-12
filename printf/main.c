#include <ft_printf.h>
#include <stdio.h>

int main(void)
{
  char *ptr;
  char nb;

  nb = 3;
  *ptr = nb;
  ft_printf("%hhd\n", 42);
  //printf("%p\n", ptr);
	return (0);
}
