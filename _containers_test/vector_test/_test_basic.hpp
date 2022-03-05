/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_basic.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:07:29 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/05 15:17:55 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_tools.hpp"

#ifndef _VECTOR_TEST_BASIC_HPP
#define _VECTOR_TEST_BASIC_HPP

namespace _test
{

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

}


#endif  //_VECTOR_TEST_BASIC_HPP