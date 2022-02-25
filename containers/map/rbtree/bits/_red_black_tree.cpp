/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _red_black_tree.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:15:26 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/25 14:11:12 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_red_black_tree.hpp"
#include <cstddef>

namespace ft
{

/** 
 * @tparam _Tp      value type 
 * @tparam _Cmp     compare object
 * @tparam _Alloc   allocator object 
 */


template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::iterator
_rbtree<_Tp, _Cmp, _Alloc>::_insert_pos(iterator it, const value_type &val)
{
    node_pointer node = _search_tree(val);
    if (node != _nil)
        return iterator(node);
    iterator ret;
    if (!_key_compare(val, *it))
        ret = (_insert_node(val, node));
    else
        ret = _insert_node(val, _root);
    return ret;
}

template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::iterator
_rbtree<_Tp, _Cmp, _Alloc>::_insert_search(const value_type &val)
{
    node_pointer node = _search_tree(val);
    if (node == _nil)
        node = _insert_node(val, _root);
    return iterator(node);
}

/**
 * @brief iterative search
 * 
 * @param val value to find
 * @return pointer to node
 */
template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::node_pointer
_rbtree<_Tp, _Cmp, _Alloc>::_search_tree(const value_type &val) const
{
    node_pointer tmp = _root;
    while (tmp != _nil && !(!_key_compare(val, *tmp->data) && !_key_compare(*tmp->data, val)))
    {
        if (_key_compare(val, *tmp->data))
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    return (tmp);
}

/**
 * @brief find smallest value in tree
 * 
 * @return poitner to node containing smallest value 
 */
template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::node_pointer
_rbtree<_Tp, _Cmp, _Alloc>::_rbtree_minimum(node_pointer node) const
{
    if (node == _nil)
        return node;
    node_pointer tmp = node;
    while (tmp->left != _nil)
        tmp = tmp->left;
    return tmp;
}
/**
 * @brief find largest value in tree 
 * 
 * @return poitner to node containing largest value
 */
template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::node_pointer
_rbtree<_Tp, _Cmp, _Alloc>::_rbtree_maximum(node_pointer node) const
{
    if (node == _nil)
        return node;
    node_pointer tmp = node;
    while (tmp->right != _nil)
        tmp = tmp->right;
    return tmp;
}

template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::node_pointer
_rbtree<_Tp, _Cmp, _Alloc>::_rbtree_end(node_pointer node) const
{
    node_pointer tmp = node;
    while (tmp->right != _nil)
        tmp = tmp->right;
    return tmp->right;
}
/**
 * @brief find the in order successor
 * @return pointer to in order successor 
 */
template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::node_pointer
_rbtree<_Tp, _Cmp, _Alloc>::_rbtree_successor(node_pointer node) const
{
    if (node->right != _nil)
        return _rbtree_minimum(node->right);
    node_pointer tmp = node->parent;
    while (tmp != _nil && node == tmp->right)
    {
        node = tmp;
        tmp = tmp->parent;
    }
    return tmp;
}

}   // END NAMESPACE FT