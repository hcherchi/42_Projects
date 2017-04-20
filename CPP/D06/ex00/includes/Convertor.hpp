# ifndef CONVERTOR_HPP
# define CONVERTOR_HPP

#include "Convertor.hpp"
#include <iostream>

class Convertor
{
  protected:
    std::string _type;
    std::string _svalue;
    char _cvalue;
    int _ivalue;
    float _fvalue;
    double _dvalue;

  public:
    Convertor(void);
    Convertor(std::string input);
    ~Convertor(void);
    Convertor(const Convertor & src);
    Convertor & operator = (const Convertor & src);

    void findType(void);
    bool isInt(void);
    bool isFloat(void);
    bool isDouble(void);

    void printChar(void);
    void printInt(void);
    void printFloat(void);
    void printDouble(void);

    std::string getType(void);
};

#endif
