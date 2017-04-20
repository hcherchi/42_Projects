#include "Sorcerer.hpp"
#include "Victim.hpp"

Sorcerer::Sorcerer(void) :
_name("Anonymous"),
_title("Paysan")
{
  std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
  return;
}

Sorcerer::Sorcerer(std::string name, std::string title) :
_name(name),
_title(title)
{
  std::cout << this->_name << ", " << this->_title << ", is born !" << std::endl;
  return;
}


Sorcerer::~Sorcerer(void)
{
  std::cout << this->_name << ", " << this->_title << ", is dead. Consequences will never be the same !" << std::endl;
  return;
}

Sorcerer::Sorcerer(Sorcerer const & src)
{
  *this = src;
  return;
}

Sorcerer & Sorcerer::operator=(Sorcerer const & src)
{
  if (this != &src)
  {
    this->_name = src._name;
    this->_title = src._title;
  }
  return *this;
}

std::string Sorcerer::getName(void) const
{
  return this->_name;
}

std::string Sorcerer::getTitle(void) const
{
  return this->_title;
}

std::ostream & operator<<(std::ostream &os, Sorcerer &src)
{
  os << "I am " << src.getName() << ", " << src.getTitle() << ", and I like ponies !" << std::endl;
  return os;
}

void Sorcerer::polymorph(Victim const & victim) const
{
  victim.getPolymorphed();
}
