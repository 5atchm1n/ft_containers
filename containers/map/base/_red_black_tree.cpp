/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _red_black_tree.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:15:26 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/08 17:39:15 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <_red_black_tree.hpp>

namespace ft {

template <typename _Tp, typename _Alloc>
_rbtree<_Tp, _Alloc>::_rbtree()
{
    _root = _node_alloc.allocate(SINGLE_TREE);
}

template <typename _Tp, typename _Alloc>
_rbtree<_Tp, _Alloc>::~_rbtree()
{
    _node_alloc.deallocate(_root, SINGLE_TREE);
}

template <typename _Tp, typename _Alloc>
void
_rbtree<_Tp, _Alloc>::_rbtree_rotate_left(const node_type *current)
{
    node_type   *tmp = current->right;
    
    current->right = tmp->left;
    if (tmp->left != NULL)
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
_rbtree<_Tp, _Alloc>::_rbtree_rotate_right(const node_type *current)
{
    node_type   *tmp= current->left;
    current->left = tmp->right;
    if (tmp->right != NULL)
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

}   // END NAMESPACE FT