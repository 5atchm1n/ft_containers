/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _test-rbt.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 01:54:28 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/09 02:28:46 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_red_black_tree.hpp"
#include "vector.hpp"

int main(void)
{
    ft::_rbtree<ft::vector<int> > tree;

    //ft::_rb_node<int> node;
    
    //std::cout << node << std::endl;
    std::cout << tree << std::endl;

    return 0;
}