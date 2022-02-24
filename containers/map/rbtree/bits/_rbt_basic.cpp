/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_basic.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:33:51 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/24 01:17:21 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_red_black_tree.hpp"

#ifndef _RBT_BASIC_H
#define _RBT_BASIC_H

namespace ft
{

/**
 * @brief 
 * 
 */
template <typename _Tp, typename _Cmp, typename _Alloc>
_rbtree<_Tp, _Cmp, _Alloc> &
_rbtree<_Tp, _Cmp, _Alloc>::operator=(const _rbtree &copy)
{
    _clean_tree(_root);
    _nil = _node_alloc.allocate(SINGLE_NODE);
    _nil->isred = false;
    _nil->parent = _nil;
    _nil->right = _nil;
    _nil->left = _nil;
    _root = _nil;
    for (const_iterator i = copy._begin(); i != copy._end(); ++i)
        _insert_node(*i, _root);
    return *this;
}

/**
 * @brief contructor with default
 */
template <typename _Tp, typename _Cmp, typename _Alloc>
_rbtree<_Tp, _Cmp, _Alloc>::_rbtree(const _Cmp compare, const _Alloc allocator)
: _data_alloc(allocator), _key_compare(compare)
{
    _size = 0;
    _nil = _node_alloc.allocate(SINGLE_NODE);
    _nil->isred = false;
    _nil->data = NULL;
    _nil->right = _nil;
    _nil->left = _nil;
    _nil->nil_node = _nil;
    _root = _nil;
}

/**
 * @brief helper function to clean tree - recursive
 */ 
template <typename _Tp, typename _Cmp, typename _Alloc>
void
_rbtree<_Tp, _Cmp, _Alloc>::_clean_tree(node_pointer node)
{
    if (node != _nil)
    {
        _clean_tree(node->left);
        _clean_tree(node->right);
        _clean_node(node);
    }
}

/**
 * @brief destructor
 */
template <typename _Tp, typename _Cmp, typename _Alloc>
_rbtree<_Tp, _Cmp, _Alloc>::~_rbtree()
{
    if (_root != _nil)
        _clean_tree(_root);
    _node_alloc.deallocate(_nil, SINGLE_NODE);
}

template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::size_type
_rbtree<_Tp, _Cmp, _Alloc>::_get_size() const
{
    return _size;
}

template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::size_type
_rbtree<_Tp, _Cmp, _Alloc>::_get_max_size() const
{
    return _node_alloc.max_size() / (sizeof(_Tp));
}

/**
 * @brief print tree helper
 * @return std::ostream& 
 */

template <typename _Tp, typename _Cmp, typename _Alloc>
std::ostream &operator<<(std::ostream &stream, const _rbtree<_Tp, _Cmp, _Alloc> &val)
{
    stream << "root = " << val._root << "\n";
    stream << "nil = " << val._nil << "\n";
    stream << "node : " << *val._root << "\n";
    return stream;
}

    
}   // END NAMESPACE FT

#endif  // _RBT_BASIC_H