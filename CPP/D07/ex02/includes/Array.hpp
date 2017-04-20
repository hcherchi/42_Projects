#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template<typename T>
class Array
{

  private:
    T *_array;
    unsigned int _len;

  public:
    Array(void) : _array(new T[0]), _len(0)
    {
      return;
    }

    Array(unsigned int n) : _array(new T[n]), _len(n)
    {
      for (unsigned int i = 0; i < this->_len; i++)
        this->_array[i] = 0;
      return;
    }

    Array(const Array & src)
    {
      *this = src;
      return;
    }

    Array & operator = (const Array & src)
    {
      delete [] this->_array;
      this->_len = src._len;
      this->_array = new T[this->_len];
      for (unsigned int i = 0; i < this->_len; i++)
        this->_array[i] = src._array[i];
      return *this;
    }

    T & operator [] (unsigned int n)
    {
      if (n >= this->_len)
        throw std::runtime_error("Trying to acces non allocated memory");
      return this->_array[n];
    }

    void *operator new[] (size_t n)
    {
      return new T[n];
    }

    ~Array(void)
    {
      delete [] this->_array;
      return;
    }

    unsigned int size(void) const
    {
      return this->_len;
    }
};

#endif
