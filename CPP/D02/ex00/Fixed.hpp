# ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
  private:
    int _fixedPointValue;
    static const int _nbBits;
  public:
    Fixed(void);
    ~Fixed(void);
    Fixed(const Fixed & src);
    Fixed & operator = (const Fixed & rhs);
    int getRawBits(void) const;
    void setRawBits(int const rawValue);
};

#endif
