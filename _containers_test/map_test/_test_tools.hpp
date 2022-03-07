/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test_tools.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:08:25 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/07 17:18:38 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <climits>

#ifndef _MAP_TEST_TOOLS_HPP
#define _MAP_TEST_TOOLS_HPP

namespace _test
{
    /**
     * @brief PRINT VECTOR
     */
    template <typename _map>
    void test_print(const _map &M)
    {
        std::cout << "empty : " << M.empty() << std::endl;
        std::cout << "size : " << M.size() << std::endl;
        // std::cout << "capacity : " << v.capacity() << std::endl;
        // std::cout << "max size : " << v.max_size() << std::endl;
        if (!M.empty())
        {
            std::cout << "content : " << std::endl;
            for (typename _map::const_iterator it = M.begin(); it != M.end(); it++)
                std::cout << it->first << " => " << it->second << std::endl;
        //    std::cout << "reverse content : " << std::endl;
        //    for (typename _vector::const_reverse_iterator it = v.rbegin(); it != v.rend(); it++)
        //        std::cout << it->first << " => " << it->second << std::endl;
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

    template <>
    std::pair<const int, std::string>
    rdm_val<std::pair<const int, std::string> >()
    {
        return std::pair<const int, std::string>(rdm_val<int>(), rdm_val<std::string>());
    }
    
    template <>
    ft::pair<const int, std::string>
    rdm_val<ft::pair<const int, std::string> >()
    {
        return ft::pair<const int, std::string>(rdm_val<int>(), rdm_val<std::string>());
    }
}

#endif  //_MAP_TEST_TOOLS_HPP