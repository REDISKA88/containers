#ifndef MAP_HPP
#define MAP_HPP

namespace ft {
    template <typename T>
    struct node {

        T value;
        node* left;
        node* right;
        node* parent;
        bool  last;
        node(T _v, node* _l, node* _r, node* _p, bool _last_ = false)
            : value(_v), left(_l), right(_r), parent(_p), last(_last_) {};
        ~node(){};
    };
}
#endif