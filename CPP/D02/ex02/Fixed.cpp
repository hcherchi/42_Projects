#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0)
{
  return;
}

Fixed::Fixed(int value)
{
  this->_fixedPointValue = value << this->_pointPos;
  return;
}

Fixed::Fixed(float value)
{
  this->_fixedPointValue = (int)(roundf(value * (1 << Fixed::_pointPos)));
  return;
}

Fixed::~Fixed(void)
{
  return;
}

Fixed::Fixed(Fixed const & src)
{
  *this = src;
  return;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
  if (this != &rhs)
  {
    this->_fixedPointValue = rhs.getRawBits();
  }
  return *this;
}

Fixed & Fixed::operator++()
{
  this->_fixedPointValue++;
  return *this;
}

Fixed & Fixed::operator--()
{
  this->_fixedPointValue--;
  return *this;
}

Fixed Fixed::operator++(int)
{
  Fixed old(*this);
  this->_fixedPointValue++;
  return old;
}

Fixed Fixed::operator--(int)
{
  Fixed old(*this);
  this->_fixedPointValue--;
  return old;
}

bool    Fixed::operator>(Fixed const & rhs) const
{
    return (this->_fixedPointValue > rhs._fixedPointValue);
}

bool    Fixed::operator<(Fixed const & rhs) const
{
    return (this->_fixedPointValue < rhs._fixedPointValue);
}

bool    Fixed::operator>=(Fixed const & rhs) const
{
    return (this->_fixedPointValue >= rhs._fixedPointValue);
}


bool    Fixed::operator<=(Fixed const & rhs) const
{
    return (this->_fixedPointValue <= rhs._fixedPointValue);
}

bool    Fixed::operator==(Fixed const & rhs) const
{
    return (this->_fixedPointValue == rhs._fixedPointValue);
}

bool    Fixed::operator!=(Fixed const & rhs) const
{
    return (this->_fixedPointValue != rhs._fixedPointValue);
}

Fixed    Fixed::operator+(Fixed rhs)
{
    Fixed    fixed;

    fixed.setRawBits(this->_fixedPointValue + rhs._fixedPointValue);
    return (fixed);
}

Fixed    Fixed::operator-(Fixed rhs)
{
    Fixed    fixed;

    fixed.setRawBits(this->_fixedPointValue - rhs._fixedPointValue);
    return (fixed);
}

Fixed    Fixed::operator*(Fixed rhs)
{
    Fixed    fixed;
    int        res;

    res = this->_fixedPointValue * rhs._fixedPointValue;
    res += 1 << (Fixed::_pointPos - 1);
    res >>= Fixed::_pointPos;

    fixed.setRawBits(res);
    return (fixed);
}

Fixed    Fixed::operator/(Fixed rhs)
{
    Fixed    fixed;
    int        res;

    res = this->_fixedPointValue << Fixed::_pointPos;
    res += rhs._fixedPointValue / 2;
    res /= rhs._fixedPointValue;

    fixed.setRawBits(res);
    return (fixed);
}

Fixed    &Fixed::min(Fixed &lhs, Fixed &rhs)
{
    if (lhs < rhs)
        return (lhs);
    else
        return (rhs);
}

Fixed    const&Fixed::min(Fixed const&lhs, Fixed const&rhs)
{
    if (lhs < rhs)
        return (lhs);
    else
        return (rhs);
}

Fixed    &Fixed::max(Fixed &lhs, Fixed &rhs)
{
    if (lhs > rhs)
        return (lhs);
    else
        return (rhs);
}

Fixed    const&Fixed::max(Fixed const&lhs, Fixed const&rhs)
{
    if (lhs > rhs)
        return (lhs);
    else
        return (rhs);
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
