/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_modify.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:46 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/08 11:45:23 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_tools.hpp"

#ifndef _MAP_TEST_MODIFY_HPP
#define _MAP_TEST_MODIFY_HPP

namespace _test
{

        /**
     * @brief TEST INSERT
     */
    
    template <typename _map>
    void test_insert(_map &X, _map &Y)
    {
        std::cout << "TEST : " << test_no++;
        std::cout << " - INSERT" << std::endl;
        typename _map::iterator it;

        typedef typename _NAMESPACE::pair<typename _map::key_type, typename _map::mapped_type> pair_type;
        typedef typename _NAMESPACE::pair< typename _map::iterator, bool>   pair_return;
        
        pair_return     ret; 
        pair_type       value;
        try
        {
            switch (std::rand() % 4)
            {
                case (0):
                    for (int i = 0; i < std::rand() % _MAX_TEST_SIZE; i++)
                    {
                        ret = X.insert(rdm_val<typename _map::value_type>());
                        std::cout << "key :" << ret.first->first << std::endl;
                        std::cout << " value : " << ret.first->second << std::endl;
                        std::cout << "already in :" << ret.second << std::endl;
                    }
                    break;
                case (1):
                    if (!X.empty())
                        std::cout << (X.insert(*(X.begin()))).second << std::endl;
                    if (!Y.empty())
                        std::cout << (X.insert(*(--(X.end())))).second << std::endl;
                    break;
                case (2):
                    if (!Y.empty())
                        X.insert(Y.begin(), --(Y.end()));
                    if (!X.empty())
                        Y.insert(X.begin(), X.end());
                    break;
                case (3):
                    if (!Y.empty())
                    {
                        typename _map::key_type test;
                        it = Y.begin();
                        test = it->first;
                        for (int k = 0; k < std::rand() % _MAX_TEST_SIZE; k++)
                        {
                            value = _NAMESPACE::make_pair(test, rdm_val<typename _map::mapped_type>());
                            it = Y.insert(it, value);
                            test++;
                        }
                    }
            }
            test_print(X);
            test_print(Y);
        }
        catch (std::exception &error)
        {
            std::cout << error.what() << std::endl;
        }
    }
    
    template <typename _map>
    void test_erase(_map &X, _map &Y)
    {
        (void)X;
        (void)Y;
        std::cout << "TEST : " << test_no++;
        std::cout << " - ERASE" << std::endl;
    }

    template <typename _map>
    void
    test_clear(_map &X, _map &Y)
    {
        (void)X;
        (void)Y;
        std::cout << "TEST : " << test_no++;
        std::cout << " - CLEAR" << std::endl;
    }
    
}

#endif  // _map_TEST_MODIFY_HPP