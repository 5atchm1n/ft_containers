/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _set_modifier.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:19:29 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/11 03:18:04 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SET_MODIFIER_HPP
#define _SET_MODIFIER_HPP

#include "set.hpp"

namespace ft 
{

/**
 * @brief Insert using iterators 
 */
template <typename _Key, typename _Cmp, typename _Alloc>
template <typename InputIterator>
void
set<_Key, _Cmp, _Alloc>::insert(InputIterator first, InputIterator last)
{
    while (first != last)
        _tree._insert(*first++);
}
/**
 * @brief Insert single value
 * @return a pair type with an iterator to the element and bool if insert fails 
 */
template <typename _Key, typename _Cmp, typename _Alloc>
typename set<_Key, _Cmp, _Alloc>::pair_type
set<_Key, _Cmp, _Alloc>::insert(const value_type &value)
{
    return _tree._insert(value);
}
/**
 * @brief Insert with position
 * @return iterator to the position
 */
template <typename _Key, typename _Cmp, typename _Alloc>
typename set<_Key, _Cmp, _Alloc>::iterator
set<_Key, _Cmp, _Alloc>::insert(iterator position, const value_type &value)
{
    const_iterator it = position;
    return _tree._insert_pos(it, value);
}
/**
 * @brief   erase value at position (must be valid)
 */
template <typename _Key, typename _Cmp, typename _Alloc>
void
set<_Key, _Cmp, _Alloc>::erase(iterator position)
{
    _tree._delete_node(_tree._search_tree(*position));
}
/**
 * @brief erase given key from map
 * @return 1 if key was in else 0
 */
template <typename _Key, typename _Cmp, typename _Alloc>
typename set<_Key, _Cmp, _Alloc>::size_type
set<_Key, _Cmp, _Alloc>::erase(const key_type &key)
{
    iterator pos(_tree._search_tree(key));
    if (pos != end())
        _tree._delete_node(_tree._search_tree(key));
    return pos == end() ? 0 : 1;
    
}
/**
 * @brief Erase range of elements
 */
template<typename _Key, typename _Cmp, typename _Alloc>
void
set<_Key, _Cmp, _Alloc>::erase(iterator first, iterator last)
{
    while (first != last)
        _tree._delete_node(_tree._search_tree(*first++));
}

}   // END NAMESPACE FT

#endif //_SET_MODIFIER_HPP