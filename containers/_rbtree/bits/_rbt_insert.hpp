/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_insert.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:20:06 by satchmin          #+#    #+#             */
/*   Updated: 2022/03/09 15:38:03 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_red_black_tree.hpp"


#ifndef _RBT_INSERT_HPP
#define _RBT_INSERT_HPP
namespace ft
{
/**
 * @brief create and initialize new node
 */
template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::node_pointer
_rbtree<_Tp, _Cmp, _Alloc>::_create_node(const value_type &val)
{
    node_pointer new_node;
    new_node = _node_alloc.allocate(SINGLE_NODE);
    new_node->parent = _nil;
    new_node->nil_node = _nil;
    new_node->data = _data_alloc.allocate(SINGLE_NODE);
    _data_alloc.construct(new_node->data, val);
    return new_node;
}
/**
 * @brief insert node into tree
 */
template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::pair_type
_rbtree<_Tp, _Cmp, _Alloc>::_insert_node(const value_type &val, node_pointer pos)
{
    node_pointer y = _nil;
    node_pointer x;
    if (pos != _nil)
        x = pos;
    else
        x = _root;
    while (x != _nil)
    {
        y = x;
        if (_is_equal(val, *x->data))
            return pair_type(iterator(x), false);
        else if (_key_compare(val, *x->data))
            x = x->left;
        else
            x = x->right;
	}
	node_pointer new_node = _create_node(val);
    new_node->parent = y;
    if (y == _nil)
        _root = new_node;
    else if (_key_compare(val, *y->data))
        y->left = new_node;
    else
        y->right = new_node;
    new_node->left = _nil;
    new_node->right = _nil;
	new_node->isred = true;
    _insert_node_fix(new_node);
    _size++;
    return pair_type(iterator(new_node), true);
}

/**
 * @brief fix insert function
 * @param node node that was just added 
 */
template <typename _Tp, typename _Cmp, typename _Alloc>
void
_rbtree<_Tp, _Cmp, _Alloc>::_insert_node_fix(node_pointer node)
{
    while (node->parent->isred == true)
    {
        if (node->parent == node->parent->parent->left)     // if aunt is red
        {
            node_pointer y = node->parent->parent->right;   // check uncle
            if (y->isred == true)
            {
                node->parent->isred = false;
                y->isred = false;
                node->parent->parent->isred = true;
                node = node->parent->parent;
            }
            else
            {
                if (node == node->parent->right)
                {    
                    node = node->parent;
                    _rbtree_rotate_left(node);
                }
                node->parent->isred = false;
                node->parent->parent->isred = true;
                _rbtree_rotate_right(node->parent->parent);
            }
        }
        else    // if uncle 
        {
            node_pointer y = node->parent->parent->left;
            if (y->isred == true)
            {
                node->parent->isred = false;
                y->isred = false;
                node->parent->parent->isred = true;
                node = node->parent->parent;
            }
            else
            { 
                if (node == node->parent->left)
                {
                    node = node->parent;
                    _rbtree_rotate_right(node);
                }
                node->parent->isred = false;
                node->parent->parent->isred = true;
                _rbtree_rotate_left(node->parent->parent);
            }
        }
    }
    _root->isred = false;
    _nil->_max = _rbtree_maximum(_root);
    _nil->_min = _rbtree_minimum(_root);
}

}   // END NAMESPACE FT

#endif  // _RBT_INSERT_HPP