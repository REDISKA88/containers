#pragma once
#include "../vector/vector.hpp"

namespace ft
{
    template <class T, class Container = vector<T> >
    class stack {
    public:
        typedef T                                       value_type;
        typedef Container                               container_type;
        typedef size_t                                  size_type;

    protected:
        container_type _ct;

    public:
        container_type get_ct() const {
            return (this->_ct);
        }

        explicit stack(const container_type &_c_ = container_type()) : _ct(_c_) {}
        virtual ~stack() {}

        bool empty() const {
            return _ct.empty();
        }

        size_type size() const {
            return _ct.size();
        }

        value_type &top() {
            return _ct.back();
        }

        value_type &top() const {
            return _ct.back();
        }

        void push(value_type const &val) {
            this->_ct.push_back(val);
        }

        void pop() {
            this->_ct.pop_back();
        }
    };

    template <class T, class Container>
    bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
        return lhs.get_ct() == rhs.get_ct();
    }

    template <class T, class Container>
    bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
        return lhs.get_ct() != rhs.get_ct();
    }

    template <class T, class Container>
    bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
        return lhs.get_ct() < rhs.get_ct();
    }

    template <class T, class Container>
    bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
        return lhs.get_ct() > rhs.get_ct();
    }

    template <class T, class Container>
    bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
        return lhs.get_ct() <= rhs.get_ct();
    }

    template <class T, class Container>
    bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs) {
        return lhs.get_ct() >= rhs.get_ct();
    }

}