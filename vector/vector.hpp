#pragma once
#include <memory>
#include <iostream>
#include <string>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "lexicographical.hpp"
#include "../iterators/vector_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
struct enable_if;
class vector_iterator;

namespace ft {
    template <typename T, class Allocator = std::allocator<T> > class vector {
    public:
        typedef T                                       value_type;
        typedef std::size_t                             size_type;
        typedef long int                                diff_type;
        typedef Allocator                               allocator_type;
        typedef T&                                      reference;
        typedef const T&                                const_reference;
        typedef T*                                      pointer;
        typedef const T*                                const_pointer;
        typedef ft::vector_iterator<value_type>         iterator;
        typedef ft::vector_iterator<value_type const>   const_iterator;
        typedef ft::reverse_iterator<iterator>          reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;

    private:
        pointer             _v;
        size_type           _size;
        size_type           _capacity;
        allocator_type      _allocator;

    public:
        vector(const allocator_type &_alloc_ = allocator_type())
            : _size(0), _capacity(0), _allocator(_alloc_), _v(NULL) {};
        vector(size_type _s, const value_type &_vt = value_type(), const allocator_type &_alloc_ = allocator_type())
            : _size(_s), _capacity(_s), _allocator(_alloc_), _v(NULL) {
            size_t i = 0;
            this->_v = _allocator.allocate(_s);
            while (i < _s) {
                _allocator.construct(&_v[i], _vt);
                i++;
            }
        }

        template<class InputIterator>
        vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
               InputIterator last, const allocator_type &_alloc_ = allocator_type())
                : _size(0), _capacity(0), _allocator(_alloc_), _v(NULL) {
        InputIterator _it(first);
            while (_it++ != last)
                this->_size++;
            this->_capacity = this->_size;
            _v = _allocator.allocate(_size);
            for (size_t i = 0; first != last; ++first, ++i)
                _allocator.construct(_v[i], *first);
        }
        vector(const vector &V)
            : _size(V._size), _capacity(V._capacity), _allocator(V._allocator), _v(NULL) {
            size_type i = 0;
            _v = _allocator.allocate(this->_capacity);
            while (i < _size) {
                _allocator.construct(&_v[i], V._v[i]);
                i++;
            }
        }
        ~vector() {
            size_type i = 0;
            size_type _s = _size;
            while (i < _s) {
                _allocator.destroy(&_v[i]);
                i++;
            }
            _allocator.deallocate(_v, _capacity);
        }


        //simple

    };

}