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

        node_type *findNode(const key_type& _key, node_type* _node_) const {
            if (!_node_ || _node_->last)
                return NULL;
            if (_key_compare(_key, _node_->data.first))
                return findNode(_key, _node_->left);
            else if (_key_compare(_node_->data.first, _key))
                return findNode(_key, _node_->right);
            else
                return _node_;
        }
        //-----------------------
        //simple
        size_type size() const {
            return _size;
        }

        size_type max_size() const {
            return _allocator.max_size();
        }

        bool empty() const {
            return _size == 0;
        }

        void clear() {
            _size = 0;
        }

        allocator_type get_allocator() const {
            return _allocator;
        }

        key_compare key_comp() const {
            return _key_compare;
        }

        value_compare value_comp() const {
            return value_compare(_key_compare);
        }

        //---------------------------------------

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
            return iterator(findNode(vt.first, _r));
        }

        template <class InputIterator>
        void insert(typename ft::enable_if<!ft::is_integral<InputIterator>::value,
                InputIterator>::type first, InputIterator last) {
            for(; first != last; first++)
                insert(*first);
        }

        //----------------------------------------------------------

        iterator begin() {
            if (_size == 0)
                return _r;
            node_type *tmp = _r;
            while (tmp && tmp->left)
                tmp = tmp->left;
            return tmp;
        }

        const_iterator begin() const {
            if (_size == 0)
                return const_iterator(_r);
            node_type *tmp = _r;
            while (tmp && tmp->left)
                tmp = tmp->left;
            return const_iterator(tmp);
        }

        iterator end() {
            if (!_r) {
                insert(value_type(key_type(), mapped_type()));
                _r->last = true;
                _size--;
            }
            if (_size == 0)
                return _r;
            node_type *tmp = _r;
            while (tmp && !tmp->last)
                tmp = tmp->right;
            return tmp;
        }

        const_iterator end() const {
            if (_size == 0)
                return const_iterator(_r);
            node_type *tmp = _r;
            while (tmp && !tmp->last)
                tmp = tmp->right;
            return const_iterator(tmp);
        }

        reverse_iterator rbegin() {
            return reverse_iterator(end()--);
        }

        const_reverse_iterator rbegin() const {
            return const_reverse_iterator(end()--);
        }

        reverse_iterator rend() {
            return reverse_iterator(begin());
        }

        const_reverse_iterator rend() const {
            return const_reverse_iterator(begin());
        }

        size_type count(const key_type& _key) {
            if (find(_key) != end())
                return 1;
            return 0;
        }

        void swap(map &Map2) {
            node_type* r = _r;
            size_type size = _size;
            key_compare key = _key_compare;
            node_allocator alloc = _allocator;

            _r = Map2._r;
            _size = Map2._size;
            _key_compare = Map2._key_compare;
            _allocator = Map2._allocator;

            Map2._r = r;
            Map2._size = size;
            Map2._key_compare = key;
            Map2._allocator = alloc;
        }

        iterator find(const key_type& _key) {
            node_type *tmp = findNode(_key, _r);
            if (tmp)
                return (iterator(tmp));
            return end();
        }

        const_iterator find(const key_type& _key) const {
            node_type *tmp = findNode(_key, _r);
            if (tmp)
                return const_iterator(tmp);
            return const_iterator(end());
        }

        void erase(iterator position) {
            erase(position->first);
        }

        size_type erase(key_type const& _key) {
            size_type tmp = _size;
            _r = destroyNode(_r, _key);
            return tmp - _size;
        }

        void erase(iterator first, iterator last) {
            map<key_type, mapped_type> tmp(first, last);
            for (iterator _begin = tmp.begin(), _end = tmp.end(); _begin != _end; _begin++)
                _r = destroyNode(_r, _begin->first);
        }

        iterator lower_bound(const key_type& _key) {
            iterator _end = end();
            iterator _begin = begin();
            while (_begin != _end)
            {
                if (!_key_compare(_begin->first, _key))
                    return _begin;
                _begin++;
            }
            return _end;
        }

        const_iterator lower_bound(const key_type& _key) const{
            const_iterator _end = end();
            const_iterator _begin = begin();

            while (_begin != _end) {
                if (!_key_compare(_begin->first, _key))
                    return _begin;
                _begin++;
            }
            return _end;
        }

        iterator upper_bound(const key_type& _key) {
            iterator _begin = begin();
            iterator _end = end();
            while (_begin != _end) {
                if (_key_compare(_key, _begin->first))
                    return _begin;
                _begin++;
            }
            return _end;
        }

        const_iterator upper_bound(const key_type& _key) const {
            const_iterator _begin = begin();
            const_iterator _end = end();
            while (_begin != _end) {
                if (_key_compare(_key, _begin->first))
                    return _begin;
                _begin++;
            }
            return _end;
        }

        mapped_type &operator[](const key_type& _key)
        {
            node_type *tmp = findNode(_key, _r);
            if (tmp)
                return tmp->data.second;
            insert(value_type(_key, mapped_type()));
            return (findNode(_key, _r)->data.second);
        }

        pair<iterator, bool> insert(const value_type& vt) {
            size_t tmp = _size;
            insert(NULL, vt);
            return (pair<iterator, bool>(findNode(vt.first, _r), tmp != _size));
        }

        pair<iterator, iterator> equal_range(const key_type& _key) {
            return pair<iterator, iterator>(lower_bound(_key), upper_bound(_key));
        }

        pair<const_iterator, const_iterator> equal_range(const key_type& _key) const {
            return pair<const_iterator, const_iterator>(lower_bound(_key), upper_bound(_key));
        }
    };

    template <class Key, class T, class Compare, class Allocator>
    bool operator!=(const map<Key, T, Compare, Allocator> &X,
            const map<Key, T, Compare, Allocator> &Y) {
        return !(X == Y);
    }

    template <class Key, class T, class Compare, class Allocator>
    bool operator>=(const map<Key, T, Compare, Allocator> &X,
            const map<Key, T, Compare, Allocator> &Y) {
        return (X > Y || X == Y);
    }

    template <class Key, class T, class Compare, class Allocator>
    bool operator<=(const map<Key, T, Compare, Allocator> &X,
            const map<Key, T, Compare, Allocator> &Y) {
        return (X < Y || X == Y);
    }

    template <class Key, class T, class Compare, class Allocator>
    bool operator>(const map<Key, T, Compare, Allocator> &X,
                   const map<Key, T, Compare, Allocator> &Y) {
        return Y < X;
    }

    template <class Key, class T, class Compare, class Allocator>
    bool operator<(const map<Key, T, Compare, Allocator> &X,
            const map<Key, T, Compare, Allocator> &Y) {
        return lexicographical_compare(X.begin(), X.end(), Y.begin(), Y.end());
    }

    template <class Key, class T, class Compare, class Allocator>
    bool operator==(const map<Key, T, Compare, Allocator> &X,
            const map<Key, T, Compare, Allocator> &Y) {
        if (X.size() != Y.size())
            return false;
        return equal(X.begin(), X.end(), Y.begin());
    }

    template <class Key, class T, class Compare, class Allocator>
    void swap(map<Key, T, Compare, Allocator> &X, map<Key, T, Compare, Allocator> &Y) { X.swap(Y); }
}