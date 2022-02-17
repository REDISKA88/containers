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


    private:
        node_allocator      _allocator;
        key_compare         _key_compare;
        size_type           _size;
        root_node           _r;

    public:
        explicit map(const key_compare& _cmp_ = key_compare(),
                     const allocator_type& _alloc_ = allocator_type())
                : _allocator(_alloc_), _key_compare(_cmp_), _size(0), _r(NULL){}
        template <class Iterator>
        map(typename ft::enable_if<!ft::is_integral<Iterator>::value,
                Iterator>::type first, Iterator last, const key_compare& _cmp_ = key_compare(),
            const allocator_type& _alloc_ = allocator_type())
                    : _allocator(_alloc_), _key_compare(_cmp_), _size(0), _r(NULL) {
            insert(first, last);
        }
        map(const map &M) : _allocator(M._allocator),
                            _key_compare(M._key_compare), _size(0), _r(NULL) {
            *this = M;
        }
        //---------------
        // node func
        node_type *insertNode(const value_type& vt, node_type* _node_, node_type* parent) {
            if (!_node_) {
                node_type *node = _allocator.allocate(1);
                _allocator.construct(node, node_type(vt, NULL, NULL, parent)); _size++;
                return node;
            }
            if (_node_->last) {
                node_type *_new = _allocator.allocate(1);
                _allocator.construct(_new, node_type(vt, NULL, NULL, parent)); _size++;
                _node_->parent = _new;
                _new->right = _node_;
                _node_ = _new;
                return _node_;
            }
            if (_key_compare(vt.first, _node_->data.first))
                _node_->left = insertNode(vt, _node_->left, _node_);
            else if (_key_compare(_node_->data.first, vt.first))
                _node_->right = insertNode(vt, _node_->right, _node_);
            return _node_;
        }

        node_type *destroyNode(node_type* _node_, const key_type& _key) {
            if (!_node_ || _node_->last)
                return _node_;
            if (_key_compare(_key, _node_->data.first))
                _node_->left = destroyNode(_node_->left, _key);
            else if (_key_compare(_node_->data.first, _key))
                _node_->right = destroyNode(_node_->right, _key);
            else {
                if (!_node_->left || !_node_->right) {
                    node_type *tmp = _node_->left ? _node_->left : _node_->right;
                    if (!_node_->left && !_node_->right) {
                        tmp = _node_; _node_ = NULL;
                        _allocator.destroy(tmp); _allocator.deallocate(tmp, 1); _size--;
                    } else {
                        tmp->parent = _node_->parent;
                        node_type *tmp2 = _node_; _node_ = tmp;
                        _allocator.destroy(tmp2); _allocator.deallocate(tmp2, 1); _size--;
                    }
                } else {
                    node_type *tmp = _node_->right;
                    while (tmp->left != NULL)
                        tmp = tmp->left;
                    if (tmp != _node_->right) {
                        tmp->right = _node_->right;
                        _node_->right->parent = tmp;
                    }
                    tmp->left = _node_->left;
                    _node_->left->parent = tmp;
                    tmp->parent->left = NULL;
                    tmp->parent = _node_->parent;
                    if (_r == _node_)
                        _r = tmp;
                    _allocator.destroy(_node_); _allocator.deallocate(_node_, 1); _size--;
                    _node_ = tmp;
                }
            }
            return _node_;
        }

        node_type *find_key(const key_type& _key, node_type* _node_) const {
            if (!_node_ || _node_->last)
                return NULL;
            if (_key_compare(_key, _node_->data.first))
                return find_key(_key, _node_->left);
            else if (_key_compare(_node_->data.first, _key))
                return find_key(_key, _node_->right);
            else
                return _node_;
        }
        //-----------------------------------------------------
        iterator insert(iterator it, const value_type& vt) {
            if (!_r) {
                node_type *_new = _allocator.allocate(1);
                _allocator.construct(_new, node_type(vt, NULL, NULL, NULL)); _size++;
                _r = _new;
                node_type *end = _allocator.allocate(1);
                _allocator.construct(end,node_type(value_type(key_type(),mapped_type()),NULL,NULL,_r));
                _r->right = end;
                end->last = true;
            }
            if (_r->last) {
                node_type *_new = _allocator.allocate(1);
                _allocator.construct(_new, node_type(vt, NULL, NULL, NULL));
                _r->parent = _new;
                _new->right = _r;
                _r = _new;
                return _r;
            }
            it = NULL;
            insertNode(vt, _r, NULL);
            return iterator(find_key(vt.first, _r));
        }

        template <class InputIterator>
        void insert(typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                InputIterator>::type first, InputIterator last) {
            for(; first != last; first++)
                insert(*first);
        }
    };

}