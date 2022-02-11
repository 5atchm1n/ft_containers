/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_rotations.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:07:08 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/11 15:11:12 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_red_black_tree.hpp"

namespace ft {

template <typename _Tp, typename _Alloc>
void
_rbtree<_Tp, _Alloc>::_rbtree_rotate_left(node_type *current)
{
    node_type   *tmp = current->right;
    
    current->right = tmp->left;
    if (tmp->left != _nil)
        tmp->left->parent = current;
    tmp->parent = current->parent;
    if (current == _root)
        _root = tmp;
    else if (current == current->parent->left)
        current->parent->left = tmp;
    else
        current->parent->right = tmp;
    tmp->left = current;
    current->parent = tmp;
}

template <typename _Tp, typename _Alloc>
void
_rbtree<_Tp, _Alloc>::_rbtree_rotate_right(node_type *current)
{
    node_type   *tmp= current->left;
    current->left = tmp->right;
    if (tmp->right != _nil)
        tmp->right->parent = current;
    tmp->parent = current->parent;
    if (current == _root)
        _root = tmp;
    else if (current == current->parent->right)
        current->parent->right = tmp;
    else
        current->parent->left = tmp;
    tmp->right = current;
    current->parent = tmp;
}

template <typename _Tp, typename _Alloc>
void
_rbtree<_Tp, _Alloc>::_rotate(node_pointer node)
{
    if (node->parent->left == node)
    {
        if (node->parent->parent->left == node->parent)
        {
            _rbtree_rotate_right(node->parent->parent);
            node->isred = true;
            node->parent->isred = true;
            if (node->parent->right != _nil)
                node->parent->right->isred = true;
            return ;
        }
        _right_left_rotate(node->parent->parent);
        node->isred = false;
        node->right->isred = true;
        node->left->isred = true;
        return ;
    }
}

template <typename _Tp, typename _Alloc>
void
_rbtree<_Tp, _Alloc>::_right_left_rotate(node_pointer node)
{
    _rbtree_rotate_left(node->left);
    _rbtree_rotate_right(node); 
}

}