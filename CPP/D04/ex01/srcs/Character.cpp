#include "Character.hpp"

Character::Character(void) :
_name("Anonymous"),
_ap(40),
_weapon(NULL)
{
  return;
}

Character::Character(std::string const & name) :
_name(name),
_ap(40)
{
  return;
}


Character::~Character(void)
{
  return;
}

Character::Character(Character const & src)
{
  *this = src;
  return;
}

Character & Character::operator=(Character const & src)
{
  if (this != &src)
  {
    this->_name = src._name;
    this->_ap = src._ap;
    this->_weapon = src._weapon;
  }
  return *this;
}

std::string Character::getName(void) const
{
  return this->_name;
}

int Character::getAp(void) const
{
  return this->_ap;
}

AWeapon *Character::getWeapon(void) const
{
  return this->_weapon;
}

void Character::recoverAP(void)
{
  int amount = 10;

  if (this->_ap + amount >= 40)
  {
    amount -= this->_ap + amount - 40;
    std::cout << this->_name << " recover " << amount << " AP. He's now full." << std::endl;
    this->_ap += amount;
  }
  else
  {
    std::cout << this->_name << " recover " << amount << " AP." << std::endl;
    this->_ap += amount;
  }
}

void Character::equip(AWeapon* weapon)
{
  this->_weapon = weapon;
}

void Character::attack(Enemy* enemy)
{
  if (this->_weapon)
  {
    if (this->_ap >= this->_weapon->getApcost())
    {
      std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName()  << std::endl;
      this->_weapon->attack();
      if (enemy->getHp() <= this->_weapon->getDamage())
      {
        enemy->takeDamage(0);
        delete(enemy);
      }
      else
        enemy->takeDamage(this->_weapon->getDamage());
      this->_ap -= this->_weapon->getApcost();
    }
  }
}

std::ostream & operator<<(std::ostream &os, Character &src)
{
  if (src.getWeapon())
    os << src.getName() << " has " << src.getAp() << " AP and wields a " << src.getWeapon()->getName() << std::endl;
  else
    os << src.getName() << " has " << src.getAp() << " AP and is unarmed" << std::endl;
  return os;
}
