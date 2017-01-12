#include <ft_printf.h>
#include <stdio.h>

int main(void)
{
    ft_printf("salut %c %++255.56hhs %d trop trop trop\n", 'c', "Hugo", 10);
	return (0);
}
