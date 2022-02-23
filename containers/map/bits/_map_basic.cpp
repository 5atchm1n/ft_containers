/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map_basic.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 00:13:30 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/23 22:24:28 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_BASIC_HPP
#define _MAP_BASIC_HPP

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
 * @brief Construct a new map object using iterators
 */
template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
template <typename InputIterator>
map<_Key, _Tp, _Cmp, _Alloc>::map(InputIterator first, InputIterator last, const _Cmp &comp, const _Alloc &alloc) : tree(comp, alloc)
{
    InputIterator tmp = first;
    iterator pos = tree._insert_search(*tmp++);
    while (tmp != last)
        pos = tree._insert_pos(pos, *tmp++);
}

/**
 * @brief Construct a new map object from copy
 */
template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
map<_Key, _Tp, _Cmp, _Alloc>::map(const map &copy) : tree(copy.key_comp(), copy.get_allocator())
{
    iterator pos = copy.begin();
    iterator tmp = tree._insert_search(*pos);
    while (pos != copy.end())
        tmp = tree._insert_pos(tmp, *pos++);
}    

/**
 * @brief 
 * 
 */
template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
map<_Key, _Tp, _Cmp, _Alloc> &
map<_Key, _Tp, _Cmp, _Alloc>::operator=(const map &val)
{
    if (this != &val)
        *this = val;
    return *this;
}
/**
 *	ELEMENT ACCESS
 */
template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::mapped_type &
map<_Key, _Tp, _Cmp, _Alloc>::operator[](const key_type &key)
{
    value_type val = ft::make_pair(key, mapped_type());
    if (!tree._is_duplicate(val))
        insert(val);
    return (tree._search_tree(val)->_get_data())->second;
}

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::iterator
map<_Key, _Tp, _Cmp, _Alloc>::find(const _Key &key)
{
    value_type val = ft::make_pair(key, mapped_type());
    return iterator(tree._search_tree(val));
}

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::const_iterator
map<_Key, _Tp, _Cmp, _Alloc>::find(const _Key &key) const
{
    value_type val = ft::make_pair(key, mapped_type());
    return const_iterator(tree._search_tree(val));
}

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::size_type
map<_Key, _Tp, _Cmp, _Alloc>::count(const _Key &key) const
{
    value_type val = ft::make_pair(key, mapped_type());
    const_iterator pos(tree._search_tree(val));
    return pos == end() ? end() : pos;
}


}   // END NAMESPACE FT

#endif // _MAP_BASIC_HPP