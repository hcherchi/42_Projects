#include "Squad.hpp"
#include "Header.hpp"
#include <iostream>

Squad::Squad(void) :
_objs(NULL)
{
  return;
}

Squad::Squad(Plane *plane) :
_objs(NULL)
{
  this->push(plane);
  return;
}

Squad::~Squad(void)
{
  t_obj *tmp = this->_objs;
  t_obj *save;

  while (tmp)
  {
    save = tmp->next;
    delete(tmp->obj);
    delete(tmp);
    tmp = save;
  }
  return;
}

Squad::Squad(Squad const & src)
{
  *this = src;
  return;
}

Squad & Squad::operator=(Squad const & src)
{
  t_obj *tmp = this->_objs;
  t_obj *save;

  while (tmp)
  {
    save = tmp->next;
    delete(tmp->obj);
    delete(tmp);
    tmp = save;
  }

  tmp = src._objs;

  if (this != &src)
  {
    this->_objs = NULL;
    while (tmp)
    {
      this->push(tmp->obj->clone());
      tmp = tmp->next;
    }
  }
  return *this;
}

int Squad::getCount() const
{
  int index = 0;
  t_obj *tmp = this->_objs;

  while (tmp)
  {
    tmp = tmp->next;
    index++;
  }
  return index;
}

Object* Squad::getUnit(int nb) const
{
  t_obj *tmp = this->_objs;
  int index = 0;

  while (tmp)
  {
    if (index == nb)
      return tmp->obj;
    tmp = tmp->next;
    index++;
  }
  return NULL;
}

int Squad::push(Object* rawObj)
{
  t_obj *tmp;
  t_obj *newObj = new t_obj;

  newObj->obj = rawObj;
  newObj->next = NULL;

  tmp = this->_objs;
  if (!tmp)
    this->_objs = newObj;
  else
  {
    while (tmp->next)
      tmp = tmp->next;
    tmp->next = newObj;
  }
  return (this->getCount());
}

void Squad::deleteUnit(int nb)
{
  t_obj *tmp = this->_objs;
  t_obj *save;

  int index = 0;
  if (tmp && index == nb)
  {
    save = tmp->next;
    delete(tmp->obj);
    delete(tmp);
    this->_objs = save;
  }
  while (tmp->next)
  {
    if (index + 1 == nb)
    {
      save = tmp->next;
      delete(tmp->next->obj);
      delete(tmp->next);
      tmp->next = save->next;
      return;
    }
    tmp = tmp->next;
    index++;
  }
}

void Squad::print(void)
{
  Object *tmp;

  for (int i = 0; i < this->getCount(); i++)
  {
    tmp = this->getUnit(i);
    tmp->print();
  }
}
