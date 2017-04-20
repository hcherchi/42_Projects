# ifndef SQUAD_HPP
# define SQUAD_HPP

#include "List.hpp"
#include "Plane.hpp"

class Squad
{
  protected:
    t_obj *_objs;

  public:
    Squad(void);
    Squad(Plane *plane);
    ~Squad(void);
    Squad(const Squad & src);
    Squad & operator = (const Squad & src);

    int getCount() const;
    Object* getUnit(int) const;
    int push(Object*);
    void deleteUnit(int nb);
	void print(void);
};

#endif
