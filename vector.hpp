#ifndef VECTOR_H
//#include <iostream>
#include <memory>
#include "iterator.hpp"

namespace ft {
    template <typename T, class Allocator = std::allocator<T> >
    class vector;
}
template <typename T, class Allocator>

class ft::vector {
public:
    typedef T                                           value_type;
    typedef size_t                                      size_type;
    typedef Allocator                                   allocator_type;
    typedef T&                                          reference;
    typedef const T&                                    const_reference;
    typedef T*                                          pointer;
    typedef const T*                                    const_pointer;
    typedef ft::rac_iterator_v<T>				        iterator;
    typedef  ft::const_rac_iterator_v<T>                const_iterator;
    typedef ft::reverse_iterator_v<T>                   reverse_iterator;
    typedef  ft::const_reverse_iterator_v<T>            const_reverse_iterator;






private:
    size_t capacity;

public:




};

#endif // VECTOR_H
