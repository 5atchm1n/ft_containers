/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map_modifier.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:19:29 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/08 20:34:37 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_MODIFIER_HPP
#define _MAP_MODIFIER_HPP

#include "../_map_header.hpp"

namespace ft 
{

/**
 * @tparam _Key             key_type 
 * @tparam _Tp              value_type
 * @tparam _Cmp             key_compare
 * @tparam _Alloc           allocator_type
 * @tparam InputIterator    Input iterator type
 */

/**
 * @brief Insert using iterators 
 */

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
template <typename InputIterator>
void
map<_Key, _Tp, _Cmp, _Alloc>::insert(InputIterator first, InputIterator last)
{
    while (first != last)
        tree._insert_search(*first++);
}

/**
 * @brief Insert single value
 * @return a pair type with an iterator to the element and bool if insert fails 
 */
template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
ft::pair<typename ft::map<_Key, _Tp, _Cmp, _Alloc>::iterator, bool>
map<_Key, _Tp, _Cmp, _Alloc>::insert(const value_type &value)
{
    iterator tmp = tree._search_tree(value);
    bool    was_inserted = (tmp == end() ? true : false);
    iterator position = tree._insert_search(value);
    ft::pair<iterator, bool> _value = ft::make_pair(position, was_inserted);
    return _value;
}

/**
 * @brief Insert with position
 * @return iterator to the position
 */
template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::iterator
map<_Key, _Tp, _Cmp, _Alloc>::insert(iterator position, const value_type &value)
{
    return tree._insert_pos(position, value);
}

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
void
map<_Key, _Tp, _Cmp, _Alloc>::erase(iterator position)
{
    key_type tmp_key = position->first;
    value_type val = ft::make_pair(tmp_key, mapped_type());
    tree._delete_node(tree._search_tree(val));
    tree.print();
}


template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::size_type
map<_Key, _Tp, _Cmp, _Alloc>::erase(const key_type &key)
{
    value_type val = ft::make_pair(key, mapped_type());
    iterator pos(tree._search_tree(val));
    if (pos != end())
        tree._delete_node(tree._search_tree(val));
    return pos == end() ? 0 : 1;
    
}

template<typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
void
map<_Key, _Tp, _Cmp, _Alloc>::erase(iterator first, iterator last)
{
    while (first != last)
        tree._delete_node(tree._search_tree(*first++));
}

}   // END NAMESPACE FT

#endif //_MAP_MODIFIER_HPP