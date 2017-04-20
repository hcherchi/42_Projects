#include <iostream>

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

template< typename T >
void iter(T array[], size_t len, void (* f)(T const & arg))
{
  for (size_t i = 0; i < len; i++)
    f(array[i]);
}

int main()
{
  int tab[] = { 0, 1, 2, 3, 4 };

  iter( tab, 5, print );

  return 0;
}
