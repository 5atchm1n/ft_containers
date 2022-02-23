/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:07:48 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/23 00:57:20 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RBT_ITERATOR_H
#define _RBT_ITERATOR_H

#include <iterator>
#include "_rbt_node.hpp"
#include "../_red_black_tree.hpp"

namespace ft
{

    template <typename _Tp>
    class _rbtree_iterator
    {
        public:
        typedef _Tp value_type;
        typedef _Tp &reference;
        typedef _Tp *pointer;

        typedef std::bidirectional_iterator_tag iterator_category;
        typedef ptrdiff_t difference_type;
        typedef _rbtree_iterator<_Tp> _self;
        typedef _rb_node<_Tp> *_node_pointer;

        protected:
            _node_pointer _node;

        public:
        _rbtree_iterator() : _node() {}
        _rbtree_iterator(_node_pointer val) : _node(val) {}
        _rbtree_iterator(const _rbtree_iterator &other) : _node(other._node) {}

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

        _self &
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

        _self &
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

    template <typename value_type>
    class _rbtree_const_iterator : public ft::_rbtree_iterator<value_type>
    {
        typedef typename _rbtree_iterator<value_type>::_node_pointer _node_pointer;
    public:

        _rbtree_const_iterator() : _rbtree_iterator<value_type>() {}
        _rbtree_const_iterator(_node_pointer val) : _rbtree_iterator<value_type>(val) {}
        _rbtree_const_iterator(_rbtree_iterator<value_type> other) : _rbtree_iterator<value_type>(other) {}

        const value_type &operator*() const
        {
            return _rbtree_iterator<value_type>::operator*();
        }

        const value_type *operator->() const
        {
            return _rbtree_iterator<value_type>::operator->();
        }
    };

} // END NAMESPACE FT

#endif //_RBT_ITERATOR_H