#ifndef VECTOR_H
#include <iostream>
#include <memory>
#include <stdexcept>

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
        if (s > _capacity)

        while (_size != s) {
            if (s > _size)
                push_back(vt);
            else if(s < _size)
                pop_back();
        }
    }

    //simple
    size_type capacity() {
        return _capacity;
    }
    bool empty() const {
        return _size == 0;
    }
    reference front() {
        return _v[0];
    }
    const_reference front() const {
        return _v[0];
    }
    reference back() {
        return _v[_size - 1];
    }
    const_reference back() const {
        return _v[_size - 1];
    }
    void clear() {
        while (_size > 0)
            pop_back();
    }

   /* iterator insert(iterator _it, const value_type&_vt) {
        size_type   n = 0;
        iterator    start = begin();
        while (start + n != _it && n < _size)
            n++;

    }*/
   void push_back(const value_type& vt) {
        if (_capacity == _size) {
            size_type _st;
            if (_size == 0)
                _st = 1;
            else
                _st = _capacity * 2;
            pointer _v_reallocate;
            _v_reallocate = _allocator.allocate(_st);
            for (size_type i = 0; i < _st; i++)
                _allocator.construct(&_v_reallocate[i], _v[i]);
            ~vector();
            _v = _v_reallocate;
            _capacity = _st;
        }
        _allocator.construct(&_v[_size++],vt);
   }

   void pop_back() {
       _allocator.destroy(&_v[--this->_size]);
   }

   reference at(size_type index) {
       if (index >= _size)
           throw std::out_of_range("out of range");
       else
           return _v[index];
   }
   const_reference at(size_type index) const {
       if (index >= _size)
           throw std::out_of_range("out of range");
       else
           return _v[index];
   }

   reference operator[](size_type index) {
       return _v[index];
   };

   const_reference operator[](size_type index) const {
       return _v[index];
   }

   ~vector() {
       for (size_type i = 0; i < _size; i++)
           _allocator.destroy(&_v[i]);
       _allocator.deallocate(_v, _capacity);
   }
};

#endif // VECTOR_H
