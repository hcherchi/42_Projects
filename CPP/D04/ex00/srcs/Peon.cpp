#include "Peon.hpp"

Peon::Peon(void) :
Victim("Anonymous")
{
  std::cout << "Zog zog." << std::endl;
  return;
}

Peon::Peon(std::string name) :
Victim(name)
{
  std::cout << "Zog zog." << std::endl;
  return;
}

Peon::~Peon(void)
{
  std::cout << "Bleuark..." << std::endl;
  return;
}

Peon::Peon(Peon const & src)
{
  *this = src;
  return;
}

Peon & Peon::operator=(Peon const & src)
{
  if (this != &src)
  {
    this->_name = src._name;
  }
  return *this;
}

void Peon::getPolymorphed(void) const
{
  std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
}
