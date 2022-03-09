/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _red_black_tree.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:15:26 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/09 02:20:02 by sshakya          ###   ########.fr       */
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
    iterator pos;
    if (it != _end() && _key_compare(val, *(it._node->data))
    && it._node->parent != _nil
    && _key_compare(*(it._node->parent->data), val))
        pos = _insert_node(val, it._node).first;
    else
        pos = _insert_node(val, _root).first;
    return pos;
}

template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::pair_type
_rbtree<_Tp, _Cmp, _Alloc>::_insert(const value_type &val)
{
    return _insert_node(val, _root);
}

/**
 * @brief check if two values are equal
 * @return true or false bool
 */
template <typename _Tp, typename _Cmp, typename _Alloc>
bool
_rbtree<_Tp, _Cmp, _Alloc>::_is_equal(const value_type &val, const value_type &other) const
{
    return !_key_compare(val, other) && !_key_compare(other, val);
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
    while (tmp != _nil && !_is_equal(val, *tmp->data))
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

/**
 * @brief find lower bound of given val
 * @return iterator to val or end
 */

template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::iterator
_rbtree<_Tp, _Cmp, _Alloc>::_lower_bound(const value_type &val)
{
    iterator it = _begin();
    iterator ite = _end();
    while (it != ite)
    {
        if (!_key_compare(*it, val))
            return it;
        it++;
    }
    return it;
}

template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::const_iterator
_rbtree<_Tp, _Cmp, _Alloc>::_lower_bound(const value_type &val) const
{
    iterator it = _begin();
    iterator ite = _end();
    while (it != ite)
    {
        if (!_key_compare(*it, val))
            return it;
        it++;
    }
    return it;
}
/**
 * @brief find upper bound of given val
 * @return iterator to value after val or end
 */
template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::iterator
_rbtree<_Tp, _Cmp, _Alloc>::_upper_bound(const value_type &val)
{
    iterator it = _begin();
    iterator ite = _end();
    while (it != ite)
    {
        if (!_key_compare(val, *it))
            return it;
        it++;
    }
    return it;
}

template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::const_iterator
_rbtree<_Tp, _Cmp, _Alloc>::_upper_bound(const value_type &val) const
{
    iterator it = _begin();
    iterator ite = _end();
    while (it != ite)
    {
        if (!_key_compare(val, *it))
            return it;
        it++;
    }
    return it;
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