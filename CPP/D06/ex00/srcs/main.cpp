#include "Convertor.hpp"

int main(void)
{
  Convertor *convertor;
  std::string input;

  std::cout << "Enter a value: ";
  std::getline(std::cin, input, '\n');
  convertor = new Convertor(input);
  convertor->printChar();
  convertor->printInt();
  convertor->printFloat();
  convertor->printDouble();
  return (0);
}
