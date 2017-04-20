#ifndef LIST_H
#define LIST_H

#include "Object.hpp"

typedef struct s_obj
{
  Object *obj;
  struct s_obj *next;
}             t_obj;

#endif
