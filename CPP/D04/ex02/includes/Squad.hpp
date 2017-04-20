# ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"
#include "list.hpp"

class Squad : public ISquad
{
  protected:
    t_marine *_marines;

  public:
    Squad(void);
    ~Squad(void);
    Squad(const Squad & src);
    Squad & operator = (const Squad & src);

    int getCount() const;
    ISpaceMarine* getUnit(int) const;
    int push(ISpaceMarine*);
};

#endif
