# ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include "Enemy.hpp"

class RadScorpion : public Enemy
{
  protected:
  public:
    RadScorpion(void);
    ~RadScorpion(void);
    RadScorpion(const RadScorpion & src);
    RadScorpion & operator = (const RadScorpion & src);
};

#endif
