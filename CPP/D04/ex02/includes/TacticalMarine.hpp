# ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
  protected:
  public:
    TacticalMarine(void);
    ~TacticalMarine(void);
    TacticalMarine(const TacticalMarine & src);
    TacticalMarine & operator = (const TacticalMarine & src);

    TacticalMarine* clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
};

#endif
