/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:07:48 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/10 02:48:02 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RBT_ITERATOR_H
#define _RBT_ITERATOR_H

#include <iterator>
#include "_rbt_node.hpp"
#include "../_red_black_tree.hpp"

namespace ft
{

    template <typename _Tp, typename _node_type>
    class _rbtree_iterator
    {
    public:
        typedef _Tp         value_type;
        typedef _Tp&        reference;
        typedef _Tp*        pointer;
        typedef const _Tp&  const_reference;
        typedef const _Tp*  const_pointer;

        typedef std::bidirectional_iterator_tag iterator_category;
        typedef ptrdiff_t                       difference_type;
        typedef _node_type*                     _node_pointer;

    protected:
        void _increment();
        void _decrement();


    public:
        _node_pointer _node;

        _rbtree_iterator() : _node() {}
        _rbtree_iterator(_node_pointer val) : _node(val) {}
        _rbtree_iterator(_rbtree_iterator const &other) : _node(other._node) {}

        _rbtree_iterator& operator=(_rbtree_iterator const &val)
        {
            if (this != &val)
                _node = val._node;
            return *this;
        }

        operator    _rbtree_iterator<value_type const, _node_type const>() const
        {
            return _rbtree_iterator<value_type const, _node_type const>(_node);
        }

        reference
        operator*()
        {
            return *_node->data;
        }

        pointer
        operator->()
        {
            return _node->data;
        }
        
        const_reference
        operator*() const
        {
            return *_node->data;
        }

        const_pointer
        operator->() const
        {
            return _node->data;
        }

        _rbtree_iterator &
        operator++()
        {
            _increment();
            return *this;
        }

        _rbtree_iterator
        operator++(int)
        {
            _rbtree_iterator tmp(*this);
            _increment();
            return tmp;
        }

        _rbtree_iterator &
        operator--()
        {
            _decrement();
            return *this;
        }

        _rbtree_iterator
        operator--(int)
        {
            _rbtree_iterator tmp(*this);
            _decrement();
            return tmp;
        }

        bool
        operator==(const _rbtree_iterator &val) const
        {
            return _node == val._node;
        }

        bool
        operator!=(const _rbtree_iterator &val) const
        {
            return _node != val._node;
        }
    };

    /**
     * @brief Helper function for iterator
     *
     * @param nil_node  value of _nil node
     * @return value of "next" node
     */
    template <typename _Tp, typename _node_type>
    void
    _rbtree_iterator<_Tp, _node_type>::_increment()
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
    
    template <typename _Tp, typename _node_type>
    void
    _rbtree_iterator<_Tp, _node_type>::_decrement()
    {
        if (_node == _node->nil_node)
        {
            _node = _node->nil_node->_max;
            return ;
        }
        if (_node->left != _node->nil_node)
        {
            _node = _node->left;
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