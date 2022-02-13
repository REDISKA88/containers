namespace ft
{
    template <class InputIterator, class InputIterator2>
    bool lexicographical_compare(InputIterator first,
                                 InputIterator last,
                                 InputIterator2 first2,
                                 InputIterator last2) {
        for(; (first != last) && (first2 != last2); first++, first2++) {
            if (*first < *first2)
                return true;
            if (*first2 < *first)
                return false;
        }
        return (first == last) && (first2 != last2);
    }

    template <class InputIterator, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator first,
                                 InputIterator last,
                                 InputIterator2 first2,
                                 InputIterator2 last2,
                                 Compare cmp) {
        for(; (first != last) && (first2 != last2); first++, first2++) {
            if (cmp(*first, *first2))
                return true;
            if (cmp(*first2,*first))
                return false;
        }
        return (first == last) && (first2 != last2);
    }
}