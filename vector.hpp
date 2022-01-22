#ifndef VECTOR_H
#include <iostream>
namespace ft {
    template <typename T, class Allocator = std::allocator<T> >
    class vector;
}
template <typename T, class Allocator>

class ft::vector {
public:
    typedef T value_type;
    typedef Allocator allocator_type;
    typedef typename allocator_type::reference          reference;
    typedef typename allocator_type::const_reference    const_reference;
    typedef typename allocator_type::pointer            pointer;
    typedef typename allocator_type::const_pointer      const_pointer;





    typedef size_t  size_type;

private:
    size_t capacity;

public:




};

#endif // VECTOR_H
