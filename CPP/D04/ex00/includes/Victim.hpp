# ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class Victim
{
  protected:
    std::string _name;
  public:
    Victim(void);
    Victim(std::string _name);

    ~Victim(void);

    Victim(const Victim & src);
    Victim & operator = (const Victim & src);

    std::string getName(void) const;
    virtual void getPolymorphed(void) const;
};

std::ostream & operator << (std::ostream &os, Victim & src);

#endif
