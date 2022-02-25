/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_node.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 02:50:49 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/24 22:15:01 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RBT_NODE_HPP
#define _RBT_NODE_HPP

#include <cstddef>
#include <memory>
#include <iostream>

#define SINGLE_NODE 1

namespace ft
{
template <typename _Tp, typename _Alloc>
class _rb_node
{
public:
    typedef _rb_node    node;
    typedef _rb_node*   node_pointer;
    typedef _Tp*        data_pointer;
    typedef _Alloc      data_allocator;
    bool isred;
    node_pointer nil_node;
    node_pointer parent;
    node_pointer left;
    node_pointer right;
    data_pointer data;

    node_pointer    _min;
    node_pointer    _max;
    // Coplien
    _rb_node();
    _rb_node(const _rb_node &copy);

    _rb_node &operator=(const _rb_node &val);
    // Helper function for iterator
private:
    node_pointer _increment() const;
    node_pointer _decrement() const;
    data_pointer _get_data() const;
    node_pointer _get_self() const;
};
/**
 *	@brief return data
 */
template <typename _Tp, typename _Alloc>
typename _rb_node<_Tp, _Alloc>::data_pointer
_rb_node<_Tp, _Alloc>::_get_data() const
{
    return (data);
}
template <typename _Tp, typename _Alloc>
typename _rb_node<_Tp, _Alloc>::node_pointer
_rb_node<_Tp, _Alloc>::_get_self() const
{
    return &this;
}
/**
 * @brief Construct a new NODE
 *
 * @tparam _Tp, typename _Alloc
 */
template <typename _Tp, typename _Alloc>
_rb_node<_Tp, _Alloc>::_rb_node() :
isred(false),
nil_node(),
parent(),
left(),
right(),
_min(),
_max(),
data() {}
/**
 * @brief Construct a new NODE from copy
 *
 * @tparam _Tp, typename _Alloc
 * @param copy
 */
template <typename _Tp, typename _Alloc>
_rb_node<_Tp, _Alloc>::_rb_node(const _rb_node &copy)
{
    *this = copy;
}
/**
 * @brief Operator= for COPLIEN class
 *
 * @tparam _Tp, typename _Alloc
 * @param val   node that we want to assign
 * @return current node with pointers swapped
 */
template <typename _Tp, typename _Alloc>
_rb_node<_Tp, _Alloc> &
_rb_node<_Tp, _Alloc>::operator=(const _rb_node &val)
{
    isred = val.isred;
    nil_node = val.nil_node;
    parent = val.parent;
    left = val.left;
    right = val.right;
    data = val.data;
    _max = val._max;
    _min = val._min;
    return *this;
}
/**
 * @brief Overload ostream operator to print node easily
 *
 * @param val   node to be printed
 */
template <typename _Tp, typename _Alloc>
std::ostream &operator<<(std::ostream &stream, const _rb_node<_Tp, _Alloc> &val)
{
    if (val.data == NULL)
    {
    stream << "NIL node" <<std::endl;
    stream << "max : " << val._max << "\n";
    stream << "min : " << val._min << "\n";
    return stream;
    }
    stream << "isred = " << val.isred << "\n";
    stream << "node = " << &val << "\n";
    stream << "parent: " << val.parent << "\n";
    stream << "nil : " << val.nil_node << "\n";
    stream << "left: " << val.left << "\tright: " << val.right << "\n";
    stream << "data: ";
    if (val.data != NULL)
        stream << " " << *val.data;
    return stream;
}

}
#endif //   _RBT_NODE_HPP
