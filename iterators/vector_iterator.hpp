#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP
#include "iterator_traits.hpp"
namespace ft {
    template <typename T>

    class vector_iterator {

    public:
        typedef T       value_type;
        typedef T*      pointer;
        typedef T&      reference;
        typedef std::ptrdiff_t                  difference_type;
        typedef std::random_access_iterator_tag iterator_category;

    protected:
        pointer         _p;

    public:

        vector_iterator() : _p(NULL) {}
        vector_iterator(pointer p) : _p(p) {}
        vector_iterator(vector_iterator const &V) : _p(V._p) {}
        virtual ~vector_iterator() {}

        //------------------------------------------------------------

        vector_iterator &operator++() {
            _p++;
            return *this;
        }

        vector_iterator operator++(int) {
            vector_iterator tmp = *this;
            operator++();
            return tmp;
        }

        vector_iterator &operator--() {
            _p--;
            return *this;
        }

        vector_iterator operator--(int) {
            vector_iterator tmp = *this;
            operator--();
            return tmp;
        }

        value_type &operator[](int idx) {
            return *(this->_p + idx);
        }

        value_type *operator->()
        {
            return (this->_p);
        }

        value_type &operator*() {
            return *this->_p;
        }

        vector_iterator operator+(difference_type _n) const {
            vector_iterator tmp = *this;
            tmp._p += _n;
            return tmp;
        }

        vector_iterator<T> operator-(difference_type _n) const {
            vector_iterator tmp = *this;
            tmp._p -= _n;
            return tmp;
        }

        difference_type operator+(const vector_iterator &r) const {
            difference_type tmp = _p + r._p;
            return tmp;
        }

        difference_type operator-(const vector_iterator &r) const {
            difference_type tmp = _p - r._p;
            return tmp;
        }

        vector_iterator<T> &operator+=(difference_type _n) {
            _p += _n;
            return *this;
        }

        vector_iterator<T> &operator-=(difference_type _n) {
            _p -= _n;
            return *this;
        }

        operator vector_iterator<value_type const>() const {
            return vector_iterator<value_type const>(_p);
        }

        vector_iterator &operator=(const vector_iterator &r) {
            if (this != &r)
                this->_p = r._p;
            return (*this);
        }

        bool operator==(const vector_iterator &r) const {
            return _p == r._p;
        }

        bool operator!=(const vector_iterator &r) const {
            return _p != r._p;
        }

        bool operator<=(const vector_iterator &r) const {
            return _p <= r._p;
        }

        bool operator>=(const vector_iterator &r) const {
            return _p >= r._p;
        }

        bool operator>(const vector_iterator &r) const {
            return _p > r._p;
        }
        bool operator<(const vector_iterator &r) const {
            return _p < r._p;
        }

        bool operator!=(const vector_iterator &r) {
            return _p != r._p;
        }

        value_type *base(void) const {
            return (this->_p);
        }

    };

    template <typename Iterator>
    vector_iterator<Iterator> operator+(typename vector_iterator<Iterator>::difference_type _n,
            const vector_iterator<Iterator> &v_it) {
        return vector_iterator<Iterator>(v_it.base() + _n);
    }

    template <typename Iterator>
    vector_iterator<Iterator> operator-(typename vector_iterator<Iterator>::difference_type _n,
            const vector_iterator<Iterator> &v_it) {
        return vector_iterator<Iterator>(v_it.base() - _n);
    }

    template <typename Iterator, typename Iterator2>
    bool operator==(const vector_iterator<Iterator> &v_it,
            const vector_iterator<Iterator2> &v_it2) {
        return v_it.base() == v_it2.base();
    }

    template <typename Iterator, typename Iterator2>
    bool operator!=(const vector_iterator<Iterator> &v_it,
            const vector_iterator<Iterator2> &v_it2) {
        return v_it.base() != v_it2.base();
    }

    template <typename Iterator, typename Iterator2>
    bool operator<(const vector_iterator<Iterator> &v_it,
            const vector_iterator<Iterator2> &v_it2) {
        return v_it.base() < v_it2.base();
    }

    template <typename Iterator, typename Iterator2>
    bool operator<=(const vector_iterator<Iterator> &v_it,
            const vector_iterator<Iterator2> &v_it2) {
        return v_it.base() <= v_it2.base();
    }

    template <typename Iterator, typename Iterator2>
    bool operator>(const vector_iterator<Iterator> &v_it,
                   const vector_iterator<Iterator2> &v_it2) {
        return v_it.base() > v_it2.base();
    }

    template <typename Iterator, typename Iterator2>
    bool operator>=(const vector_iterator<Iterator> &v_it,
            const vector_iterator<Iterator2> &v_it2) {
        return v_it.base() >= v_it2.base();
    }
}
#endif
