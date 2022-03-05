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
#define _NTESTS 1000

#ifndef _NAMESPACE
#define _NAMESPACE ft
#endif

static int test_no = 0;
static int main_test_no = 0;

#include "vector_test/_test_tools.hpp"
#include "vector_test/_test_basic.hpp"
#include "vector_test/_test_modify.hpp"


#define _DEFAULT_CONSTRUCTOR 0
#define _COPY_CONSTRUCTOR 1
#define _ASSIGNMENT_OP 2
#define _MIXED_0_3 3
#define _INSERT 4
#define _ASSIGN 5
#define _PUSH 6
#define _POP 7
#define _ERASE 8

#define _TEST 9

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
            &_test::test_erase
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

#define MAX_SEED 10

int main(void)
{
    int seed = 55;
    for (int i = 0; i < MAX_SEED; i++)
        test_vector<_NAMESPACE::vector<std::string> >(seed++);
    return 0;
}