/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test-rbt.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:54:28 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/13 12:53:13 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_red_black_tree.hpp"
#include "vector.hpp"

int main(void)
{
    ft::_rbtree<int> tree;

    tree._insert_node(5);
    std::cout << tree << std::endl;
    std::cout << "ADD 10" << std::endl;
    tree._insert_node(10);
    std::cout << "ADD 12" << std::endl;
    tree._insert_node(12);
    std::cout << tree << std::endl;
    std::cout << "ADD 8" << std::endl;
    tree._insert_node(8);
    tree._insert_node(3);
    tree._insert_node(14);
    std::cout << tree << std::endl;

    return 0;
}