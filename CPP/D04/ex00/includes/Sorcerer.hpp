# ifndef SORCERER_HPP
# define SORCERER_HPP

#include <iostream>
#include "Victim.hpp"

class Sorcerer
{
  protected:
    std::string _name;
    std::string _title;
  public:
    Sorcerer(void);
    Sorcerer(std::string _name, std::string _title);

    ~Sorcerer(void);

    Sorcerer(const Sorcerer & src);
    Sorcerer & operator = (const Sorcerer & src);

    std::string getName(void) const;
    std::string getTitle(void) const;
    void polymorph(Victim const & victim) const;
};

std::ostream & operator << (std::ostream &os, Sorcerer & src);

#endif
