# ifndef BONUS_HPP
# define BONUS_HPP

#include "Object.hpp"
#include "Header.hpp"

class Bonus : public Object {

  public:
    Bonus(void);
    ~Bonus(void);
    Bonus(const Bonus & src);
    Bonus & operator = (const Bonus & src);
};

#endif
