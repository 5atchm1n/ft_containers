/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:07:48 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/22 18:13:31 by sshakya          ###   ########.fr       */
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

    _rbtree_iterator() : _node() {}
    _rbtree_iterator(_node_pointer val) : _node(val) {}
    _rbtree_iterator(const _rbtree_iterator & other) : _node(other._node) {}
    
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
        _node = _node->_increment();
        return *this;
    }

    _self
    operator++(int)
    {
        _self tmp = *this;
        _node = _node->_increment();
        return tmp;
    }

    _self&
    operator--()
    {
        _node = _node->_decrement();
        return *this;
    }

    _self
    operator--(int)
    {
        _self tmp = *this;
        _node = _node->_decrement();
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