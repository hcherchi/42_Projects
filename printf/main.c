#include <ft_printf.h>
#include <stdio.h>

int main(void)
{
  printf("%05d\n", -42);
  ft_printf("%05d", -42);
	return (0);
}
