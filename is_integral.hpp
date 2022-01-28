namespace ft
{
    template <typename Iterator>
    class reverse_iterator;

    template<typename>
    struct is_integral {
        static const bool _value = false;
    };
    template< >
    struct is_integral<bool> {
        static const bool _value = true;
    };
    template< >
    struct is_integral<int> {
        static const bool _value = true;
    };
    template< >
    struct is_integral<signed char> {
        static const bool _value = true;
    };
    template< > struct is_integral<short int> {
        static const bool _value = true;
    };
    template< >
    struct is_integral<long long int> {
        static const bool _value = true;
    };
    template< >
    struct is_integral<long int> {
        static const bool _value = true;
    };
    template< >
    struct is_integral<unsigned char> {
        static const bool _value = true;
    };
    template< >
    struct is_integral<unsigned short int> {
        static const bool _value = true;
    };
    template< >
    struct is_integral<unsigned int> {
        static const bool _value = true;
    };
    template< > struct is_integral<unsigned long int> {
        static const bool _value = true;
    };
    template< >
    struct is_integral<unsigned long long int> {
        static const bool _value = true;
    };
}