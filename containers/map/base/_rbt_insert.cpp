/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_insert.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:20:06 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/13 21:21:18 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_red_black_tree.hpp"

namespace ft
{
/**
 * @brief create and initialize new node
 */
template <typename _Tp, typename _Alloc>
typename _rbtree<_Tp, _Alloc>::node_pointer
_rbtree<_Tp, _Alloc>::_create_node(const value_type &val)
{
    node_pointer new_node;
    new_node = _node_alloc.allocate(SINGLE_NODE);
    new_node->data = _data_alloc.allocate(SINGLE_NODE);
    _data_alloc.construct(new_node->data, val);
    return new_node;
}
/**
 * @brief insert node into tree
 */
template <typename _Tp, typename _Alloc>
void
_rbtree<_Tp, _Alloc>::_insert_node(const value_type &val)
{
    node_pointer new_node = _create_node(val);
    node_pointer y = _nil;
    node_pointer x = _root;
    while (x != _nil)
    {
        y = x;
        if (*new_node->data < *x->data)
            x = x->left;
        else
            x = x->right;
    }
    new_node->parent = y;
    if (y == _nil)
        _root = new_node;
    else if (*new_node->data < *y->data)
        y->left = new_node;
    else
        y->right = new_node;
    new_node->left = _nil;
    new_node->right = _nil;
    new_node->isred = true;
    _insert_node_fix(new_node);
    _size++;
}

/**
 * @brief fix insert function
 * @param node node that was just added 
 */
template <typename _Tp, typename _Alloc>
void
_rbtree<_Tp, _Alloc>::_insert_node_fix(node_pointer node)
{
    while (node->parent->isred == true)
    {
        if (node->parent == node->parent->parent->left)
        {
            node_pointer y = node->parent->parent->right;
            if (y->isred == true)
            {
                node->parent->isred = false;
                y->isred = false;
                node->parent->parent->isred = true;
                node = node->parent->parent;
            }
            else if (node == node->parent->right)
            {
                node = node->parent->parent;
                _rbtree_rotate_left(node);
            }
            else
            {
                node->parent->isred = false;
                node->parent->parent->isred = true;
                _rbtree_rotate_right(node->parent->parent);
            }
        }
        else
        {
            node_pointer y = node->parent->parent->left;
            if (y->isred == true)
            {
                node->parent->isred = false;
                y->isred = false;
                node->parent->parent->isred = true;
                node = node->parent->parent;
            }
            else if (node == node->parent->left)
            {
                node = node->parent->parent;
                _rbtree_rotate_right(node);
            }
            else
            {
                node->parent->isred = false;
                node->parent->parent->isred = true;
                _rbtree_rotate_left(node->parent->parent);
            }
        }
    }
    _root->isred = false;
}

}   // END NAMESPACE FT