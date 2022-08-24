// Array.h
// Array class definition with overloaded operators.
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
template <class T> class Array{
  template <class U> friend std::ostream &operator<<( std::ostream &, const Array<U> & );
  template <class U> friend std::istream &operator>>( std::istream &, Array<U> & );

  public:
    explicit Array( int = 10 ); // default constructor
    size_t getSize() const; // return size
    Array( const Array & ); // copy constructor
    ~Array(); // destructor
    const Array &operator=( const Array & ); // assignment operator
    bool operator==( const Array & ) const; // equality operator
    // inequality operator; returns opposite of == operator
    bool operator!=( const Array &right ) const{
      return ! ( *this == right ); // invokes Array::operator==
    } // end function operator!=
    // subscript operator for non-const objects returns modifiable lvalue
    T &operator[]( int );
    // subscript operator for const objects returns rvalue
    T operator[]( int ) const;

    size_t size; // pointer-based array size
  private:
    T *ptr; // pointer to first element of pointer-based array
}; // end class Array
#endif
