/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_rotations.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:07:08 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/18 12:42:16 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_red_black_tree.hpp"

namespace ft {

template <typename _Tp, typename _Cmp, typename _Alloc>
void
_rbtree<_Tp, _Cmp, _Alloc>::_rbtree_rotate_left(node_type *current)
{
    node_pointer   tmp = current->right;
    current->right = tmp->left;
    if (tmp->left != _nil)
        tmp->left->parent = current;
    tmp->parent = current->parent;
    if (current->parent == _nil)
        _root = tmp;
    else if (current == current->parent->left)
        current->parent->left = tmp;
    else
        current->parent->right = tmp;
    tmp->left = current;
    current->parent = tmp;
}

template <typename _Tp, typename _Cmp, typename _Alloc>
void
_rbtree<_Tp, _Cmp, _Alloc>::_rbtree_rotate_right(node_type *current)
{
    node_pointer   tmp = current->left;
    current->left = tmp->right;
    if (tmp->right != _nil)
        tmp->right->parent = current;
    tmp->parent = current->parent;
    if (current->parent == _nil)
        _root = tmp;
    else if (current == current->parent->right)
        current->parent->right = tmp;
    else
        current->parent->left = tmp;
    tmp->right = current;
    current->parent = tmp;
}

}