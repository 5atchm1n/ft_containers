/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_traversal.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 01:34:31 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/16 17:14:14 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_red_black_tree.hpp"

namespace ft
{

template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::node_pointer
_rbtree<_Tp, _Cmp, _Alloc>::_increment(node_pointer node)
{
    if (node->right != _nil)
    {
        node = node->right;
        while (node->left != _nil)
            node = node->left;
    }
    else
    {
        node_pointer tmp = node->parent;
        while (node != tmp->right)
        {
            node = tmp;
            tmp = tmp->right;
        }
        if (node->right != tmp)
            node = tmp;
    }
    return node;
}

template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::node_pointer
_rbtree<_Tp, _Cmp, _Alloc>::_decrement(node_pointer node)
{
    if (node->isred == true && node->parent->parent == node)
        node = node->right;
    else if (node->left != _nil)
    {
        node_pointer tmp = node->left;
        while (tmp->right != _nil)
            tmp = tmp->right;
        node = tmp;
    }
    else
    {
        node_pointer tmp = node->parent;
        while (node != tmp->left)
        {
            node = tmp;
            tmp = tmp->parent;
        }
        node = tmp;
    }
    return node;
}

}   // END NAMESPACE FT