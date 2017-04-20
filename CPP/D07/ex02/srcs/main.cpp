#include "Array.hpp"

int main(void)
{
  Array<int> a(5);
  Array<int> b;

  std::cout << "Array A : ";
  for (unsigned int i = 0; i < a.size(); i++)
    std::cout << a[i] << "";
  std::cout << std::endl;

  for (unsigned int i = 0; i < a.size(); i++)
    a[i] = i;

  std::cout << "Array A (modifiee) : ";
  for (unsigned int i = 0; i < a.size(); i++)
    std::cout << a[i] << "";
  std::cout << std::endl;

  b = a;

  std::cout << "Array B (copie) : ";
  for (unsigned int i = 0; i < b.size(); i++)
    std::cout << b[i] << "";
  std::cout << std::endl;

  for (unsigned int i = 0; i < a.size(); i++)
    a[i] = i * 2;
  std::cout << std::endl;

  std::cout << "Array A (modifiee * 2) : ";
  for (unsigned int i = 0; i < a.size(); i++)
    std::cout << a[i] << "";
  std::cout << std::endl;

  std::cout << "Array B (apres modification de A) : ";
  for (unsigned int i = 0; i < b.size(); i++)
    std::cout << b[i] << "";

  b[b.size()] = 0;
  std::cout << std::endl;

  return 0;
}
