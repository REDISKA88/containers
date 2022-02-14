#pragma once

#include "../vector/enable_if.hpp"
#include "../vector/is_integral.hpp"
#include "../iterators/map_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"

namespace ft {
    template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
            //fix std to ft
            class map {
            public:



                    };
}