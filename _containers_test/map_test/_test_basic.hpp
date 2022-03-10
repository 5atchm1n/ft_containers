/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_basic.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:07:29 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/10 04:52:39 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_tools.hpp"

#ifndef _MAP_TEST_BASIC_HPP
#define _MAP_TEST_BASIC_HPP

namespace _test
{

    /********
     * @brief   TEST SUITE FOR VECTOR
     * @tparam _vector  vector class
     */

    /**
     * @brief CONSTRUCTORS
     */
    template <typename _map>
    void test_constructors(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - CONSTRUCTORS" << std::endl;
        _map Z;
        for (int i = 0 ; i < _MAX_TEST_SIZE; i++)
            Z.insert(rdm_val<typename _map::value_type>());
        test_print(Z);
        _map W(Z.begin(),Z.end());
        test_print(W);
        _map U(Z);
        test_print(U);
        X = U;
        Y = W;
    }

    /**
     * @brief TEST COPY CONSTRUCTOR
     */
    template <typename _vector>
    void test_relational_op(_vector &X, _vector &Y)
    {
        (void)X;
        (void)Y;
        std::cout << "TEST : " << test_no++;
        std::cout << " - RELATIONAL OPERATORS" << std::endl;
    }

}


#endif  //_VECTOR_TEST_BASIC_HPP