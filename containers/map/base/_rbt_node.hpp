/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_node.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satchmin <satchmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 02:50:49 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/08 03:02:42 by satchmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RBT_NODE_HPP
#define _RBT_NODE_HPP

#include <cstddef>
#include <memory>

#define SINGLE_NODE 1

namespace ft {

template <typename _Tp, typename _Alloc = std::allocator<_Tp> >
class _rb_node
{
    private:
        _Alloc _data_alloc;
    
    public:
        bool        isred;
        _rb_node    *parent;
        _rb_node    *left;
         _rb_node    *right;
        _Tp         *data;
        
        _rb_node();
        _rb_node(const _rb_node &copy);
        _rb_node    operator=(const _rb_node &val);
        ~_rb_node();
};

template <typename _Tp, typename _Alloc>
_rb_node<_Tp, _Alloc>::_rb_node()
{
    isred = false;
    parent = NULL;
    left = NULL;
    right = NULL;
    data =  _data_alloc.allocate(SINGLE_NODE); 
}
template <typename _Tp, typename _Alloc>
_rb_node<_Tp, _Alloc>::_rb_node(const _rb_node &copy)
{
    isred = copy.isred;
    parent = copy.parent;
    left = copy.left;
    right = copy.right;
    data = _data_alloc.allocate(SINGLE_NODE);
    _data_alloc.construct(data, *copy.data);
}

template <typename _Tp, typename _Alloc>
_rb_node<_Tp, _Alloc>
_rb_node<_Tp, _Alloc>::operator=(const _rb_node &val)
{
    _rb_node _new(val);
    return _new;        
}

template <typename _Tp, typename _Alloc>
_rb_node<_Tp, _Alloc>::~_rb_node()
{
    _data_alloc.destroy(data);
    _data_alloc.deallocate(data, SINGLE_NODE);
}

}
#endif //   _RBT_NODE_HPP