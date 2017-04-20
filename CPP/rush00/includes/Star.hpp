# ifndef STAR_HPP
# define STAR_HPP

#include "Object.hpp"
#include "Header.hpp"

class Star : public Object {

  public:
    Star(void);
    ~Star(void);
    Star(const Star & src);
    Star & operator = (const Star & src);

    void takeDamage(int) {};
};

#endif
