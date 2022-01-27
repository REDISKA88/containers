#ifndef VECTOR_H
#include <iostream>
#include <memory>
#include "iterator.hpp"
/*#include <vector>
std::vector<int> i;*/
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
    pointer                                             _v;
    size_type                                           _capacity;
    allocator_type                                      _allocator;
    size_type                                           _size;
public:

  /*  explicit vector(const allocator_type&_a = allocator_type())
        :_size(0), _capacity(0), _v(NULL), _allocator(_a){};*/
    //NULL pointer initialization
    explicit vector(const allocator_type&_a = allocator_type())
            :_size(0), _capacity(0), _allocator(_a) {
        _v = _allocator.allocate(_capacity);
    }; // with 0 size;
    explicit vector(size_type _s, const value_type&_value = value_type(), const allocator_type&_a = allocator_type())
        : _size(_s), _capacity(_s), _allocator(_a) {
        _v = _allocator.allocate(_s);
        for (size_type i = 0; i < _s; ++i)
            _allocator.construct(_v + i, _value);
    }
//-----------------------------------------------
    //template <typename _InputIterator>
    /*vector(_InputIterator _first, _InputIterator _last, const allocator_type&_a = allocator_type())
        :*/
    //ITERATORS
    iterator begin() {
        return iterator(_v);
    }
    const_iterator begin() const {
        return const_iterator(_v);
    }
    iterator end() {
        return iterator(_v + _size);
    }
    const_iterator end() const {
        return const_iterator(_v + _size);
    }
    reverse_iterator rbegin() {
        return reverse_iterator(_v + _size - 1);
    }
    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(_v + _size - 1);
    }
    reverse_iterator rend() {
        return reverse_iterator(_v - 1);
    }
    const_reverse_iterator rend() const {
        return const_reverse_iterator(_v - 1);
    }
    //----------------------------------------------------
    //METHODS
    void reserve(size_type s) {
        pointer new_pointer = _allocator.allocate(s);
        _capacity = s;
        for (size_type n = 0; n < _size; n++)
            new_pointer[n] = _v[n];
        _allocator.deallocate(_v, _capacity);
        _v = new_pointer;
    }

    void resize(size_type s, value_type vt = value_type()) {
        while (_size != s) {
            if (s > _size)
                push_back(vt);
            else if(s < _size)
                pop_back();
        }
    }
    bool empty() const {
        return _size == 0;
    }
    reference front() {
        return _v[0];
    }
   /* iterator insert(iterator _it, const value_type&_vt) {
        size_type   n = 0;
        iterator    start = begin();
        while (start + n != _it && n < _size)
            n++;

    }*/
   void push_back(const value_type& vt) {

   }

   void pop_back() {

   }
};

#endif // VECTOR_H
