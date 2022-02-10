#pragma once

#include <memory>
#include <iostream>
#include <string>
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "lexicographical.hpp"
#include "../iterators/vector_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"

namespace ft {
	template <typename T, typename Allocator = std::allocator<T> >
	class vector {
	public:

		typedef T                                                           value_type;
        typedef size_t                                                      size_type;
		typedef Allocator                                                   allocator_type;
        typedef T&                                                          reference;
        typedef const T&                                                    const_reference;
        typedef T*                                                          pointer;
		typedef long int                                                    diff_type;
        typedef ft::vector_iterator<value_type>                             iterator;
		typedef ft::vector_iterator<value_type const>                       const_iterator;
		typedef ft::reverse_iterator<iterator>                              reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>                        const_reverse_iterator;

	private:

		size_type _size;
		size_type _capacity;
		allocator_type _allocator;
		pointer _v;

	public:

        explicit vector(const allocator_type &alloc = allocator_type())
            : _size(0), _capacity(0), _allocator(alloc), _v(NULL) {}

        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
            : _size(n), _capacity(n), _allocator(alloc), _v(NULL) {
            _v = _allocator.allocate(n);
            for(size_t i = 0; i < n; i++)
                _allocator.construct(&_v[i], val);
        }

        template <class InputIterator>
        vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value,
               InputIterator>::type first, InputIterator last, const allocator_type &alloc = allocator_type())
                : _size(0), _capacity(0), _allocator(alloc), _v(NULL) {
            InputIterator tmp(first);
            while (tmp++ != last)
                this->_size++;
            this->_capacity = this->size();
            this->_v = _allocator.allocate(this->size());
            for (int i = 0; first != last; ++first, ++i)
                _allocator.construct(&this->_v[i], *first);
        }
        ~vector() {
            for(size_type i = 0; i < this->size(); i++)
                this->_allocator.destroy(&_v[i]);
            this->_allocator.deallocate(this->_v, this->_capacity);
        }

        vector(const vector &V)
            : _size(V._size), _capacity(V._capacity), _allocator(V._allocator), _v(NULL) {
            this->_v = _allocator.allocate(this->_capacity);
            for(size_type i = 0; i < this->size(); i++)
                _allocator.construct(&_v[i], V._v[i]);
        }
        //////////////////////////////////////////////////
        vector& operator=(const vector&V) {
            if (this != &V)
                assign(V.begin(), V.end());
            return *this;
        }

        reference operator[](size_type idx) {
            return _v[idx];
        }

        const_reference operator[](size_type idx) const {
            return _v[idx];
        }

        reference at(size_type idx) {
            if (idx >= size())
                throw std::out_of_range("out of range");
            return _v[idx];
        }

        const_reference at(size_type idx) const {
            if (idx >= size())
                throw std::out_of_range("out of range");
            return _v[idx];
        }

        //simple
        size_type capacity() const {
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
        size_type size() const {
            return _size;
        }
        size_type max_size() const {
            size_type ms;
            ms = _allocator.max_size();
            return ms;
        }
        void clear() {
            this->_size = 0;
        }

		allocator_type get_allocator() const {
			return _allocator;
		}

        void swap(vector &sw) {
            pointer t_v;
            size_type t_capacity;
            size_type t_size;
            allocator_type t_allocator;

            t_v = _v;
            t_size = _size;
            t_allocator = _allocator;
            t_capacity = _capacity;

            _v = sw._v;
            _size = sw._size;
            _allocator = sw._allocator;
            _capacity = sw._capacity;
            sw._allocator = t_allocator;
            sw._v = t_v;
            sw._size = t_size;
            sw._capacity = t_capacity;
        }

        //iterators
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
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(end());
		}

		reverse_iterator rend() {
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(begin());
		}

        //--------------------------------------------


		void reserve(size_type _s) {
			if (_s > capacity()) {
                pointer new_v = this->_allocator.allocate(_s);
                for (size_type i = 0; i < this->size(); i++) {
                    this->_allocator.construct(&new_v[i], this->_v[i]);
                    this->_allocator.destroy(&_v[i]);
                }
				this->_allocator.deallocate(this->_v, this->_capacity);
                this->_v = new_v;
                this->_capacity = _s;
			}
		}

		void resize(size_type _s, value_type _vt = value_type()) {
			if (_s > capacity()) {
				if (_s < capacity() * 2)
					reserve(capacity() * 2);
				else
					reserve(_s);
			}
            for (size_type i = size(); i < _s; i++)
                this->_allocator.construct(&_v[i], _vt);
            for(size_type i = _s; i < size(); i++)
                _allocator.destroy(&_v[i]);
            this->_size = _s;
		}

        void push_back(const value_type &val) {
            if (size() == capacity())
            {
                if (capacity() == 0)
                    this->reserve(1);
                else
                    this->reserve(capacity() * 2);
            }
            this->_allocator.construct(&_v[size()], val);
            this->_size++;
        }
        void pop_back() {
            _allocator.destroy(&_v[--this->_size]);
        }

        void assign(size_type n, const value_type& val) {
            for (size_t i = 0; i < _size; i++)
                _allocator.destroy(&_v[i]);
            _size = 0;
            if (n > _capacity)
                _capacity = n;
            for (size_type i = 0; i < _size; i++)
                _allocator.destroy(_v + i);
            _allocator.deallocate(_v, _size);
            _v = _allocator.allocate(_capacity);
            for (size_t i = 0; i < _size; i++)
                _allocator.construct(_v + i, val);
            _size = n;
        }

		template <class InputIterator>
		void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                    InputIterator>::type first, InputIterator last) {
            size_type i = 0;
            size_type _ns = 0;
            for(InputIterator it = first; it < last; it++)
                _ns++;
			reserve(_ns);
			resize(_ns);
            for (size_type j = 0; j < _ns && j < size(); j++)
                this->_allocator.destroy(&_v[j]);
            for(InputIterator it = first; it < last; it++) {
                _allocator.construct(&_v[i], *it); i++;
            }
			if (_ns > this->size())
                this->_size = _ns;
		}

		iterator erase(iterator first, iterator last) {
            size_type _start = 0;
            size_type _end = 0;
            size_type _range = 0;

            if (first == this->end() || first == last)
				return first;
            for(iterator it = this->begin(); it < first; it++)
                _start++;
            for(iterator it = last; it < this->end(); it++)
                _end++;
            for(iterator it = first; it < last; it++)
                _range++;
            size_type i = 0;
			for (; i < _end; i++) {
                _allocator.destroy(&_v[_start + i]);
                _allocator.construct(&_v[_start + i], _v[_start + i + _range]);
            }
            for (; i < _range; i++)
                _allocator.destroy(&_v[_start + _range + i]);
			this->_size -= _range;
			return (first);
		}

        iterator erase(iterator position) {
            return erase(position, position + 1);
        }

		iterator insert(iterator position, const value_type &_vt)
		{
            diff_type _d = position.get_ptr() - _v;
			insert(position, 1, _vt);
			return iterator(begin() + _d);
		}

        void insert(iterator it, size_type n, const value_type&_vt) {
            vector t_v(it, this->end());
            iterator t_it = t_v.begin();
            while (this->end() != it) {
                pop_back();
            }
            for (size_t i = n; i > 0; --i) {
                push_back(_vt);
            }
            while (t_it != t_v.end()) {
                push_back(*t_it);
                ++t_it;
            }
        }

		template <class InputIterator>
		void insert(iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                    InputIterator>::type first, InputIterator last) {
			size_type _s = 0;
			size_type _start = 0;
			size_type _end = 0;

            for(InputIterator it = first; it < last; it++)
                _s++;
            iterator it = this->begin();
            for(; it < position; it++)
                _start++;
            for(;it < this->end(); it++)
                _end++;
			if (this->_size + _s > this->_capacity) {
				if (this->_size + _s < this->_capacity * 2)
					reserve(this->_capacity * 2);
				else
					reserve(this->_size + _s);
			}
            for(size_type i = 0; i < _end; i++) {
                _allocator.construct(&_v[_start + _s + _end - i - 1], _v[_start + _end - i - 1]);
                _allocator.destroy(&_v[_start + _end - i - 1]);
            }
            InputIterator Init = first;
            for(size_type i = 0; i < _s; i++) {
                _allocator.construct(&_v[_start + i], *Init); Init++;
            }
            this->_size = (this->size() + _s);
		}
	};

    template <typename T, typename Allocator>
    bool operator!=(const vector<T, Allocator> &x, const vector<T, Allocator> &y) {
        return (!(x == y));
    }

    template <typename T, typename Allocator>
    bool operator==(const vector<T, Allocator> &x, const vector<T, Allocator> &y) {
        size_t i = 0;
        if (x.size() != y.size())
            return false;
        while (i < x.size()) {
            if (x[i] != y[i])
                return false;
            i++;
        }
        return true;
    }

    template <class T, class Allocator>
    bool operator>=(const vector<T, Allocator> &x, const vector<T, Allocator> &y) {
        return ((x > y) || (x == y));
    }

    template <class T, class Allocator>
    bool operator<=(const vector<T, Allocator> &x, const vector<T, Allocator> &y) {
        return ((x < y) || (x == y));
    }

    template <class T, class Allocator>
    bool operator>(const vector<T, Allocator> &x, const vector<T, Allocator> &y) {
        return y < x;
    }

	template <typename T, typename Allocator>
	bool operator<(const vector<T, Allocator> &x, const vector<T, Allocator> &y) {
		return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));
	}

    template <typename T, typename Allocator>
    void swap(vector<T, Allocator> &X, vector<T, Allocator> &Y) {
        X.swap(Y);
    }

}