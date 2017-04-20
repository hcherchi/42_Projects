#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <time.h>

void identify_from_pointer(Base *p)
{
  if (dynamic_cast<A*>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "C" << std::endl;
}

void identify_from_reference(Base &p)
{
  A a;
  B b;

  try
  {
    a = dynamic_cast<A &>(p);
    std::cout << "A" << std::endl;
  }
  catch (std::exception &e)
  {
    try
    {
      b = dynamic_cast<B &>(p);
      std::cout << "B" << std::endl;
    }
    catch (std::exception &e)
    {
      std::cout << "C" << std::endl;
    }
  }
}

Base *generate(void)
{
  Base *newPointer;

  std::srand(time(NULL));
  int random = std::rand() % 3;
  switch (random)
  {
    case 0:
      newPointer = new A();
      break;
    case 1:
      newPointer = new B();
      break;
    case 2:
      newPointer = new C();
      break;
    default:
      newPointer = new A();
      break;
  }
  return newPointer;
}

int main(void)
{
  Base *newPointer = generate();
  identify_from_pointer(newPointer);
  identify_from_reference(*newPointer);
  return (0);
}
