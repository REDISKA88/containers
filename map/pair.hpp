#ifndef PAIR_HPP
#define PAIR_HPP
namespace ft {

    template<class T, class T2>
    struct pair {
    public:
        typedef T       first_type;
        typedef T2      second_type;


        first_type      first;
        second_type     second;

        pair() : first(T()), second(T2()) {}
        ~pair() {}

        template<class T_, class T2_>
        pair(const pair<T_, T2_>& p) : first(p.first), second(p.second){}
        pair(const first_type& _first_, const second_type& _second_) : first(_first_), second(_second_) {}

        pair& operator=(const pair& P) {
            if (*this == P)
                return *this;
            first = P.first;
            second = P.second;
            return *this;
        }
    };

    template<typename T, typename T2>
    bool operator!=(const pair<T, T2>& p, const pair<T, T2>& p2) {
        return !(p == p2);
    }
    template<typename T, typename T2>
    bool operator==(const pair<T, T2>& p, const pair<T, T2>& p2) {
        return (p.first == p2.first && p.second == p2.second);
    }
    template<typename T, typename T2>
    bool operator>(const pair<T, T2>& p, const pair<T, T2>& p2) {
        return p2 < p;
    }
    template<typename T, typename T2>
    bool operator<(const pair<T, T2>& p, const pair<T, T2>& p2) {
        return (p.first < p2.first || (!(p2.first < p.first) && p.second < p2.second));
    }
    template<typename T, typename T2>
    bool operator>=(const pair<T, T2>& p, const pair<T, T2>& p2) {
        return (!(p < p2));
    }
    template<typename T, typename T2>
    bool operator<=(const pair<T, T2>& p, const pair<T, T2>& p2) {
        return (!(p2 < p));
    }
    template<typename T, typename T2>
    pair<T, T2> make_pair(T _first, T2 _second) {
        return pair<T, T2>(_first, _second);
    }
}
#endif
