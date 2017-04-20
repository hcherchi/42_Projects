# ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
  protected:
    std::string _name;
    int _ap;
    AWeapon *_weapon;
  public:
    Character(void);
    Character(std::string const & name);
    ~Character(void);
    Character(const Character & src);
    Character & operator = (const Character & src);

    std::string getName(void) const;
    AWeapon *getWeapon(void) const;
    int getAp(void) const;

    void recoverAP();
    void equip(AWeapon*);
    void attack(Enemy*);
};

std::ostream & operator << (std::ostream &os, Character & src);

#endif
