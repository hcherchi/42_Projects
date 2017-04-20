# ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
  private:
    int _fixedPointValue;
    static const int _pointPos;
  public:
    Fixed(void);
    Fixed(const Fixed & src);
    Fixed(int const);
    Fixed(float const);
    ~Fixed(void);
    Fixed & operator = (const Fixed & rhs);
    int getRawBits(void) const;
    void setRawBits(int const rawValue);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream & operator << (std::ostream & os, Fixed const & rhs);

#endif
