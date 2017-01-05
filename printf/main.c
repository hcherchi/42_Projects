#include <ft_printf.h>
#include <stdio.h>

int main(void)
{
    ft_printf("salut %s %s %%d trop trop trop\n", "Hugo", "est");
    printf("salut %s %s %%d trop trop trop", "Hugo", "est");
    return (0);
}
