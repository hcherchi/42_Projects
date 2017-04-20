# ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"
#include <iostream>

class Peon : public Victim
{
public:
  Peon(void);
  Peon(std::string _name);

  ~Peon(void);

  Peon(const Peon & src);
  Peon & operator = (const Peon & src);

  void getPolymorphed(void) const;
};

#endif
