/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test-vector.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 03:34:44 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/01 17:1 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <climits>

#define _MAX_TEST_SIZE 10
#define _NTESTS 8000

#ifndef _NAMESPACE
#define _NAMESPACE ft
#endif

static int test_no = 0;
static int main_test_no = 0;

namespace _test
{
    /**
     * @brief PRINT VECTOR
     */
    template <typename _vector>
    void test_print(const _vector &v)
    {
        std::cout << "empty : " << v.empty() << std::endl;
        std::cout << "size : " << v.size() << std::endl;
        // std::cout << "capacity : " << v.capacity() << std::endl;
        // std::cout << "max size : " << v.max_size() << std::endl;
        if (!v.empty())
        {
            std::cout << "front : " << v.front() << std::endl;
            std::cout << "back : " << v.back() << std::endl;
            std::cout << "content : " << std::endl;
            for (typename _vector::const_iterator it = v.begin(); it != v.end(); it++)
                std::cout << *it << std::endl;
            std::cout << "reverse content : " << std::endl;
            for (typename _vector::const_reverse_iterator it = v.rbegin(); it != v.rend(); it++)
                std::cout << *it << std::endl;
        }
    }

    /**
     * @brief Template overload RDM_VAL
     */
    template <typename _Type>
    _Type rdm_val()
    {
        return (_Type());
    }
    /**
     * @brief Generate a random string
     */
    template <>
    std::string rdm_val<std::string>()
    {
        std::string default_val[18] =
            {
                "This is a test",
                "there are many tests",
                "all tests should pass",
                "Lorem ipsum dolor sit amet",
                "consectetur adipiscing elit.",
                "Phasellus ut rutrum ante.",
                "Sed vehicula tellus eu erat",
                "congue dictum. Fusce a ultrices",
                "",
                "magna. Morbi fringilla ullamcorper",
                "nisi id scelerisque.",
                "Curabitur elementum enim",
                "a mi vestibulum eleifend.",
                "Pellentesque eget risus efficitur",
                "euismod mi ut, tristique lorem.",
                "Praesent ullamcorper venenatis augue,",
                "\t",
                "eget pretium velit vehicula et."};
        return (std::string(default_val[std::rand() % 18]));
    }

    /**
     * @brief Generate a random UINT
     *
     */
    template <>
    int rdm_val<int>()
    {
        return (int(std::rand() % UINT_MAX));
    }

    /********
     * @brief   TEST SUITE FOR VECTOR
     * @tparam _vector  vector class
     */

    /**
     * @brief CONSTRUCTORS
     */
    template <typename _vector>
    void test_constructors(_vector &x, _vector &y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - CONSTRUCTORS" << std::endl;
        x = _vector(std::rand() % _MAX_TEST_SIZE, rdm_val<typename _vector::value_type>());
        test_print(x);
        y = _vector(x.begin(), x.end());
        test_print(x);
        _vector z(std::rand() % _MAX_TEST_SIZE, rdm_val<typename _vector::value_type>());
        test_print(z);
    }

    /**
     * @brief TEST COPY CONSTRUCTOR
     */
    template <typename _vector>
    void test_copy(_vector &x, _vector &y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - COPY CONSTRUCTOR" << std::endl;
        _vector z(x);
        _vector w(y);
        test_print(x);
        test_print(w);
        test_print(z);
    }

    /**
     * @brief TEST OPERATOR =
     */
    template <typename _vector>
    void test_assign_op(_vector &x, _vector &y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - OPERATOR=" << std::endl;
        _vector Z = x;
        y = Z;
        test_print(x);
        test_print(y);
        test_print(Z);
        x = _vector(Z);
        test_print(x);
        y = Z;
        test_print(y);
        y = _vector(Z);
        test_print(y);
    }

    /**
     * @brief TEST MIXED OP = and COPY
     */
    template <typename _vector>
    void test_mixed_assign_copy(_vector &x, _vector &y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - MIXED BASIC" << std::endl;
        _vector Z(x);
        Z = x;
        test_print(Z);
        x = Z;
        x = y;
        y = Z;
        test_print(x);
        test_print(y);
        test_print(Z);
    }

    /**
     * @brief TEST INSERT
     */

    template <typename _vector>
    void test_insert(_vector &x, _vector &y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - INSERT" << std::endl;
        typename _vector::iterator it;
        if (!x.empty())
            it = x.begin() + std::rand() % x.size();
        else
        {
            it = x.end();
            try
            {
                switch (std::rand() % 3)
                {
                case (0):
                    std::cout << *x.insert(it, rdm_val<typename _vector::value_type>()) << std::endl;
                    break;
                case (1):
                    if (!x.empty() && !y.empty())
                        y.insert(y.begin() + (std::rand() % y.size()), it, it + (std::rand() % (x.size() - (it - x.begin()))));
                    else if (!y.empty())
                        y.insert(y.begin() + (std::rand() % y.size()), it, x.end());
                    else
                        y.insert(y.begin(), it, x.end());
                    break;
                case (2):
                    if (!y.empty())
                        y.insert(y.begin(), (std::rand() % y.size()), rdm_val<typename _vector::value_type>());
                    else
                        y.insert(y.begin(), std::rand() % 5, rdm_val<typename _vector::value_type>());
                }
            }
            catch (std::exception &error)
            {
                std::cout << error.what() << std::endl;
            }
        }
        test_print(x);
    }
    /**
     * @brief TEST VECTOR ASSIGN
     */
    template <typename _vector>
    void test_assign(_vector &X, _vector &Y)
    {
        _vector Z;
        std::cout << "TEST : " << test_no++;
        std::cout << " - ASSIGN" << std::endl;
        switch (std::rand() % 4)
        {
            case (0) :
                Z.assign(0, rdm_val<typename _vector::value_type>());
            case (1) :
                Z.assign(std::rand() % _MAX_TEST_SIZE, rdm_val<typename _vector::value_type>());
            case (2) :
                Z.assign(Y.begin(), Y.end());
            case (3) :
                if (!Y.empty())
                    Z.assign(Y.begin() + (std::rand() % Y.size()), Y.end());
            case (4) :
                if (!Y.empty())
                    Z.assign(Y.begin(), Y.end() - (std::rand() % Y.size()));
        }
        test_print(Z);
        test_print(X);
        test_print(Y);
    }
    
    template <typename _vector>
    void test_push(_vector &X, _vector &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - PUSH_BACK" << std::endl;
        switch (std::rand() % 3)
        {
            case (0) :
                for (int i = 0; i < std::rand() % _MAX_TEST_SIZE; i++)
                    X.push_back(rdm_val<typename _vector::value_type>());
            case (1) :
                for (int i = 0; i < std::rand() % _MAX_TEST_SIZE; i++)
                    Y.push_back(rdm_val<typename _vector::value_type>());
            case (2) :
                _vector Z;
                Z.push_back(rdm_val<typename _vector::value_type>());
                test_print(Z);
        }
        test_print(X);
        test_print(Y);
    }

#define _LESS_SIZE(X) (X.size() - (std::rand() % X.size()))

    template <typename _vector>
    void test_pop(_vector &X, _vector &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - POP" << std::endl;
        switch (std::rand() % 2)
        {
            case (0) :
                if (!X.empty())
                    for (size_t i = 0; i < X.size(); i++)
                        X.pop_back();
            case (1) :
                if (!Y.empty())
                    for (size_t i = 0; i < Y.size(); i++)
                        Y.pop_back();
        }
        test_print(X);
        test_print(Y);
    }
    
    template <typename _vector>
    void test_erase(_vector &X, _vector &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - ERASE" << std::endl;
        typename _vector::iterator pos;
        switch (std::rand() % 4)
        {
            case (0) :
                if (!X.empty())
                    X.erase(X.begin());
            case (1) :
                if (!X.empty())
                    X.erase(X.end() - 1);
            case (2) :
                if (!X.empty() && X.size() > 1)
                {   
                    pos = X.begin() + (std::rand() % X.size());
                    X.erase(X.begin(), pos);
                }
            case (3) :
                if (!Y.empty() && Y.size() > 1)
                {
                    pos = Y.begin() + (std::rand() % Y.size());
                    Y.erase(Y.begin(), pos);
                }
        }
        test_print(X);
        test_print(Y);
    }
}

#define _DEFAULT_CONSTRUCTOR 0
#define _COPY_CONSTRUCTOR 1
#define _ASSIGNMENT_OP 2
#define _MIXED_0_3 3
#define _INSERT 4
#define _ASSIGN 5
#define _PUSH 6
#define _POP 7
#define _ERASE 8

#define _TEST 8

template <class _vector>
void test_vector(int rdm_seed)
{
    std::srand(rdm_seed);
    void (*_testArray[])(_vector &, _vector &) =
        {
            &_test::test_constructors,
            &_test::test_copy,
            &_test::test_assign_op,
            &_test::test_mixed_assign_copy,
            &_test::test_insert,
            &_test::test_assign,
            &_test::test_push,
            &_test::test_pop,
            //&_test::test_erase
        };

    _vector X;
    _vector Y;
    for (int i = 0; i < _NTESTS; i++)
    {
        std::cout << "MAIN TEST : " << main_test_no++ << std::endl;
        switch (std::rand() % _TEST)
        {
        case (_DEFAULT_CONSTRUCTOR):
            if (std::rand() % 2)
                _testArray[_DEFAULT_CONSTRUCTOR](X, Y);
            else
                _testArray[_DEFAULT_CONSTRUCTOR](Y, X);
            break;
        case (_COPY_CONSTRUCTOR):
            if (std::rand() % 2)
                _testArray[_COPY_CONSTRUCTOR](X, Y);
            else
                _testArray[_COPY_CONSTRUCTOR](Y, X);
            break;
        case (_ASSIGNMENT_OP):
            if (std::rand() % 2)
                _testArray[_ASSIGNMENT_OP](X, Y);
            else
                _testArray[_ASSIGNMENT_OP](Y, X);
            break;
        case (_MIXED_0_3) :
            if (std::rand() % 2)
                _testArray[_MIXED_0_3](X, Y);
            else
            _testArray[_MIXED_0_3](Y, X);
            break;
        case (_INSERT):
            if (std::rand() % 2)
                _testArray[_INSERT](X, Y);
            else
                _testArray[_INSERT](Y, X);
            break;
        case (_ASSIGN):
            if (std::rand() % 2)
                _testArray[_ASSIGN](X, Y);
            else
                _testArray[_ASSIGN](Y, X);
            break;
        case (_PUSH):
            if (std::rand() % 2)
                _testArray[_PUSH](X, Y);
            else
                _testArray[_PUSH](Y, X);
            break;
        case (_POP):
            if (std::rand() % 2)
                _testArray[_POP](X, Y);
            else
                _testArray[_POP](Y, X);
            break;
         case (_ERASE):
            if (std::rand() % 2)
                _testArray[_ERASE](X, Y);
            else
                _testArray[_ERASE](Y, X);
            break;
        }
        _test::test_print(X);
        _test::test_print(Y);
    }
}

int main(void)
{
    int seed = 18;
    test_vector<_NAMESPACE::vector<std::string> >(seed);

    return 0;
}