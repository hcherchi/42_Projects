#include <ft_printf.h>
#include <stdio.h>

int main(void)
{
  char *ptr;
  char nb;

  nb = 3;
  *ptr = nb;
  ft_printf("%p\n", ptr);
  //printf("%p\n", ptr);
	return (0);
}
