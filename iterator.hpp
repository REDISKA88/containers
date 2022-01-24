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



        ~rac_iterator_v(){};
    };


}
#endif
