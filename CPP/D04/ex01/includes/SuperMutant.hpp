# ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy
{
  protected:
  public:
    SuperMutant(void);
    ~SuperMutant(void);
    SuperMutant(const SuperMutant & src);
    SuperMutant & operator = (const SuperMutant & src);

    void takeDamage(int damages);
};

#endif
