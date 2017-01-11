#include <ft_printf.h>
#include <stdio.h>

int main(void)
{
   unsigned int t = 421234000;
  //  ft_printf("salut %c %s %d trop trop trop\n", 'c', "Hugo", 10);
  //printf("hello no flag %c\n", t );
  printf("hello flag #x = %#23o\n", t );
  printf("hello flag x = %o\n", t );
//  printf("hello flag 0 = %+043d\n", t );
    return (0);
}
