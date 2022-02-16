#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP
#include "iterator_traits.hpp"
namespace ft {
    template <typename T, typename node>
    class map_iterator {
    public:
        typedef T                                   value_type;
        typedef value_type*                         pointer;
        typedef value_type&                         reference;
        typedef ptrdiff_t                           difference_type;
        typedef std::bidirectional_iterator_tag     iterator_category;

    protected:
        node    _p;

    public:
        map_iterator(): _p(NULL) {}
        map_iterator(node p) : _p(p) {}
        map_iterator(map_iterator const &r) : _p(r._p) {}
        virtual ~map_iterator() {}

        map_iterator& operator=(map_iterator const &r) {
            if (this != &r)
                this->_p = r._p;
            return *this;
        }
        //-------------------------------------------------

        map_iterator operator++(int) {
            map_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        map_iterator operator--(int) {
            map_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        node base() const {
            return (this->_p);
        }

        /////////////////////////////
        map_iterator& operator++() {
            if (this->_p->right) {
                this->_p = this->_p->right;
                while (this->_p->left)
                    this->_p = this->_p->left;
            }
            else {
                node tmp = this->_p;
                this->_p = this->_p->parent;
                while (this->_p->left != tmp) {
                    tmp = this->_p;
                    this->_p = this->_p->parent;
                }
            }
            return *this;
        }

        map_iterator& operator--() {
            if (this->_p->left) {
                this->_p = this->_p->left;
                while (this->_p->right)
                    this->_p = this->_p->right;
            }
            else {
                node tmp = this->_p;
                this->_p = this->_p->parent;
                while (this->_p->right != tmp) {
                    tmp = this->_p;
                    this->_p = this->_p->parent;
                }
            }
            return *this;
        }
        ////////////////////////////////////////

        reference operator*() const {
            return this->_p->data;
        }

        pointer operator->() const {
            return &(operator*());
        }


        template <typename Iterator_>
        bool operator!=(const map_iterator<Iterator_,
                node> &r) const {
            return (this->_p != r.base());
        }

        template <typename Iterator_>
        bool operator==(const map_iterator<Iterator_, node> &r) const {
            return (this->_p == r.base());
        }

        operator map_iterator<const T, node>() const {
            return map_iterator<const T, node>(this->_p);
        }

    };
}

#endif