# ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
  protected:
  public:
    AssaultTerminator(void);
    ~AssaultTerminator(void);
    AssaultTerminator(const AssaultTerminator & src);
    AssaultTerminator & operator = (const AssaultTerminator & src);

    AssaultTerminator* clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
};

#endif
