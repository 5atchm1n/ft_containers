/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:07:48 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/24 00:46:23 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RBT_ITERATOR_H
#define _RBT_ITERATOR_H

#include <iterator>
#include "_rbt_node.hpp"
#include "../_red_black_tree.hpp"

namespace ft
{

    template <typename _Tp, typename _Alloc>
    class _rbtree_iterator
    {
    public:
        typedef _Tp value_type;
        typedef _Tp &reference;
        typedef _Tp *pointer;

        typedef std::bidirectional_iterator_tag iterator_category;
        typedef ptrdiff_t difference_type;
        typedef _rbtree_iterator<_Tp, _Alloc> _self;
        typedef _rb_node<_Tp, _Alloc> * _node_pointer;

    protected:
        void _increment();
        void _decrement();

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
            return _node->data;
        }

        _self &
        operator++()
        {
            _increment();
            return *this;
        }

        _self
        operator++(int)
        {
            _self tmp = *this;
            _increment();
            return tmp;
        }

        _self &
        operator--()
        {
            _decrement();
            return *this;
        }

        _self
        operator--(int)
        {
            _self tmp = *this;
            _decrement();
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
    template <typename value_type, typename _Alloc>
    class _rbtree_const_iterator : public ft::_rbtree_iterator<value_type, _Alloc>
    {
        typedef typename _rbtree_iterator<value_type, _Alloc>::_node_pointer _node_pointer;

    public:
        _rbtree_const_iterator() : _rbtree_iterator<value_type, _Alloc>() {}
        _rbtree_const_iterator(_node_pointer val) : _rbtree_iterator<value_type, _Alloc>(val) {}
        _rbtree_const_iterator(_rbtree_iterator<value_type, _Alloc> other) : _rbtree_iterator<value_type, _Alloc>(other) {}

        const value_type &operator*() const
        {
            return _rbtree_iterator<value_type, _Alloc>::operator*();
        }

        const value_type *operator->() const
        {
            return _rbtree_iterator<value_type, _Alloc>::operator->();
        }
    };

    /**
     * @brief Helper function for iterator
     *
     * @param nil_node  value of _nil node
     * @return value of "next" node
     */
    template <typename _Tp, typename _Alloc>
    void
    _rbtree_iterator<_Tp, _Alloc>::_increment()
    {
        if (_node == _node->nil_node)
            return ;
        if (_node->right != _node->nil_node)
        {
            _node = _node->right;
            while (_node->left != _node->nil_node)
                _node = _node->left;
        }
        else
        {
            _node_pointer tmp = _node->parent;
            while(tmp != _node->nil_node && _node == tmp->right)
            {
                _node = tmp;
                tmp = tmp->parent;
            }
            _node = tmp;
        }
    }

    template <typename _Tp, typename _Alloc>
    void
    _rbtree_iterator<_Tp, _Alloc>::_decrement()
    {
        if (_node == _node->nil_node)
            return ;
        if (_node->left != _node->nil_node)
        {
            while (_node->right != _node->nil_node)
                _node = _node->right;
        }
        else
        {
            _node_pointer tmp = _node->parent;
            while (tmp != _node->nil_node && _node == tmp->left)
            {
                _node = tmp;
                tmp = tmp->parent;
            }
            _node = tmp;
        }
    }

} // END NAMESPACE FT

#endif //_RBT_ITERATOR_H