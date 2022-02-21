/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_rotations.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 15:07:08 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/21 02:05:02 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_red_black_tree.hpp"

namespace ft {

template <typename _Tp, typename _Cmp, typename _Alloc>
void
_rbtree<_Tp, _Cmp, _Alloc>::_rbtree_rotate_left(node_type *_x)
{
    node_pointer   _y = _x->right;
    _x->right = _y->left;
    if (_y->left != _nil)
        _y->left->parent = _x;
    _y->parent = _x->parent;
    if (_x->parent == _nil)
        _root = _y;
    else if (_x == _x->parent->left)
        _x->parent->left = _y;
    else
        _x->parent->right = _y;
    _y->left = _x;
    _x->parent = _y;
}

template <typename _Tp, typename _Cmp, typename _Alloc>
void
_rbtree<_Tp, _Cmp, _Alloc>::_rbtree_rotate_right(node_type *_x)
{
    node_pointer   _y = _x->left;
    _x->left = _y->right;
    if (_y->right != _nil)
        _y->right->parent = _x;
    _y->parent = _x->parent;
    if (_x->parent == _nil)
        _root = _y;
    else if (_x == _x->parent->right)
        _x->parent->right = _y;
    else
        _x->parent->left = _y;
    _y->right = _x;
    _x->parent = _y;
}

}