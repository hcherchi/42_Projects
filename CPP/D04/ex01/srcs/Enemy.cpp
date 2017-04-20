#include "Enemy.hpp"

Enemy::Enemy(void) :
_hp(10),
_type("lol")
{
  return;
}

Enemy::Enemy(int hp, std::string const & type) :
_hp(hp),
_type(type)
{
  return;
}


Enemy::~Enemy(void)
{
  return;
}

Enemy::Enemy(Enemy const & src)
{
  *this = src;
  return;
}

Enemy & Enemy::operator=(Enemy const & src)
{
  if (this != &src)
  {
    this->_type = src._type;
    this->_hp = src._hp;
  }
  return *this;
}

std::string const & Enemy::getType(void) const
{
  return this->_type;
}

int Enemy::getHp(void) const
{
  return this->_hp;
}

void Enemy::takeDamage(int damages)
{
  if (damages >= 0)
    this->_hp -= damages;
}
