#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0)
{
  std::cout << "Default constructor called" << std::endl;
  return;
}

Fixed::Fixed(int value)
{
  std::cout << "Int constructor called" << std::endl;
  this->_fixedPointValue = value << this->_pointPos;
  return;
}

Fixed::Fixed(float value)
{
  std::cout << "Float constructor called" << std::endl;
  this->_fixedPointValue = (int)(roundf(value * (1 << Fixed::_pointPos)));
  return;
}

Fixed::~Fixed(void)
{
  std::cout << "Destructor called" << std::endl;
  return;
}

Fixed::Fixed(Fixed const & src)
{
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
  std::cout << "Assignation operator called" << std::endl;
  if (this != &rhs)
  {
    this->_fixedPointValue = rhs.getRawBits();
  }
  return *this;
}

std::ostream & operator<<(std::ostream & os, Fixed const & rhs)
{
  os << rhs.toFloat();
  return os;
}

int Fixed::getRawBits(void) const
{
  return this->_fixedPointValue;
}


void Fixed::setRawBits(int const raw)
{
  this->_fixedPointValue = raw;
}

int Fixed::toInt(void) const
{
  return (this->_fixedPointValue >> this->_pointPos);
}

float Fixed::toFloat(void) const
{
  return (float)(this->_fixedPointValue) / (1 << Fixed::_pointPos);
}

const int Fixed::_pointPos = 8;
