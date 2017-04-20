# ifndef HEAL_HPP
# define HEAL_HPP

#include "Object.hpp"
#include "Header.hpp"

class Heal : public Object {

  public:
    Heal(void);
    ~Heal(void);
    Heal(const Heal & src);
    Heal & operator = (const Heal & src);
};

#endif
