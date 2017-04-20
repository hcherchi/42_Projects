#include "Squad.hpp"

Squad::Squad(void) :
_marines(NULL)
{
  return;
}

Squad::~Squad(void)
{
  t_marine *tmp = this->_marines;
  t_marine *save;

  while (tmp)
  {
    save = tmp->next;
    delete(tmp->marine);
    delete(tmp);
    tmp = save;
  }
  return;
}

Squad::Squad(Squad const & src)
{
  t_marine *tmp = this->_marines;
  t_marine *save;

  while (tmp)
  {
    save = tmp->next;
    delete(tmp->marine);
    delete(tmp);
    tmp = save;
  }
  *this = src;
  return;
}

Squad & Squad::operator=(Squad const & src)
{
  t_marine *tmp = src._marines;

  if (this != &src)
  {
    this->_marines = NULL;
    while (tmp)
    {
      this->push(tmp->marine->clone());
      tmp = tmp->next;
    }
  }
  return *this;
}

int Squad::getCount() const
{
  int index = 0;
  t_marine *tmp = this->_marines;

  while (tmp)
  {
    tmp = tmp->next;
    index++;
  }
  return index;
}

ISpaceMarine* Squad::getUnit(int nb) const
{
  t_marine *tmp = this->_marines;
  int index = 0;

  while (tmp)
  {
    if (index == nb)
      return tmp->marine;
    tmp = tmp->next;
    index++;
  }
  return NULL;
}

int Squad::push(ISpaceMarine* rawMarine)
{
  t_marine *tmp;
  t_marine *newMarine = new t_marine;

  newMarine->marine = rawMarine;
  newMarine->next = NULL;

  tmp = this->_marines;
  if (!tmp)
    this->_marines = newMarine;
  else
  {
    while (tmp->next)
      tmp = tmp->next;
    tmp->next = newMarine;
  }
  return (this->getCount());
}
