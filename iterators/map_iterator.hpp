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

    };
}






#endif