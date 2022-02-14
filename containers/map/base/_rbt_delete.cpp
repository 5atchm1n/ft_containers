/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_delete.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 12:32:29 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/14 14:54:13 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_red_black_tree.hpp"

namespace ft
{

template <typename _Tp, typename _Alloc>
void
_rbtree<_Tp, _Alloc>::_rbtree_transplant(node_pointer node_a, node_pointer node_b)
{
    if (node_a->parent == _nil)
        _root = node_b;
    else if (node_a == node_a->parent->left)
        node_a->parent->left = node_b;
    else
        node_a->parent->right = node_b;
    node_b->parent = node_a->parent;
}

template <typename _Tp, typename _Alloc>
void
_rbtree<_Tp, _Alloc>::_delete_node(node_pointer node)
{
    node_pointer tmp_x;
    node_pointer tmp_y;
    tmp = node;
    bool node_isred = tmp_y->isred;
    if (node->left == _nil)
    {
        tmp_x = node->right;
        _rbtree_transplant(node, node->right);
    }
    else if (node->right == _nil)
    {
        tmp_x = node->left;
        _rbtree_transplant(node, node->left);
    }
    else
    {
        tmp_y = _rbtree_minimum(node->right);
        node_isred = tmp_y->isred;
        tmp_x = tmp_y->right;
        if (tmp_y== node)
            tmp_x->parent = tmp_y;
        else
        {
            _rbtree_transplant(tmp_y, tmp_y->right);
            tmp_y->right = node->right;
            tmp_y->right->parent = tmp_y;
        }
        _rbtree_transplant(node, tmp_y);
        tmp_y->left = node->left;
        tmp_y->left->parent = tmp_y;
        tmp_Y->isred = node->isred;
    }
    if (node_isred == false)
        _delete_node_fix(tmp_x);
}

}   // END NAMESPACE FT