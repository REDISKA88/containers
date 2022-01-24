#ifndef VECTOR_H
#include <iostream>
#include "iterator.hpp"
#include <iterator>
namespace ft {
    template <typename T, class Allocator = std::allocator<T> >
    class vector;
}
template <typename T, class Allocator>

class ft::vector {
public:
    typedef T                   value_type;
    typedef Allocator           allocator_type;
    typedef T&                  reference;
    typedef const T&            const_reference;
    typedef T*                  pointer;
    typedef const T*            const_pointer;
    typedef ft::rac_iterator_v<T>				iterator;




    typedef size_t  size_type;

private:
    size_t capacity;

public:




};

#endif // VECTOR_H
