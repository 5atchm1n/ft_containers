/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_node.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 02:50:49 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/23 21:52:20 by sshakya          ###   ########.fr       */
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
    typedef _rb_node    node;
    typedef _rb_node*   node_pointer;
    typedef _Tp*        data_pointer;
    
    bool            isred;
    node_pointer    nil_node;
    node_pointer    parent;
    node_pointer    left;
    node_pointer    right;
    data_pointer    data;
    // Coplien
    _rb_node();
    _rb_node(const _rb_node &copy); 
    _rb_node    &operator=(const _rb_node &val);
    // Helper function for iterator
    node_pointer	_increment() const;
    node_pointer	_decrement() const;
	data_pointer	_get_data() const;
    node_pointer    _get_self() const;
};

/**
 *	@brief return data
 */
template <typename _Tp>
typename _rb_node<_Tp>::data_pointer
_rb_node<_Tp>::_get_data() const
{
	return (data);
}

template <typename _Tp>
typename _rb_node<_Tp>::node_pointer
_rb_node<_Tp>::_get_self() const
{
    return &this;
}

/**
 * @brief Construct a new NODE
 * 
 * @tparam _Tp 
 */
template <typename _Tp>
_rb_node<_Tp>::_rb_node() : 
isred(false),
nil_node(),
parent(),
left(),
right(), 
data()
{}
/**
 * @brief Construct a new NODE from copy
 * 
 * @tparam _Tp 
 * @param copy 
 */
template <typename _Tp>
_rb_node<_Tp>::_rb_node(const _rb_node &copy)
{
    *this = copy;
}
/**
 * @brief Operator= for COPLIEN class
 * 
 * @tparam _Tp 
 * @param val   node that we want to assign
 * @return current node with pointers swapped 
 */
template <typename _Tp>
_rb_node<_Tp> &
_rb_node<_Tp>::operator=(const _rb_node &val)
{
    isred = val.isred;
    nil_node = val.nil_node;
    parent = val.parent;
    left = val.left;
    right = val.right;
    data = val.data;
    return *this;
}
/**
 * @brief Overload ostream operator to print node easily
 * 
 * @param val   node to be printed 
 */
template <typename _Tp>
std::ostream& operator<<(std::ostream& stream, const _rb_node<_Tp> &val)
{
    stream << "isred = " << val.isred << "\n";
    //stream << "node = " << &val << "\n";
    //stream << "parent: " << val.parent << "\n";
    //stream << "left: " << val.left << "\tright: " << val.right << "\n";
    stream << "data: " << val.data;
    if (val.data != NULL)
        stream << " " << *val.data;
    return stream;
}

}
#endif //   _RBT_NODE_HPP
