/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:07:48 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/18 13:58:12 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RBT_ITERATOR_H
#define _RBT_ITERATOR_H

#include <iterator>
#include "../bits/_rbt_node.hpp"
#include "../_red_black_tree.hpp"

namespace ft
{

template<typename _Tp>
struct _rbtree_iterator
{   
    typedef _Tp value_type;
    typedef _Tp& reference;
    typedef _Tp* pointer;

    typedef std::bidirectional_iterator_tag     iterator_category;
    typedef ptrdiff_t                           difference_type;
    typedef _rbtree_iterator<_Tp>               _self;
    typedef _rb_node<_Tp>*                     _node_pointer;

    _node_pointer   _node;

    _rbtree_iterator(_node_pointer val) : _node(val) {}
    _rbtree_iterator() : _node() {}
    
    reference
    operator*() const
    {
        return *static_cast<_node_pointer>(_node->data);
    }

    pointer
    operator->() const
    {
        return static_cast<_node_pointer>(_node->data);
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
        _node = increment(_node);
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

#endif      //_RBT_ITERATOR_H