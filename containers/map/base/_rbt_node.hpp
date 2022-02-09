/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_node.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 02:50:49 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/09 18:58:31 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RBT_NODE_HPP
#define _RBT_NODE_HPP

#include <cstddef>
#include <memory>
#include <iostream>

#define SINGLE_NODE 1

namespace ft {

template <typename _Tp>
struct _rb_node
{
    private:
        void    _copy_node(const _rb_node &copy);
    
    public:
        bool        isred;
        _rb_node    *parent;
        _rb_node    *left;
         _rb_node    *right;
        _Tp         *data;
    //  HELPER FUNCTORS
        _rb_node    operator=(const _rb_node &val);
        void        _init_node(_rb_node *_nil);
};


template <typename _Tp>
void
_rb_node<_Tp>::_init_node(_rb_node *_nil)
{
    parent = _nil;
    left = _nil;
    right = _nil;
    data = NULL;
}

template <typename _Tp>
void
_rb_node<_Tp>::_copy_node(const _rb_node &copy)
{
    isred = copy.isred;
    parent = copy.parent;
    left = copy.left;
    right = copy.right;
    data = copy.data; 
}

template <typename _Tp>
_rb_node<_Tp>
_rb_node<_Tp>::operator=(const _rb_node &val)
{
    _copy_node(val);
    return *this;        
}

template <typename _Tp>
std::ostream& operator<<(std::ostream& stream, const _rb_node<_Tp> &val)
{
    stream << "isred = " << val.isred << "\n";
    stream << "parent: " << val.parent << "\n";
    stream << "left: " << val.left << "\tright: " << val.right << "\n";
    stream << "data: " << val.data;
    return stream;
}

}
#endif //   _RBT_NODE_HPP