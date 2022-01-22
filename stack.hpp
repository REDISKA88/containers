#ifndef STACK_H
#include <vector>

namespace ft {
    template <typename T, class Container = std::vector<T> >
    class stack;
}
template<typename T, class Container>
class ft::stack {

public:
    typedef T value_type;
    typedef Container container_type;
    typedef std::size_t size_type;
public:
    container_type _ct;

public:

    stack() : _ct() {}

    explicit stack(const container_type &_ct = container_type()) {
        this->_ct = _ct;
    }

    //METHODS
    bool empty() const {
            return _ct.empty();
    }

    size_type size() const {
        return _ct.size();
    }

    void pop() {
         _ct.pop_back();
    }

    void push(value_type &v) {
        _ct.push_back(v);
    }

    value_type &top() {
        return _ct.back();
    }

    //OPERATORS
    bool operator==(const stack<T, Container> &b) const {
        return _ct == b._ct;
    }

    bool operator!=(const stack<T, Container> &b) const {
        return _ct != b._ct;
    }

    bool operator<(const stack<T, Container> &b) const {
        return _ct < b._ct;
    }

    bool operator>(const stack<T, Container> &b) const {
        return _ct > b._ct;
    }

    bool operator<=(const stack<T,Container> &b) const {
        return _ct <= b._ct;
    }

    bool operator>=(const stack<T,Container> &b) const {
        return _ct >= b._ct;
    }

    ~stack() {};
};


#define STACK_H
#endif
