/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test-rbt.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:54:28 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/11 15:16:07 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_red_black_tree.hpp"
#include "vector.hpp"

int main(void)
{
    ft::_rbtree<int> tree;
    std::cout << tree << std::endl;

    tree._insert_node(5);
    std::cout << tree << std::endl;
    tree._insert_node(10);
    tree._insert_node(12);
    tree._insert_node(8);
    std::cout << tree << std::endl;

    return 0;
}