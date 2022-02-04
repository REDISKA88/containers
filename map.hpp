#include "iterator.hpp"
#include <functional>

template<typename KEY, typename T,
 typename Compare = std::less<KEY>, 
    typename Allocator = std::allocator<std::pair<const KEY, T>> >
    class map {
        public:
            class Iterator;
            class CIterator;
            class RIterator;
            class CRIterator;
	        class ValueComp;

            typedef KEY                                     key_type;
            typedef T                                       map_type;
            typedef Compare                                 key_compare;
            typedef std::pair<key_type, map_type>           value_type;
            typedef Allocator                               allocator_type;
            typedef value_type&                             reference;
            typedef value_type*                             pointer;
            typedef const value_type&                       const_reference;
            typedef const value_type*                       const_pointer;
            typedef Iterator                                iterator;
            typedef CIterator                               const_iterator;
            typedef RIterator                               reverse_iterator;
            typedef CRIterator                              const_reverse_iterator;
            typedef ValueComp                               value_compare;
            typedef size_t                                  size_type;
            typedef ptrdiff_t                               diff_type; 

        private:
            struct Node {
                bool                        isRed;
                Node                        *parent;
                Node                        *left;
                Node                        *right;
                std:pair<const KEY, T>      *data;

                Allocator                   _alloc;
                key_compare                 _comp;
                value_compare               _val_comp;
                size_t                      _size;
                Node                        *_root;

               
               //simple
               Node *max_node() {
                   Node *tmp = this;
                   while (tmp && tmp->right)
                        tmp = tmp->right;
               }

            }



     };

