#ifndef LIST_H
#define LIST_H

#include "./ISpaceMarine.hpp"

typedef struct s_marine
{
  ISpaceMarine *marine;
  struct s_marine *next;
}             t_marine;

#endif
