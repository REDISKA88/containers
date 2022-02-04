#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>
namespace ft {
    template<typename T>

    class rac_iterator_v {
    public:
        typedef T       value_type;
        typedef T*      pointer;
        typedef T&      reference;
    protected:
        pointer         _p;

    public:
        rac_iterator_v(){};
        rac_iterator_v(pointer p): _p(p) {};
        rac_iterator_v(const rac_iterator_v&r) {
            *this = r;
        }
        // --------------------------------------------
        rac_iterator_v& operator=(const rac_iterator_v&r) {
            _p = r._p;
            return *this;
        }
        bool operator==(const rac_iterator_v&r) const {
            return _p == r._p;
        }
        bool operator!=(const rac_iterator_v&r) const {
            return _p != r._p;
        }
        bool operator<=(const rac_iterator_v&r) const {
            return _p <= r._p;
        }
        bool operator>=(const rac_iterator_v&r) const {
            return _p >= r._p;
        }
        bool operator<(const rac_iterator_v&r) const {
            return _p < r._p;
        }
        bool operator>(const rac_iterator_v&r) const {
            return _p > r._p;
        }
        // --------------------------------------------
        rac_iterator_v& operator++() {
            _p++;
            return *this;
        }

        rac_iterator_v operator++(int) {
            rac_iterator_v _tmp = *this;
            operator++();
            return _tmp;
        }

        rac_iterator_v& operator--() {
            _p--;
            return *this;
        }

        rac_iterator_v operator--(int) {
            rac_iterator_v _tmp = *this;
            operator--();
            return _tmp;
        }

        rac_iterator_v operator+(int _n) const{
            rac_iterator_v _tmp = *this;
            _tmp._p += _n;
            return _tmp;
        }

        rac_iterator_v operator-(int _n) const{
            rac_iterator_v _tmp = *this;
            _tmp._p -= _n;
            return _tmp;
        }

        rac_iterator_v& operator+=(int _n) {
            _p += _n;
            return *this;
        }

        rac_iterator_v& operator-=(int _n) {
            _p -= _n;
            return *this;
        }

        value_type& operator[](int _n) const {
            return *(*this + _n);
        }

        value_type& operator*() const {
            return *_p;
        }

        value_type* operator->() const {
            return _p;
        }

        virtual ~rac_iterator_v(){};
    };

    template<typename T>
    class const_rac_iterator_v : public rac_iterator_v<T> {
    public:
        typedef T       value_type;
        typedef T*      pointer;
        typedef T&      reference;

        const_rac_iterator_v() {};
        const_rac_iterator_v(pointer p) {
            this->_p = p;
        }
        const_rac_iterator_v(const const_rac_iterator_v &cr) {
                *this = cr;
        }
        // --------------------------------------------------------------
        const_rac_iterator_v& operator=(const const_rac_iterator_v &cr) {
            this->_p = cr._p;
            return *this;
        }
       const value_type& operator[](int _n) const {
            return *(*this + _n);
        }
        const value_type& operator*() const {
            return (*this->_p);
        }
        ~const_rac_iterator_v() {};
    };

    template<typename T>
    class reverse_iterator_v : public rac_iterator_v<T> {
    public:
        typedef T       value_type;
        typedef T*      pointer;
        typedef T&      reference;

        reverse_iterator_v(){};
        reverse_iterator_v(pointer p) {
            this->_p = p;
        }
        reverse_iterator_v(const reverse_iterator_v& rev) {
            *this = rev;
        }

        reverse_iterator_v& operator=(const reverse_iterator_v &rev) {
            if (this != &rev)
                this->_p = rev._p;
            return *this;
        }
        bool operator==(const reverse_iterator_v &rev) {
            return this->_p == rev._p;
        }
        bool operator!=(const reverse_iterator_v &rev) {
            return this->_p != rev._p;
        }

        // ---------------------------------------------
        reverse_iterator_v& operator++() {
            this->_p--;
            return *this;
        }
        reverse_iterator_v operator++(int) {
            reverse_iterator_v _tmp = *this;
            this->operator--();
            return _tmp;
        }

        reverse_iterator_v& operator--() {
            this->_p++;
            return *this;
        }
        reverse_iterator_v operator--(int) {
            reverse_iterator_v _tmp = *this;
            this->operator++();
            return _tmp;
        }

        reverse_iterator_v& operator+=(int _n) {
            this->_p -= _n;
            return *this;
        }

        reverse_iterator_v operator+(int _n) {
            reverse_iterator_v _tmp = *this;
            _tmp._p -= _n;
            return _tmp;
        }

        reverse_iterator_v& operator-=(int _n) {
            this->_p += _n;
            return *this;
        }

        reverse_iterator_v operator-(int _n) {
            reverse_iterator_v _tmp = *this;
            _tmp._p += _n;
            return _tmp;
        }

        reverse_iterator_v& operator[](int _n) {
            return *(*this - _n);
        }

        ~reverse_iterator_v() {};
    };

    template <typename T>
    class const_reverse_iterator_v : public reverse_iterator_v<T> {
    public:
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;

        const_reverse_iterator_v(){};
        const_reverse_iterator_v(pointer p) {
            this->_p = p;
        }
        const_reverse_iterator_v(const const_reverse_iterator_v&c_rev) {
            *this = c_rev;
        }
        const_reverse_iterator_v& operator=(const_reverse_iterator_v&c_rev) {
            if (this != c_rev)
                this->_p = c_rev._p;
            return *this;
        }
        const const_reverse_iterator_v& operator[](int _n) {
            return *(*this - _n);
        }
        ~const_reverse_iterator_v(){};
    };


    
}
#endif
