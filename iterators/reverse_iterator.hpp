#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include "iterator_traits.hpp"
namespace ft {
    template <class Iterator>
    class reverse_iterator {
    public:
        typedef Iterator                                                        iterator_type;
        typedef typename iterator_traits<iterator_type>::value_type             value_type;
        typedef typename iterator_traits<iterator_type>::pointer                pointer_type;
        typedef typename iterator_traits<iterator_type>::reference              reference_type;
        typedef typename iterator_traits<iterator_type>::difference_type        difference_type;

    protected:
        iterator_type _p;

    public:
        reverse_iterator() : _p(NULL) {}
        reverse_iterator(iterator_type p) : _p(p) {}
        template <typename _Iterator>
        reverse_iterator(const reverse_iterator<_Iterator> &rev) : _p(rev.base()) {}
        virtual ~reverse_iterator() {}

        //--------------------------------------------------------
        reverse_iterator& operator=(reverse_iterator const &rev) {
            if (this != &rev)
                this->_p = rev._p;
            return *this;
        }

        bool operator==(const reverse_iterator& rev) const {
            return this->_p == rev._p;
        }

        bool operator!=(const reverse_iterator& rev) const {
            return this->_p != rev._p;
        }
        //-------------------------------------------------------
        reverse_iterator& operator++() {
            this->_p--;
            return *this;
        }

        reverse_iterator operator++(int) {
            reverse_iterator tmp = *this;
            this->_p--;
            return tmp;
        }

        reverse_iterator& operator--(){
            this->_p++;
            return *this;
        }

        reverse_iterator operator--(int) {
            reverse_iterator tmp = *this;
            this->_p++;
            return tmp;
        }

        bool operator>(const reverse_iterator &rev) const {
            return this->_p < rev._p;
        }

        bool operator<(const reverse_iterator &rev) const {
            return this->_p > rev._p;
        }

        bool operator<=(const reverse_iterator &rev) const {
            return this->_p >= rev._p;
        }

        bool operator>=(const reverse_iterator &rev) const {
            return this->_p <= rev._p;
        }

        reverse_iterator& operator-=(difference_type _n) {
            this->_p += _n;
            return *this;
        }

        reverse_iterator operator+(difference_type _n) const {
            return reverse_iterator(this->_p - _n);
        }

        reverse_iterator<Iterator>& operator+=(difference_type _n) {
            this->_p -= _n;
            return *this;
        }

        reverse_iterator<Iterator> operator-(difference_type _n) const {
            return this->_p + _n;
        }

        difference_type operator-(const reverse_iterator& rev) const {
            return rev._p - this->_p;
        }

        reference_type operator*() const {
            iterator_type tmp = this->_p;
            tmp--;
            return *tmp;
        }

        pointer_type operator->() const {
            return &(operator*());
        }

        reference_type operator[](difference_type _n) const {
            return *(this->_p -_n -1 );
        }

        iterator_type base() const {
            return (this->_p);
        }

    };

    template <class Iterator, class Iterator2>
    bool operator==(reverse_iterator<Iterator> const &rev,
            reverse_iterator<Iterator2> const &rev2) {
        return rev.base() == rev2.base();
    }

    template <class Iterator, class Iterator2>
    bool operator!=(reverse_iterator<Iterator> const &rev,
            reverse_iterator<Iterator2> const &rev2) {
        return rev.base() != rev2.base();
    }

    template <typename Iterator, typename Iterator2>
    bool operator>(reverse_iterator<Iterator> const &rev,
                   reverse_iterator<Iterator2> const &rev2) {
        return rev.base() < rev2.base();
    }

    template <typename Iterator, typename Iterator2>
    bool operator<(reverse_iterator<Iterator> const &rev,
            reverse_iterator<Iterator2> const &rev2) {
        return rev.base() > rev2.base();
    }

    template <typename Iterator, typename Iterator2>
    bool operator>=(reverse_iterator<Iterator> const &rev,
            reverse_iterator<Iterator2> const &rev2) {
        return rev.base() <= rev2.base();
    }


    template <typename Iterator, typename Iterator2>
    bool operator<=(reverse_iterator<Iterator> const &rev,
            reverse_iterator<Iterator2> const &rev2) {
        return rev.base() >= rev2.base();
    }

    template <typename Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type _n,
            const reverse_iterator<Iterator> &rev) {
        return reverse_iterator<Iterator>(rev.base() - _n);
    }

    template <typename Iterator>
    reverse_iterator<Iterator> operator-(typename reverse_iterator<Iterator>::difference_type _n,
            const reverse_iterator<Iterator> &rev) {
        return reverse_iterator<Iterator>(rev.base() + _n);
    }
}
#endif