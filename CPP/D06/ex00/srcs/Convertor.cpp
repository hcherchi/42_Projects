#include "Convertor.hpp"
#include <limits.h>
#include <cmath>
#include <float.h>

Convertor::Convertor(void) :
_type("none"),
_svalue("nan"),
_cvalue(0),
_ivalue(0),
_fvalue(0),
_dvalue(0)
{
  try
  {
    this->findType();
  }
  catch (const std::exception &e)
  {
    std::cout << "ERREUR : " << e.what() << std::endl;
  }
  return;
}

Convertor::Convertor(std::string svalue) :
_type("none"),
_svalue(svalue),
_cvalue(0),
_ivalue(0),
_fvalue(0),
_dvalue(0)
{
  try
  {
    this->findType();
  }
  catch (const std::exception &e)
  {
    std::cout << "ERREUR : " << e.what() << std::endl;
  }
  return;
}

Convertor::~Convertor(void)
{
  return;
}

Convertor::Convertor(Convertor const & src)
{
  *this = src;
  return;
}

Convertor & Convertor::operator=(Convertor const & src)
{
  this->_svalue = src._svalue;
  this->_ivalue = src._ivalue;
  this->_fvalue = src._fvalue;
  this->_dvalue = src._dvalue;
  this->_type = src._type;
  return *this;
}

void Convertor::findType(void)
{
  if (this->_svalue.length() == 1 && !isdigit(this->_svalue[0]))
  {
    this->_type = "char";
    this->_cvalue = this->_svalue[0];
  }
  else if (this->isInt())
  {
    this->_type = "int";
    this->_ivalue = std::stoi(this->_svalue);
  }
  else if (this->isFloat())
  {
    this->_type = "float";
    this->_fvalue = std::stof(this->_svalue);
  }
  else if (this->isDouble())
  {
    this->_type = "double";
    this->_dvalue = std::stod(this->_svalue);
  }
  else
    throw std::bad_typeid();
}

bool Convertor::isInt(void)
{
  int i = 0;

  while (this->_svalue[i])
  {
    if (!isdigit(this->_svalue[i]))
      return false;
    i++;
  }
  return true;
}

bool Convertor::isFloat(void)
{
  int i = 0;
  int dot = 0;

  if (this->_svalue == "nanf" || this->_svalue == "+inff" || this->_svalue == "-inff")
    return true;
  if (this->_svalue[0] == '-')
    i++;
  while (this->_svalue[i] && this->_svalue[i] != 'f')
  {
    if (this->_svalue[i] == '.')
      dot++;
    else if (!isdigit(this->_svalue[i]))
      return false;
    i++;
  }
  if (!this->_svalue[i] || dot != 1)
    return false;
  i++;
  if (this->_svalue[i])
    return false;
  return true;
}

bool Convertor::isDouble(void)
{
  int i = 0;
  int dot = 0;

  if (this->_svalue == "nan" || this->_svalue == "+inf" || this->_svalue == "-inf")
    return true;
  if (this->_svalue[0] == '-')
    i++;
  while (this->_svalue[i])
  {
    if (this->_svalue[i] == '.')
      dot++;
    else if (!isdigit(this->_svalue[i]))
      return false;
    i++;
  }
  if (dot != 1)
    return false;
  return true;
}

std::string Convertor::getType(void)
{
  return (this->_type);
}

void Convertor::printChar(void)
{
  std::cout << "char: ";
  if (this->_type == "float" && this->_fvalue < CHAR_MAX && this->_fvalue > CHAR_MIN)
  {
      if (isprint(this->_fvalue))
        std::cout << '\'' << static_cast<char>(this->_fvalue) << '\'';
      else
        std::cout << "Non displayable";
  }
  else if (this->_type == "int" && this->_ivalue < CHAR_MAX && this->_ivalue > CHAR_MIN)
  {
      if (isprint(this->_ivalue))
        std::cout << '\'' << static_cast<char>(this->_ivalue) << '\'';
      else
        std::cout << "Non displayable";
  }
  else if (this->_type == "double" && this->_dvalue < CHAR_MAX && this->_dvalue > CHAR_MIN)
  {
      if (isprint(this->_dvalue))
        std::cout << '\'' << static_cast<char>(this->_dvalue) << '\'';
      else
        std::cout << "Non displayable";
  }
  else if (this->_type == "char")
  {
    if (isprint(this->_cvalue))
      std::cout << '\'' << this->_cvalue << '\'';
    else
      std::cout << "Non displayable";
  }
  else
    std::cout << "impossible";
  std::cout << std::endl;
}

void Convertor::printInt(void)
{
  std::cout << "int: ";
  if (this->_type == "float" && this->_fvalue < INT_MAX && this->_fvalue > INT_MIN)
      std::cout << static_cast<int>(this->_fvalue);
  else if (this->_type == "int")
      std::cout << this->_ivalue;
  else if (this->_type == "double" && this->_dvalue < INT_MAX && this->_dvalue > INT_MIN)
      std::cout << static_cast<int>(this->_dvalue);
  else if (this->_type == "char")
      std::cout << static_cast<int>(this->_cvalue);
  else
    std::cout << "impossible";
  std::cout << std::endl;
}

void Convertor::printFloat(void)
{
  std::cout << "float: ";
  if (this->_type == "float")
      std::cout << this->_fvalue << (std::fmod(this->_fvalue, 1) == 0 ? ".0f" : "f");
  else if (this->_type == "int")
      std::cout << static_cast<float>(this->_ivalue) << ".0f";
  else if (this->_type == "double" && ((this->_dvalue < FLT_MAX && this->_dvalue > FLT_MIN) || std::isinf(this->_dvalue) || std::isnan(this->_dvalue)))
      std::cout << static_cast<float>(this->_dvalue) << (std::fmod(this->_dvalue, 1) == 0 ? ".0f" : "f");
  else if (this->_type == "char")
    std::cout << static_cast<float>(this->_cvalue) << ".0f";
  else
    std::cout << "impossible";
  std::cout << std::endl;
}

void Convertor::printDouble(void)
{
  std::cout << "double: ";
  if (this->_type == "float")
      std::cout << static_cast<double>(this->_fvalue) << (std::fmod(this->_fvalue, 1) == 0 ? ".0" : "");
  else if (this->_type == "int")
      std::cout << static_cast<double>(this->_ivalue) << ".0";
  else if (this->_type == "double")
      std::cout << this->_dvalue << (std::fmod(this->_dvalue, 1) == 0 ? ".0" : "");
  else if (this->_type == "char")
      std::cout << static_cast<double>(this->_cvalue) << ".0";
  else
    std::cout << "impossible";
  std::cout << std::endl;
}
