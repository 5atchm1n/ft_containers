/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_const_iterator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:40:27 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/18 14:10:31 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RBT_CONST_ITERATOR_H
#define _RBT_CONST_ITERATOR_H

#include <iterator>
#include "../bits/_rbt_node.hpp"
#include "_rbt_iterator.hpp"
#include "../_red_black_tree.hpp"

namespace ft
{

template<typename _Tp>
struct _rbtree_const_iterator
{
    typedef _Tp value_type;
    typedef _Tp& reference;
    typedef _Tp* pointer;

    typedef _rbtree_iterator<_Tp>               iterator;

    typedef std::bidirectional_iterator_tag     iterator_category;
    typedef ptrdiff_t                           difference_type;
    typedef _rbtree_const_iterator<_Tp>               _self;
    typedef const _rb_node<_Tp>*                     _node_pointer;

    _node_pointer   _node;

    _rbtree_const_iterator(_node_pointer val) : _node(val) {}
    _rbtree_const_iterator() : _node() {}
    _rbtree_const_iterator(const iterator &val) : _node(val._node) {}

    iterator
    _const_cast() const
    {
        return iterator(const_cast<typename iterator::_node_pointer>(_node));
    }
    
    reference
    operator*() const
    {
        return *_node->data;
    }

    pointer
    operator->() const
    {
        return &(operator*());
    }

    _self&
    operator++()
    {
        _node = _increment(_node);
        return *this;
    }

    _self
    operator++(int)
    {
        _self tmp = *this;
        _node = _increment(_node);
        return tmp;
    }

    _self&
    operator--()
    {
        _node = _decrement(_node);
        return *this;
    }

    _self
    operator--(int)
    {
        _self tmp = *this;
        _node = _decrement(_node);
        return tmp;
    }

    bool
    operator==(const _self &val) const
    {
        return _node == val._node;
    }

    bool
    operator!=(const _self &val) const
    {
        return _node != val._node;
    }

};

}   // END NAMESPACE FT

#endif      //_RBT_CONST_ITERATOR_H