#ifndef EQUAL_HPP
#define EQUAL_HPP

namespace ft {
    template <typename InputIterator, typename InputIterator2, typename BinaryPredicate>
    bool equal(InputIterator first,
               InputIterator last,
               InputIterator2 first2,
               BinaryPredicate pred) {
        while (first != last) {
            if (!pred(*first, *first2))
                return false;
            first++;
            first2++;
        }
        return true;
    }

    template <typename InputIterator, typename InputIterator2>
    bool equal(InputIterator first,
               InputIterator last,
               InputIterator2 first2) {
        while (first != last) {
            if (!(*first == *first2))
                return false;
            first++;
            first2++;
        }
        return true;
    }

}
#endif
