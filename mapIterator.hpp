#ifndef MAPITERATOR_HPP
#define MAPITERATOR_HPP
#include <cstddef>
#include "pair.hpp"
#include "iterator.hpp"
namespace ft {
    template <typename T, typename  node_type>
    class mapIterator {
    private:
        typedef std::bidirectional_iterator_tag biter_tag;

    public:
        typedef T                   value_type;
        typedef value_type*         pointer;
        typedef value_type&         reference;
        typedef ptrdiff_t           difference_type;
        typedef biter_tag           iterator_category;

    private:
        node_type                   _p;

    public:
        mapIterator() :_p(NULL) {};
        mapIterator(node_type _node) :_p(_node) {};
        mapIterator(mapIterator const& _it): _p(_it._p) {};

        virtual ~mapIterator() {};

        mapIterator& operator=(mapIterator const& _it) {
            if (this != _it)
                this->_p = _it._p;
            return *this;
        }

        mapIterator &operator++(void) {
            if (this->_p->right) {
                this->_p = this->_p->right;
                while (this->_p->left)
                    this->_p = this->_p->left;
            }
            else {
                node_type _it = this->_p;
                this->_p = this->_p->parent;
                while (this->_p->left != _it) {
                    _it = this->_p;
                    this->_p = this->_p->parent;
                }
            }
        }

        mapIterator &operator--(void) {
            if (this->_p->left) {
                this->_p = this->_p->left;
                while (this->_p->right)
                    this->_p = this->_p->right;
            } else {
                mapIterator _it = this->_p;
                this->_p = this->_p->parent;
                while (this->_p->right != _it) {
                    _it = this->_p;
                    this->_p = this->_p->parent;
                }
            }
        }

        mapIterator operator++(int) {
            mapIterator _it = *this;
            ++(*this);
            return _it;
        }

        mapIterator operator--(int) {
            mapIterator _it = *this;
            --(*this);
            return _it;
        }

        reference operator*() const {
            return this->_p->value;
        }

        pointer operator->() const {
            return &operator*();
        }

        node_type getNode() const{
            return this->_p;
        }

        operator mapIterator<const T, node_type>() const {
            return mapIterator<const T, node_type>(this->_p);
        }

        template <typename _it>
        bool operator==(const mapIterator<_it, node_type> &_n) const {
            return (this->_p == _n.getNode());
        }

        template <typename _it>
        bool operator!=(const mapIterator<_it, node_type> &_n) const {
            return (this->_p != _n.getNode());
        }
    };
}
#endif
