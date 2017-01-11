#include <ft_printf.h>
#include <stdio.h>

int main(void)
{
  int t = 421234;
  //  ft_printf("salut %c %s %d trop trop trop\n", 'c', "Hugo", 10);
  printf("hello no flag %c\n", t );
  printf("hello flag - = %20d\n", t );
  printf("hello flag + = %+d\n", t );
  printf("hello flag 0 = %+043d\n", t );
    return (0);
}
