#pragma once

#include <memory>
#include "pair.hpp"
#include "equal.hpp"
#include "../iterators/map_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../vector/enable_if.hpp"
#include "../vector/is_integral.hpp"

namespace ft {
    template <class Key, class T, class Compare = std::less<Key>,
            class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map {
    public:
        typedef Key                         key_type;
        typedef T                           mapped_type;
        typedef Compare                     key_compare;
        typedef Allocator                   allocator_type;
        typedef ft::pair<const key_type, mapped_type>                   value_type;
        typedef typename allocator_type::pointer                        pointer;
        typedef typename allocator_type::reference                      reference;
        typedef typename allocator_type::const_pointer                  const_pointer;
        typedef typename allocator_type::const_reference                const_reference;
        typedef typename allocator_type::size_type                      size_type;
        typedef typename allocator_type::difference_type                difference_type;

        class value_compare : public std::binary_function<value_type, value_type, bool> {
            friend class map;
        protected:
            key_compare cmp;
            value_compare(key_compare _c) : cmp(_c) {}

        public:
            bool operator()(const value_type& vt, const value_type& vt2) const {
                return cmp(vt.first, vt2.first);
            }
        };

        template <typename T_>
        struct Node {
            T_ data; Node *left; Node *right; Node *parent; bool last;
            Node(T_ v, Node *l, Node *r, Node *p, bool e = false)
                    : data(v), left(l), right(r), parent(p), last(e) {}
        };

        typedef Node<value_type>                                node_type;
        typedef Node<value_type>*                               root_node;
        typedef map_iterator<value_type, node_type*>            iterator;
        typedef map_iterator<const value_type, node_type *>     const_iterator;
        typedef ft::reverse_iterator<iterator>                  reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;
        typedef typename allocator_type::template rebind<node_type>::other node_allocator;


    protected:
        root_node           _r;
        size_type           _size;
        key_compare         _key_compare;
        node_allocator      _allocator;

    };

    }
}