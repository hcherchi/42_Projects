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

    Fixed & operator ++ (void);
    Fixed & operator -- (void);
    Fixed operator ++ (int);
    Fixed operator -- (int);

    bool            operator>(Fixed const& lhs) const;
    bool            operator<(Fixed const& lhs) const;
    bool            operator>=(Fixed const& lhs) const;
    bool            operator<=(Fixed const& lhs) const;
    bool            operator==(Fixed const& lhs) const;
    bool            operator!=(Fixed const& lhs) const;

    Fixed            operator+(Fixed lhs);
    Fixed            operator-(Fixed lhs);
    Fixed            operator*(Fixed lhs);
    Fixed            operator/(Fixed lhs);

    static Fixed    &min(Fixed &lhs, Fixed &rhs);
    static Fixed    const&min(Fixed const& lhs, Fixed const& rhs);
    static Fixed    &max(Fixed &lhs, Fixed &rhs);
    static Fixed    const&max(Fixed const& lhs, Fixed const& rhs);

    int getRawBits(void) const;
    void setRawBits(int const rawValue);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream & operator << (std::ostream & os, Fixed const & rhs);

#endif
