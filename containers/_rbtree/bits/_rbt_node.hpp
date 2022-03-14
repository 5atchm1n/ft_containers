/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_node.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 02:50:49 by satchmin          #+#    #+#             */
/*   Updated: 2022/02/25 16:37:43 by sshakya          ###   ########.fr       */
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
template <typename _Tp>
class _rb_node
{
public:
    typedef _rb_node    node;
    typedef _rb_node*   node_pointer;
    typedef _Tp*        data_pointer;
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
protected:
    node_pointer _increment() const;
    node_pointer _decrement() const;
};

/**
 * @brief Construct a new NODE
 *
 * @tparam _Tp, typename _Alloc
 */
template <typename _Tp>
_rb_node<_Tp>::_rb_node() :
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
template <typename _Tp>
_rb_node<_Tp>::_rb_node(const _rb_node &copy)
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
    _max = val._max;
    _min = val._min;
    return *this;
}


/**
 * @brief Overload ostream operator to print node easily
 *
 * @param val   node to be printed
 */
template <typename _Tp>
std::ostream &operator<<(std::ostream &stream, const _rb_node<_Tp> &val)
{
    if (val.data == NULL)
    {
        stream << "NIL node" <<std::endl;
        stream << "max : " << val._max << "\n";
        stream << "min : " << val._min << "\n";
        return stream;
    }
    if (val.data != NULL)
        stream << "isred : "<< val.isred << " " << *val.data;
    return stream;
}

}
#endif //   _RBT_NODE_HPP
