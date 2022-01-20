#ifndef STACK_H
#include <vector>
// here we will replace <std::vector> to "ft_vector"
template <typename T, class Container = std::vector<T> >
class Stack : public std::vector<T> {

public:
    typedef T value_type;
    typedef Container container_type;
    typedef std::size_t size_type;
private:
    container_type  _ctnr;
public:
    explicit Stack(const container_type& _ctnr){}


};

#define STACK_H
#endif
