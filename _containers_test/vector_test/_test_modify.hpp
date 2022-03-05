/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_modify.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:19:46 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/05 15:23:03 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_test_tools.hpp"

#ifndef _VECTOR_TEST_MODIFY_HPP
#define _VECTOR_TEST_MODIFY_HPP

namespace _test
{

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

#endif  // _VECTOR_TEST_MODIFY_HPP