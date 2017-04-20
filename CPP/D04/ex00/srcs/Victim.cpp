#include "Victim.hpp"

Victim::Victim(void) :
_name("Anonymous")
{
  std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
  return;
}

Victim::Victim(std::string name) :
_name(name)
{
  std::cout << "Some random victim called " << this->_name << " just popped !" << std::endl;
  return;
}

Victim::~Victim(void)
{
  std::cout << "Victim " << this->_name << " just died for no apparent reason !" << std::endl;
  return;
}

Victim::Victim(Victim const & src)
{
  *this = src;
  return;
}

Victim & Victim::operator=(Victim const & src)
{
  if (this != &src)
  {
    this->_name = src._name;
  }
  return *this;
}

std::string Victim::getName(void) const
{
  return this->_name;
}

std::ostream & operator<<(std::ostream &os, Victim &src)
{
  os << "I'm " << src.getName() << " and I like otters !" << std::endl;
  return os;
}

void Victim::getPolymorphed(void) const
{
  std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}
