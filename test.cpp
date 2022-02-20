#include <map>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <stack>
#include "stack/stack.hpp"
#include "vector/vector.hpp"
#include "map/map.hpp"

int main() {
    {
        {
            std::vector <std::string> my_v(10, "fill constructor test");
            std::vector <std::string> v(10, "fill constructor test");
            std::string res, my_res;
            for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it)
                res += *it;
            for (std::vector<std::string>::iterator it = my_v.begin(); it != my_v.end(); ++it)
                my_res += *it;

        }
        {
            std::vector <std::string> v(10, "range constructor test");
            std::vector <std::string> my_v(10, "range constructor test");
            std::vector <std::string> my_v1(my_v.begin(), my_v.end());
            std::string res, my_res, my_res1;
            for (std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it)
                res += *it;
            for (std::vector<std::string>::iterator it = my_v.begin(); it != my_v.end(); ++it)
                my_res += *it;
            for (std::vector<std::string>::iterator it = my_v1.begin(); it != my_v1.end(); ++it)
                my_res1 += *it;

        }
        {
            std::vector<char> v1(10, 'a');
            std::vector<char> copy_v(v1);
            std::string res, res1;
            for (std::vector<char>::iterator it = v1.begin(); it != v1.end(); ++it)
                res += *it;
            for (std::vector<char>::iterator it = copy_v.begin(); it != copy_v.end(); ++it)
                res1 += *it;

        }
        {
            std::vector <std::string> v1(10, "string1");
            std::vector <std::string> v2(10, "string2");
            v1 = v2;
            std::vector <std::string> ft_v1(10, "string1");
            std::vector <std::string> ft_v2(10, "string2");
            ft_v1 = ft_v2;
            std::string res, ft_res;
            for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it)
                res += *it;
            for (std::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
                ft_res += *it;
        }
        {
            std::vector <std::string> v1(10, "string1");
            std::vector <std::string> v2(20, "string2");
            v1 = v2;
            std::vector <std::string> ft_v1(10, "string1");
            std::vector <std::string> ft_v2(20, "string2");
            ft_v1 = ft_v2;
            std::string res, ft_res;
            for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it)
                res += *it;
            for (std::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
                ft_res += *it;
        }
        {
            std::vector <std::string> v1(20, "string1");
            std::vector <std::string> v2(10, "string2");
            v1 = v2;
            std::vector <std::string> ft_v1(20, "string1");
            std::vector <std::string> ft_v2(10, "string2");
            ft_v1 = ft_v2;
            std::string res, ft_res;
            for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it)
                res += *it;
            for (std::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
                ft_res += *it;
        }
        {
            std::vector <std::string> v1;
            std::vector <std::string> v2(10, "string2");
            v1 = v2;
            std::vector <std::string> ft_v1;
            std::vector <std::string> ft_v2(10, "string2");
            ft_v1 = ft_v2;
            std::string res, ft_res;
            for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it)
                res += *it;

            for (std::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
                ft_res += *it;
        }
        {
            std::vector <std::string> v1(10, "string2");
            std::vector <std::string> v2;
            v1 = v2;

            std::vector <std::string> ft_v1(10, "string2");
            std::vector <std::string> ft_v2;
            ft_v1 = ft_v2;
            std::string res, ft_res;
            for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it)
                res += *it;
            for (std::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
                ft_res += *it;
        }
        {
            std::vector <std::string> v1(10, "string2");
            std::vector <std::string> const v2(10, "string2");
            std::vector <std::string> ft_v1(10, "string2");
            std::vector <std::string> const ft_v2(10, "string2");
            std::string res, ft_res, c_res, c_ft_res;
            for (std::vector<std::string>::iterator it = v1.begin(); it != v1.end(); ++it)
                res += *it;
            for (std::vector<std::string>::const_iterator rit = v2.begin(); rit != v2.end(); ++rit)
                c_res += *rit;
            for (std::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
                ft_res += *it;
            for (std::vector<std::string>::const_iterator rit = ft_v2.begin(); rit != ft_v2.end(); ++rit)
                c_ft_res += *rit;
        }
        {
            std::vector <std::string> v1(10, "string2");
            std::vector <std::string> const v2(10, "string2");
            std::vector <std::string> ft_v1(10, "string2");
            std::vector <std::string> const ft_v2(10, "string2");
            std::string res, ft_res, c_res, c_ft_res;
            for (std::vector<std::string>::reverse_iterator rit = v1.rbegin(); rit != v1.rend(); ++rit)
                res += *rit;
            for (std::vector<std::string>::const_reverse_iterator rit = v2.rbegin(); rit != v2.rend(); ++rit)
                c_res += *rit;
            for (std::vector<std::string>::reverse_iterator rit = ft_v1.rbegin(); rit != ft_v1.rend(); ++rit)
                ft_res += *rit;
            for (std::vector<std::string>::const_reverse_iterator rit = ft_v2.rbegin(); rit != ft_v2.rend(); ++rit)
                c_ft_res += *rit;
        }
        {
            std::vector <std::string> v1(10, "string2");
            std::vector <std::string> v2;
            std::vector <std::string> v3(v1.begin(), v1.end());
            std::vector <std::string> v4(v3);
            std::vector <std::string> v5(v1.rbegin(), v1.rend());
            std::vector <std::string> ft_v1(10, "string2");
            std::vector <std::string> ft_v2;
            std::vector <std::string> ft_v3(ft_v1.begin(), ft_v1.end());
            std::vector <std::string> ft_v4(ft_v1);
            std::vector <std::string> ft_v5(ft_v1.rbegin(), ft_v1.rend());
        }
        {
            std::vector <std::string> v1(10, "string2");
            std::vector <std::string> v2;
            std::vector <std::string> v3(v1.begin(), v1.end());
            std::vector <std::string> v4(v3);
            std::vector <std::string> v5(v1.rbegin(), v1.rend());
            std::vector <std::string> ft_v1(10, "string2");
            std::vector <std::string> ft_v2;
            std::vector <std::string> ft_v3(ft_v1.begin(), ft_v1.end());
            std::vector <std::string> ft_v4(ft_v1);
            std::vector <std::string> ft_v5(ft_v1.rbegin(), ft_v1.rend());
        }
        {
            std::vector <std::string> v1(10, "string");
            std::vector<int> v2;
            std::vector<double> v4;
            std::vector <std::string> ft_v1(10, "string2");
            std::vector<int> ft_v2;
            std::vector<double> ft_v4;
        }
        {
            std::string s1, s2, s3, s4, ft_s1, ft_s2, ft_s3, ft_s4;
            std::string sit1, sit2, sit3, ft_sit1, ft_sit2, ft_sit3;
            size_t z1, z2, z3, z4, ft_z1, ft_z2, ft_z3, ft_z4;
            size_t c1, c2, c3, c4, ft_c1, ft_c2, ft_c3, ft_c4;
            std::vector<std::string>::iterator valid_it, valid_eit;
            std::vector<std::string>::iterator ft_valid_it, ft_valid_eit;
            std::vector <std::string> v1(10, "string2");
            v1.resize(1e6, "hello");
            std::vector <std::string> ft_v1(10, "string2");
            ft_v1.resize(1e6, "hello");
            z1 = v1.size();
            ft_z1 = ft_v1.size();
            c1 = v1.capacity();
            ft_c1 = ft_v1.capacity();
            for (size_t i = 0; i < v1.size(); ++i)
                s1 += v1[i];
            for (std::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
                ft_s1 += *it;
            v1.resize(20);
            valid_it = v1.begin();
            valid_eit = v1.end();
            v1.resize(1e5);
            ft_v1.resize(20);
            ft_valid_it = ft_v1.begin();
            ft_valid_eit = ft_v1.end();
            ft_v1.resize(1e5);
            z2 = v1.size();
            ft_z2 = ft_v1.size();
            c2 = v1.capacity();
            ft_c2 = ft_v1.capacity();
            for (size_t i = 0; i < v1.size(); ++i)
                s2 += v1[i];
            for (; valid_it != valid_eit; ++valid_it)
                sit1 += *valid_it;
            for (std::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
                ft_s2 += *it;
            for (; ft_valid_it != ft_valid_eit; ++ft_valid_it)
                ft_sit1 += *ft_valid_it;
            valid_it = v1.begin();
            v1.resize(50);
            ft_valid_it = ft_v1.begin();
            ft_v1.resize(50);
            z3 = v1.size();
            ft_z3 = ft_v1.size();
            c3 = v1.capacity();
            ft_c3 = ft_v1.capacity();
            for (size_t i = 0; i < v1.size(); ++i)
                s3 += v1[i];
            for (; valid_it != v1.end(); ++valid_it)
                sit2 += *valid_it;
            for (std::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
                ft_s3 += *it;
            for (; ft_valid_it != ft_v1.end(); ++ft_valid_it)
                ft_sit2 += *ft_valid_it;
            valid_it = v1.begin();
            v1.resize(0, "string4");
            ft_valid_it = ft_v1.begin();
            ft_v1.resize(0, "string4");
            z4 = v1.size();
            ft_z4 = ft_v1.size();
            c4 = v1.capacity();
            ft_c4 = ft_v1.capacity();
            for (size_t i = 0; i < v1.size(); ++i)
                s4 += v1[i];
            for (; valid_it != v1.end(); ++valid_it)
                sit3 += *valid_it;
            for (std::vector<std::string>::iterator it = ft_v1.begin(); it != ft_v1.end(); ++it)
                ft_s4 += *it;
            for (; ft_valid_it != ft_v1.end(); ++ft_valid_it)
                ft_sit3 += *ft_valid_it;
        }
        {
            std::vector <std::string> v1(10, "string2");
            std::vector<char> const v2(10, '9');
            std::vector <std::string> ft_v1(10, "string2");
            std::vector<char> const ft_v2(10, '9');
            std::string s1, s2, ft_s1, ft_s2;
            for (size_t i = 0; i < v1.size(); ++i) {
                if (i == v1.size() - 1)
                    v1[i] = "other";
                s1 += v1[i];
            }
            for (size_t i = 0; i < ft_v1.size(); ++i) {
                if (i == ft_v1.size() - 1)
                    ft_v1[i] = "other";
                ft_s1 += ft_v1[i];
            }
            for (size_t i = 0; i < v2.size(); ++i)
                s2 += v2[i];
            for (size_t i = 0; i < ft_v2.size(); ++i)
                ft_s2 += ft_v2[i];

        }
        {
            std::vector <std::string> v1(10, "string2");
            std::vector<char> const v2(10, '9');
            std::vector <std::string> ft_v1(10, "string2");
            std::vector<char> const ft_v2(10, '9');
            std::string s1, s2, ft_s1, ft_s2;
            bool exce_throwed = false;
            try {
                ft_v1.at(20);
            }
            catch (std::out_of_range const &e) {
                (void) e;
                exce_throwed = true;
            }
            for (size_t i = 0; i < v1.size(); ++i) {
                if (i == v1.size() - 1)
                    v1.at(i) = "other";
                s1 += v1.at(i);
            }
            for (size_t i = 0; i < ft_v1.size(); ++i) {
                if (i == ft_v1.size() - 1)
                    ft_v1.at(i) = "other";
                ft_s1 += ft_v1.at(i);
            }
            for (size_t i = 0; i < v2.size(); ++i)
                s2 += v2.at(i);
            for (size_t i = 0; i < ft_v2.size(); ++i)
                ft_s2 += ft_v2.at(i);

        }
        {
            std::vector <std::string> v1(10, "string2");
            std::vector<int> const v2(10, 9);
            std::vector <std::string> ft_v1(10, "string2");
            std::vector<int> const ft_v2(10, 9);
            v1.front() = "LEET";
            ft_v1.front() = "LEET";
        }
        {
            std::vector <std::string> v1(10, "string2");
            std::vector<int> const v2(10, 9);
            std::vector <std::string> ft_v1(10, "string2");
            std::vector<int> const ft_v2(10, 9);
            v1.back() = "LEET";
            ft_v1.back() = "LEET";
        }
        {
            std::vector <std::string> v1(20, "less");
            std::vector <std::string> v2;
            std::vector <std::string> v3(10, "string2");
            std::vector <std::string> ft_v1(20, "less");
            std::vector <std::string> ft_v2;
            std::vector <std::string> ft_v3(10, "string2");
            std::string s1, s2, s3, ft_s1, ft_s2, ft_s3;
            size_t z1, z2, z3, ft_z1, ft_z2, ft_z3;
            size_t c1, c2, c3, ft_c1, ft_c2, ft_c3;
            v3.assign(v1.begin(), v1.end());
            ft_v3.assign(v1.begin(), v1.end());
            z1 = v3.size();
            c1 = v3.capacity();
            ft_z1 = ft_v3.size();
            ft_c1 = ft_v3.capacity();
            for (size_t i = 0; i < v3.size(); ++i)
                s1 += v3.at(i);
            for (size_t i = 0; i < ft_v3.size(); ++i)
                ft_s1 += ft_v3.at(i);
            v1.assign(v3.begin(), v3.end());
            ft_v1.assign(ft_v3.begin(), ft_v3.end());
            z2 = v1.size();
            c2 = v1.capacity();
            ft_z2 = ft_v1.size();
            ft_c2 = ft_v1.capacity();
            for (size_t i = 0; i < v1.size(); ++i)
                s3 += v1.at(i);
            for (size_t i = 0; i < ft_v1.size(); ++i)
                ft_s3 += ft_v1.at(i);
            v2.assign(v1.begin(), v1.end());
            ft_v2.assign(ft_v1.begin(), ft_v1.end());
            z3 = v2.size();
            c3 = v2.capacity();
            ft_z3 = ft_v2.size();
            ft_c3 = ft_v2.capacity();
            for (size_t i = 0; i < v2.size(); ++i)
                s2 += v2.at(i);
            for (size_t i = 0; i < ft_v2.size(); ++i)
                ft_s2 += ft_v2.at(i);
        }
        {
            std::vector <std::string> v;
            std::vector <std::string> ft_v;
            std::string s1, s2, s3, ft_s1, ft_s2, ft_s3;
            size_t z1, z2, z3, ft_z1, ft_z2, ft_z3;
            size_t c1, c2, c3, ft_c1, ft_c2, ft_c3;
            std::vector<std::string>::iterator ft_it;
            v.push_back("hello");
            ft_v.push_back("hello");
            ft_it = ft_v.begin();
            ft_it->length();
            z1 = v.size();
            c1 = v.capacity();
            ft_z1 = ft_v.size();
            ft_c1 = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                s1 += v.at(i);
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_s1 += ft_v.at(i);
            v.reserve(30);
            ft_v.reserve(30);
            v.push_back("string");
            ft_v.push_back("string");
            v.push_back("string");
            ft_v.push_back("string");
            z2 = v.size();
            c2 = v.capacity();
            ft_z2 = ft_v.size();
            ft_c2 = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                s2 += v.at(i);
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_s2 += ft_v.at(i);
            for (size_t i = 0; i < 100; ++i)
                v.push_back("string");
            for (size_t i = 0; i < 100; ++i)
                ft_v.push_back("string");
            z3 = v.size();
            c3 = v.capacity();
            ft_z3 = ft_v.size();
            ft_c3 = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                s3 += v.at(i);
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_s3 += ft_v.at(i);

        }
        {
            std::vector <std::string> v(20, "string");
            std::vector <std::string> ft_v(20, "string");
            std::string s1, ft_s1;
            size_t z1, ft_z1;
            size_t c1, ft_c1;
            v.pop_back();
            ft_v.pop_back();
            z1 = v.size();
            ft_z1 = ft_v.size();
            c1 = v.capacity();
            ft_c1 = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                s1 += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_s1 += ft_v[i];
        }
        {
            std::string str, ft_str;
            std::vector<std::string>::size_type s, ft_s;
            std::vector<std::string>::size_type c, ft_c;
            std::vector<std::string>::iterator ft_it;
            std::vector<std::string>::iterator it;
            {
                std::vector <std::string> v;
                std::vector <std::string> ft_v;
                it = v.insert(v.begin(), "hello");
                ft_it = ft_v.insert(ft_v.begin(), "hello");
                ft_it->length();
                s = v.size();
                ft_s = ft_v.size();
                c = v.capacity();
                ft_c = ft_v.capacity();
                for (size_t i = 0; i < v.size(); ++i)
                    str += v[i];
                for (size_t i = 0; i < ft_v.size(); ++i)
                    ft_str += ft_v[i];
            }

            {
                std::vector <std::string> v;
                std::vector <std::string> ft_v;
                it = v.insert(v.end(), "hello");
                ft_it = ft_v.insert(ft_v.end(), "hello");
                ft_it->length();
                str.clear();
                ft_str.clear();
                s = v.size();
                ft_s = ft_v.size();
                c = v.capacity();
                ft_c = ft_v.capacity();
                for (size_t i = 0; i < v.size(); ++i)
                    str += v[i];
                for (size_t i = 0; i < ft_v.size(); ++i)
                    ft_str += ft_v[i];
            }
            {
                std::vector <std::string> v(20, "string");
                std::vector <std::string> ft_v(20, "string");
                std::vector<std::string>::iterator valid_it;
                v.reserve(30);
                ft_v.reserve(30);
                valid_it = ft_v.begin();
                it = v.insert(v.begin() + 10, "hello");
                ft_it = ft_v.insert(ft_v.begin() + 10, "hello");
                ft_it->length();
                str.clear();
                ft_str.clear();
                s = v.size();
                ft_s = ft_v.size();
                c = v.capacity();
                ft_c = ft_v.capacity();
                for (size_t i = 0; i < v.size(); ++i)
                    str += v[i];
                for (size_t i = 0; i < ft_v.size(); ++i)
                    ft_str += ft_v[i];
            }
            {
                std::vector <std::string> v(20, "string");
                std::vector <std::string> ft_v(20, "string");
                it = v.insert(v.begin() + 10, "hello");
                ft_it = ft_v.insert(ft_v.begin() + 10, "hello");
                ft_it->length();
                str.clear();
                ft_str.clear();
                s = v.size();
                ft_s = ft_v.size();
                c = v.capacity();
                ft_c = ft_v.capacity();
                for (size_t i = 0; i < v.size(); ++i)
                    str += v[i];
                for (size_t i = 0; i < ft_v.size(); ++i)
                    ft_str += ft_v[i];
            }
        }
        {
            std::string str, ft_str;
            std::vector<std::string>::size_type s, ft_s;
            std::vector<std::string>::size_type c, ft_c;
            {
                std::vector <std::string> v;
                std::vector <std::string> ft_v;
                v.insert(v.begin(), 100, "hello");
                ft_v.insert(ft_v.begin(), 100, "hello");
                ft_v.begin()->length();
                s = v.size();
                ft_s = ft_v.size();
                c = v.capacity();
                ft_c = ft_v.capacity();
                for (size_t i = 0; i < v.size(); ++i)
                    str += v[i];
                for (size_t i = 0; i < ft_v.size(); ++i)
                    ft_str += ft_v[i];
            }
            {
                std::vector <std::string> v;
                std::vector <std::string> ft_v;
                v.insert(v.end(), "hello");
                ft_v.insert(ft_v.end(), "hello");
                ft_v.begin()->length();
                str.clear();
                ft_str.clear();
                s = v.size();
                ft_s = ft_v.size();
                c = v.capacity();
                ft_c = ft_v.capacity();
                for (size_t i = 0; i < v.size(); ++i)
                    str += v[i];
                for (size_t i = 0; i < ft_v.size(); ++i)
                    ft_str += ft_v[i];
            }
            {
                std::vector <std::string> v(20, "string");
                std::vector <std::string> ft_v(20, "string");
                std::vector<std::string>::iterator valid_it;
                v.reserve(100);
                ft_v.reserve(100);
                valid_it = ft_v.begin();
                v.insert(v.begin() + 15, 70, "hello");
                ft_v.insert(ft_v.begin() + 15, 70, "hello");
                str.clear();
                ft_str.clear();
                s = v.size();
                ft_s = ft_v.size();
                c = v.capacity();
                ft_c = ft_v.capacity();
                for (size_t i = 0; i < v.size(); ++i)
                    str += v[i];
                for (size_t i = 0; i < ft_v.size(); ++i)
                    ft_str += ft_v[i];
            }
            {
                std::vector <std::string> v(20, "string");
                std::vector <std::string> ft_v(20, "string");
                v.insert(v.begin() + 10, 100, "hello");
                ft_v.insert(ft_v.begin() + 10, 100, "hello");
                str.clear();
                ft_str.clear();
                s = v.size();
                ft_s = ft_v.size();
                c = v.capacity();
                ft_c = ft_v.capacity();
                for (size_t i = 0; i < v.size(); ++i)
                    str += v[i];
                for (size_t i = 0; i < ft_v.size(); ++i)
                    ft_str += ft_v[i];
            }
            {
                std::vector <std::string> v(20, "string");
                std::vector <std::string> ft_v(20, "string");
                v.insert(v.begin() + 10, 15, "hello");
                ft_v.insert(ft_v.begin() + 10, 15, "hello");
                str.clear();
                ft_str.clear();
                s = v.size();
                ft_s = ft_v.size();
                c = v.capacity();
                ft_c = ft_v.capacity();
                for (size_t i = 0; i < v.size(); ++i)
                    str += v[i];
                for (size_t i = 0; i < ft_v.size(); ++i)
                    ft_str += ft_v[i];
            }
        }
        {
            std::string str, ft_str;
            std::vector<std::string>::size_type s, ft_s;
            std::vector<std::string>::size_type c, ft_c;
            {
                std::vector <std::string> v1(300, "string");
                std::vector <std::string> v;
                std::vector <std::string> ft_v;
                v.insert(v.begin(), v1.begin(), v1.end());
                ft_v.insert(ft_v.begin(), v1.begin(), v1.end());
                ft_v.begin()->length();
                s = v.size();
                ft_s = ft_v.size();
                c = v.capacity();
                ft_c = ft_v.capacity();
                for (size_t i = 0; i < v.size(); ++i)
                    str += v[i];
                for (size_t i = 0; i < ft_v.size(); ++i)
                    ft_str += ft_v[i];
            }
            {
                std::vector <std::string> v;
                std::vector <std::string> v1(300, "string");
                std::vector <std::string> ft_v;
                v.insert(v.end(), v1.begin(), v1.end());
                ft_v.insert(ft_v.end(), v1.begin(), v1.end());
                ft_v.begin()->length();
                str.clear();
                ft_str.clear();
                s = v.size();
                ft_s = ft_v.size();
                c = v.capacity();
                ft_c = ft_v.capacity();
                for (size_t i = 0; i < v.size(); ++i)
                    str += v[i];
                for (size_t i = 0; i < ft_v.size(); ++i)
                    ft_str += ft_v[i];
            }
            {
                std::vector <std::string> v1(70, "hello");
                std::vector <std::string> v(20, "string");
                std::vector <std::string> ft_v(20, "string");
                std::vector<std::string>::iterator valid_it;
                v.reserve(100);
                ft_v.reserve(100);
                valid_it = ft_v.begin();
                v.insert(v.begin() + 15, v1.begin(), v1.end());
                ft_v.insert(ft_v.begin() + 15, v1.begin(), v1.end());
                str.clear();
                ft_str.clear();
                s = v.size();
                ft_s = ft_v.size();
                c = v.capacity();
                ft_c = ft_v.capacity();
                for (size_t i = 0; i < v.size(); ++i)
                    str += v[i];
                for (size_t i = 0; i < ft_v.size(); ++i)
                    ft_str += ft_v[i];
            }
            {
                std::vector <std::string> v1(100, "hello");
                std::vector <std::string> v(20, "string");
                std::vector <std::string> ft_v(20, "string");
                v.insert(v.begin() + 10, v1.begin(), v1.end());
                ft_v.insert(ft_v.begin() + 10, v1.begin(), v1.end());
                str.clear();
                ft_str.clear();
                s = v.size();
                ft_s = ft_v.size();
                c = v.capacity();
                ft_c = ft_v.capacity();
                for (size_t i = 0; i < v.size(); ++i)
                    str += v[i];
                for (size_t i = 0; i < ft_v.size(); ++i)
                    ft_str += ft_v[i];
            }
            {
                std::vector <std::string> v1(15, "hello");
                std::vector <std::string> v(20, "string");
                std::vector <std::string> ft_v(20, "string");
                v.insert(v.begin() + 10, v1.begin(), v1.end());
                ft_v.insert(ft_v.begin() + 10, v1.begin(), v1.end());
                str.clear();
                ft_str.clear();
                s = v.size();
                ft_s = ft_v.size();
                c = v.capacity();
                ft_c = ft_v.capacity();
                for (size_t i = 0; i < v.size(); ++i)
                    str += v[i];
                for (size_t i = 0; i < ft_v.size(); ++i)
                    ft_str += ft_v[i];
            }
        }

        {
            std::string str, ft_str;
            std::vector<std::string>::size_type s, ft_s;
            std::vector<std::string>::size_type c, ft_c;
            std::vector <std::string> v(200, "hello");
            std::vector <std::string> ft_v(200, "hello");
            std::vector<std::string>::iterator valid_it;
            std::vector<std::string>::iterator it;
            std::vector<std::string>::iterator ft_it;
            valid_it = ft_v.begin() + 99;
            it = v.erase(v.begin() + 100);
            ft_it = ft_v.erase(ft_v.begin() + 100);
            ft_it->length();
            s = v.size();
            ft_s = ft_v.size();
            c = v.capacity();
            ft_c = ft_v.capacity();
            for (size_t i = 0; i < v.size(); ++i)
                str += v[i];
            for (size_t i = 0; i < ft_v.size(); ++i)
                ft_str += ft_v[i];
        }
        {
            std::string str, ft_str;
            std::vector<std::string>::size_type s, ft_s;
            std::vector<std::string>::size_type c, ft_c;
            std::vector<std::string>::iterator it;
            std::vector<std::string>::iterator ft_it;
        }
        {
            std::vector <std::string> v(200, "hello");
            std::vector <std::string> ft_v(200, "hello");

        }
        {
            {
                std::vector<int> v(100, 5);
                std::vector<int> v1(100, 5);
                std::vector<int> ft_v(100, 5);
                std::vector<int> ft_v1(100, 5);
                v[80] = 4;
                ft_v[80] = 4;
                v1[80] = 3;
                ft_v1[80] = 3;
            }

            {
                std::vector<int> v(50, 5);
                std::vector<int> v1(100, 5);
                std::vector<int> ft_v(50, 5);
                std::vector<int> ft_v1(100, 5);

                v[40] = 4;
                ft_v[40] = 4;
                v1[80] = 3;
                ft_v1[80] = 3;
            }

            {
                std::vector<int> v(100, 5);
                std::vector<int> v1(50, 5);
                std::vector<int> ft_v(100, 5);
                std::vector<int> ft_v1(50, 5);

                v[80] = 4;
                ft_v[80] = 4;
                v1[40] = 3;
                ft_v1[40] = 3;
            }
        }

        {
            {
                std::vector<int> v(100, 5);
                std::vector<int> v1(100, 5);
                std::vector<int> ft_v(100, 5);
                std::vector<int> ft_v1(100, 5);

                v[80] = 4;
                ft_v[80] = 4;
                v1[80] = 3;
                ft_v1[80] = 3;
            }

            {
                std::vector<int> v(50, 5);
                std::vector<int> v1(100, 5);
                std::vector<int> ft_v(50, 5);
                std::vector<int> ft_v1(100, 5);


                v[40] = 4;
                ft_v[40] = 4;

                v1[80] = 3;
                ft_v1[80] = 3;

            }

            {
                std::vector<int> v(100, 5);
                std::vector<int> v1(50, 5);
                std::vector<int> ft_v(100, 5);
                std::vector<int> ft_v1(50, 5);


                v[80] = 4;
                ft_v[80] = 4;

                v1[40] = 3;
                ft_v1[40] = 3;
            }
        }
        {
            {
                std::vector<int> v(100, 5);
                std::vector<int> v1(100, 5);
                std::vector<int> ft_v(100, 5);
                std::vector<int> ft_v1(100, 5);

                v[80] = 4;
                ft_v[80] = 4;
                v1[80] = 3;
                ft_v1[80] = 3;
            }
            {
                std::vector<int> v(50, 5);
                std::vector<int> v1(100, 5);
                std::vector<int> ft_v(50, 5);
                std::vector<int> ft_v1(100, 5);

                v[40] = 4;
                ft_v[40] = 4;
                v1[80] = 3;
                ft_v1[80] = 3;
            }


            {
                std::vector<int> v(100, 5);
                std::vector<int> v1(50, 5);
                std::vector<int> ft_v(100, 5);
                std::vector<int> ft_v1(50, 5);

                v[80] = 4;
                ft_v[80] = 4;
                v1[40] = 3;
                ft_v1[40] = 3;
            }
        }
        {
            {
                std::vector<int> v(100, 5);
                std::vector<int> v1(100, 5);
                std::vector<int> ft_v(100, 5);
                std::vector<int> ft_v1(100, 5);

                v[80] = 4;
                ft_v[80] = 4;
                v1[80] = 3;
                ft_v1[80] = 3;
            }


            {
                std::vector<int> v(50, 5);
                std::vector<int> v1(100, 5);
                std::vector<int> ft_v(50, 5);
                std::vector<int> ft_v1(100, 5);

                v[40] = 4;
                ft_v[40] = 4;
                v1[80] = 3;
                ft_v1[80] = 3;
            }

            {
                std::vector<int> v(100, 5);
                std::vector<int> v1(50, 5);
                std::vector<int> ft_v(100, 5);
                std::vector<int> ft_v1(50, 5);

                v[80] = 4;
                ft_v[80] = 4;
                v1[40] = 3;
                ft_v1[40] = 3;
            }
        }
        {
            {
                std::vector<int> v(100, 5);
                std::vector<int> v1(100, 5);
                std::vector<int> ft_v(100, 5);
                std::vector<int> ft_v1(100, 5);

                v[80] = 4;
                ft_v[80] = 4;
                v1[80] = 3;
                ft_v1[80] = 3;
            }

            {
                std::vector<int> v(50, 5);
                std::vector<int> v1(100, 5);
                std::vector<int> ft_v(50, 5);
                std::vector<int> ft_v1(100, 5);

                v[40] = 4;
                ft_v[40] = 4;
                v1[80] = 3;
                ft_v1[80] = 3;
            }
            {
                std::vector<int> v(100, 5);
                std::vector<int> v1(50, 5);
                std::vector<int> ft_v(100, 5);
                std::vector<int> ft_v1(50, 5);

                v[80] = 4;
                ft_v[80] = 4;
                v1[40] = 3;
                ft_v1[40] = 3;
            }
        }
        {
            {
                std::vector<int> v(100, 5);
                std::vector<int> v1(100, 5);
                std::vector<int> ft_v(100, 5);
                std::vector<int> ft_v1(100, 5);

                v[80] = 4;
                ft_v[80] = 4;
                v1[80] = 3;
                ft_v1[80] = 3;
            }
            {
                std::vector<int> v(50, 5);
                std::vector<int> v1(100, 5);
                std::vector<int> ft_v(50, 5);
                std::vector<int> ft_v1(100, 5);

                v[40] = 4;
                ft_v[40] = 4;
                v1[80] = 3;
                ft_v1[80] = 3;
            }
            {
                std::vector<int> v(100, 5);
                std::vector<int> v1(50, 5);
                std::vector<int> ft_v(100, 5);
                std::vector<int> ft_v1(50, 5);

                v[80] = 4;
                ft_v[80] = 4;
                v1[40] = 3;
                ft_v1[40] = 3;
            }
        }
    }

    {

        std::vector<int> v(3, 4);
        std::vector<int>::iterator it, it1;
        it = v.begin();
        it1 = v.begin() + 1;

        std::vector<int> my_v(3, 4);
        std::vector<int>::iterator my_it, my_it1, tmp;
        my_it = my_v.begin();
        my_it1 = my_v.begin() + 1;

        {
            std::vector<int>::iterator ob(my_it);
        }
        {
            std::vector<int>::const_iterator c_it, c_ob(my_it);
            c_it = my_it;
        }

    }

    {

        std::vector<int> v(3, 4);
        std::vector<int>::const_iterator it, it1;
        it = v.begin();
        it1 = v.begin() + 1;

        std::vector<int> my_v(3, 4);
        std::vector<int>::const_iterator my_it, my_it1, tmp;
        my_it = my_v.begin();
        my_it1 = my_v.begin() + 1;

        {
            std::vector<int>::const_iterator ob(my_it);
        }

    }

    {

        std::vector<int> v(3, 4);
        std::reverse_iterator <std::vector<int>::iterator> rit(v.end()), rit_1(v.end() - 1);

        std::reverse_iterator <std::vector<int>::iterator> my_rit(v.end()), my_rit1(v.end() - 1);

        {
            std::reverse_iterator <std::vector<int>::iterator> ob(my_rit);
        }

        {
            std::vector<int>::reverse_iterator my_rit2(v.end());
            std::vector<int>::const_reverse_iterator c_it, c_ob(v.end());
            c_it = my_rit2;
        }
        my_rit += 1;
        rit += 1;

        my_rit -= 1;
        rit -= 1;

        ++my_rit;
        ++rit;

        --my_rit;
        --rit;

        {
            std::reverse_iterator <std::vector<int>::iterator> tmp(rit++);
            std::reverse_iterator <std::vector<int>::iterator> my_tmp(my_rit++);
        }

        {
            std::reverse_iterator <std::vector<int>::iterator> tmp(rit--);
            std::reverse_iterator <std::vector<int>::iterator> my_tmp(my_rit--);
        }

    }
    std::cout << "vector tests: OK\n";

    ////////////////////////////////////////////////////////////////////////////////////
    {
        std::map<char, int> map1;
        map1['a'] = 10;
        map1['b'] = 30;
        map1['c'] = 50;
        map1['d'] = 70;
        std::map<char, int> second(map1.begin(), map1.end());
        std::map<char, int> third(second);
        std::map<char, int> sixth = third;
    }
    {
        std::map<char, int> mymap;
        std::map<char, int>::iterator itlow, itup;

        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100;

        itlow = mymap.lower_bound('b');
        mymap.erase(itlow);
        itlow = mymap.lower_bound('d');
        mymap.erase(itlow);
    }
    {
        std::map<char, int> mymap;
        std::map<char, int>::iterator itlow, itup;
        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100;
        itlow = mymap.lower_bound('b');
        itup = mymap.upper_bound('d');
        mymap.erase(itlow, itup);
    }

    {
        std::map<char, int> mymap;
        mymap.insert(std::pair<char, int>('a', 100));
        mymap.insert(std::pair<char, int>('z', 200));

        std::pair<std::map<char, int>::iterator, bool> ret;
        ret = mymap.insert(std::pair<char, int>('z', 500));

        std::map<char, int>::iterator it = mymap.begin();
        mymap.insert(it, std::pair<char, int>('b', 300));
        mymap.insert(it, std::pair<char, int>('c', 400));

        std::map<char, int> anothermap;
        anothermap.insert(mymap.begin(), mymap.find('c'));
    }
    {
        std::map<char, int> foo, bar;
        foo['x'] = 100;
        foo['y'] = 200;
        bar['a'] = 11;
        bar['b'] = 22;
        bar['c'] = 33;
        foo.swap(bar);
    }
    {
        std::map<char, int> mymap;
        std::map<char, int>::iterator it;
        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;
        mymap['d'] = 40;
        mymap['e'] = 50;
        mymap['f'] = 60;
        it = mymap.find('b');
        mymap.erase(it);
        mymap.erase('c');
        it = mymap.find('e');
        mymap.erase(it, mymap.end());

    }
    {
        std::map<char, int> mymap;
        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;

        std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> ret;
        ret = mymap.equal_range('b');

    }
    {
        std::map<char, int> mymap;
        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;

        while (!mymap.empty()) {
            mymap.erase(mymap.begin());
        }
    }

    {
        std::map<char, int> mymap;
        mymap['a'] = 101;
        mymap['b'] = 202;
        mymap['c'] = 302;
        mymap.size();

    }

    {
        int psize;
        std::map<char, int> mymap;
        std::pair<const char, int> *p;

        p = mymap.get_allocator().allocate(5);
        psize = sizeof(std::map<char, int>::value_type) * 5;
        mymap.get_allocator().deallocate(p, 5);
    }
    {
        std::map<char, int> map1;
        map1['a'] = 10;
        map1['b'] = 30;
        map1['c'] = 50;
        map1['d'] = 70;
        std::map<char, int> second(map1.begin(), map1.end());
    };

    {
        std::map<char, int> mymap;
        std::map<char, int>::iterator it;

        mymap['a'] = 50;
        mymap['b'] = 100;
        mymap['c'] = 150;
        mymap['d'] = 200;

        it = mymap.find('b');
        if (it != mymap.end())
            mymap.erase(it);
    }
    {
        std::pair<int, char> mypair;
        mypair.first = 1;
        mypair.second = 'a';
        std::pair<int, int> foo;
        std::pair<int, int> bar;
        foo = std::make_pair(1, 2);
        bar = std::make_pair(3, 4);
        std::map<int, int> map;
        map.insert(std::pair<int, int>(1, 10));
        map.insert(std::pair<int, int>(-2, -20));
        map.insert(std::pair<int, int>(0, 0));
        map.insert(std::pair<int, int>(1, -20));
        std::map<int, int>::iterator it = map.begin();
        std::map<int, int>::iterator ite = map.end();
        int check = (*it).first;
        while (it != ite) {
            check = (*it).first;
            it++;
        }
        std::map<int, int> map1;
        map1.insert(bar);
        std::map<int, int>::iterator it1 = map1.begin();
        std::map<int, int> map2;
        map2.insert(foo);
        std::map<int, int>::iterator it2 = map2.begin();
        std::swap(map1, map2);
    };
    ///////////////////////////////////////////////////////////////////////////////////////


    {
        ft::stack<int> myints;
        for (int i = 0; i < 5; i++)
            myints.push(i);

        myints.pop();
        ft::stack<int> container;
        for (int i = 0; i < 7; ++i)
            container.push(i);

    }
    {
        ft::stack<int> mystack;
        mystack.push(10);
        mystack.push(20);
        mystack.top() -= 5;
        std::stack<int> s;
        s.push(2);
        s.push(6);
        s.push(51);
        s.pop();

    }
    {
        ft::stack<int> mystack;
        for (int i = 0; i < 5; ++i)
            mystack.push(i);
        while (!mystack.empty()) {
            mystack.pop();
        }
    }
    {
        ft::stack<int> c1;
        c1.push(5);
        ft::vector<int> vec;
        ft::stack<int> c2(vec);
        c2.push(1);
        c2.push(2);
        ft::stack<int, std::deque<int> > c3;
        c3.push(1);
        c3.push(2);
    }
    std::cout << "ok\n";

    {
        std::map<char, int> map1;
        map1['a'] = 10;
        map1['b'] = 30;
        map1['c'] = 50;
        map1['d'] = 70;
        std::map<char, int> second(map1.begin(), map1.end());
        std::map<char, int> third(second);
        std::map<char, int> sixth = third;
    }
    {
        std::map<char, int> mymap;
        std::map<char, int>::iterator itlow, itup;

        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100;

        itlow = mymap.lower_bound('b');
        mymap.erase(itlow);
        itlow = mymap.lower_bound('d');
        mymap.erase(itlow);
    }
    {
        std::map<char, int> mymap;
        std::map<char, int>::iterator itlow, itup;
        mymap['a'] = 20;
        mymap['b'] = 40;
        mymap['c'] = 60;
        mymap['d'] = 80;
        mymap['e'] = 100;
        itlow = mymap.lower_bound('b');
        itup = mymap.upper_bound('d');
        mymap.erase(itlow, itup);
    }

    {
        std::map<char, int> mymap;
        mymap.insert(std::pair<char, int>('a', 100));
        mymap.insert(std::pair<char, int>('z', 200));

        std::pair<std::map<char, int>::iterator, bool> ret;
        ret = mymap.insert(std::pair<char, int>('z', 500));

        std::map<char, int>::iterator it = mymap.begin();
        mymap.insert(it, std::pair<char, int>('b', 300));
        mymap.insert(it, std::pair<char, int>('c', 400));

        std::map<char, int> anothermap;
        anothermap.insert(mymap.begin(), mymap.find('c'));
    }
    {
        std::map<char, int> foo, bar;
        foo['x'] = 100;
        foo['y'] = 200;
        bar['a'] = 11;
        bar['b'] = 22;
        bar['c'] = 33;
        foo.swap(bar);
    }
    {
        std::map<char, int> mymap;
        std::map<char, int>::iterator it;
        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;
        mymap['d'] = 40;
        mymap['e'] = 50;
        mymap['f'] = 60;
        it = mymap.find('b');
        mymap.erase(it);
        mymap.erase('c');
        it = mymap.find('e');
        mymap.erase(it, mymap.end());

    }
    {
        std::map<char, int> mymap;
        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;

        std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> ret;
        ret = mymap.equal_range('b');

    }
    {
        std::map<char, int> mymap;
        mymap['a'] = 10;
        mymap['b'] = 20;
        mymap['c'] = 30;

        while (!mymap.empty()) {
            mymap.erase(mymap.begin());
        }
    }

    {
        std::map<char, int> mymap;
        mymap['a'] = 101;
        mymap['b'] = 202;
        mymap['c'] = 302;
        mymap.size();

    }

    {
        int psize;
        std::map<char, int> mymap;
        std::pair<const char, int> *p;

        p = mymap.get_allocator().allocate(5);
        psize = sizeof(std::map<char, int>::value_type) * 5;
        mymap.get_allocator().deallocate(p, 5);
    }
    {
        std::map<char, int> map1;
        map1['a'] = 10;
        map1['b'] = 30;
        map1['c'] = 50;
        map1['d'] = 70;
        std::map<char, int> second(map1.begin(), map1.end());
    };

    {
        std::map<char, int> mymap;
        std::map<char, int>::iterator it;

        mymap['a'] = 50;
        mymap['b'] = 100;
        mymap['c'] = 150;
        mymap['d'] = 200;

        it = mymap.find('b');
        if (it != mymap.end())
            mymap.erase(it);
    }
    {
        std::pair<int, char> mypair;
        mypair.first = 1;
        mypair.second = 'a';
        std::pair<int, int> foo;
        std::pair<int, int> bar;
        foo = std::make_pair(1, 2);
        bar = std::make_pair(3, 4);
        std::map<int, int> map;
        map.insert(std::pair<int, int>(1, 10));
        map.insert(std::pair<int, int>(-2, -20));
        map.insert(std::pair<int, int>(0, 0));
        map.insert(std::pair<int, int>(1, -20));
        std::map<int, int>::iterator it = map.begin();
        std::map<int, int>::iterator ite = map.end();
        int check = (*it).first;
        while (it != ite) {
            check = (*it).first;
            it++;
        }
        std::map<int, int> map1;
        map1.insert(bar);
        std::map<int, int>::iterator it1 = map1.begin();
        std::map<int, int> map2;
        map2.insert(foo);
        std::map<int, int>::iterator it2 = map2.begin();
        std::swap(map1, map2);
    };
    std::cout << "tests map: OK\n";
    return 0;
}
