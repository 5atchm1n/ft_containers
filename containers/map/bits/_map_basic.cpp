/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map_basic.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 00:13:30 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/25 18:30:18 by sshakya          ###   ########.fr       */
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
    tmp++;
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
    iterator tmp = tree._insert_search(*pos++);
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
    tree = val.tree;
    _key_cmp = val._key_cmp;
    return *this;
}
/**
 *	ELEMENT ACCESS
 */

/**
 * @brief access operator [ ]
 * @return mapped_type at location
 */
template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::mapped_type &
map<_Key, _Tp, _Cmp, _Alloc>::operator[](const key_type &key)
{
    value_type val = ft::make_pair(key, mapped_type());
    iterator tmp = tree._insert_search(val);
    return tmp->second;
}
/**
 * @brief find a value that matches key pairing 
 * @return iterator to value
 */
template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::iterator
map<_Key, _Tp, _Cmp, _Alloc>::find(const _Key &key)
{
    value_type val = ft::make_pair(key, mapped_type());
    return iterator(tree._search_tree(val));
}
/**
 * @brief find a value that matches key pairing 
 * @return const iterator to value
 */
template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::const_iterator
map<_Key, _Tp, _Cmp, _Alloc>::find(const _Key &key) const
{
    value_type val = ft::make_pair(key, mapped_type());
    return const_iterator(tree._search_tree(val));
}
/**
 * @brief find a value that matches key pairing 
 * @return 1  or 0  depending on if key is found 
 */
template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::size_type
map<_Key, _Tp, _Cmp, _Alloc>::count(const _Key &key) const
{
    value_type val = ft::make_pair(key, mapped_type());
    const_iterator pos(tree._search_tree(val));
    return pos == end() ? end() : pos;
}
template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
void
map<_Key, _Tp, _Cmp, _Alloc>::clear()
{
    tree._clean();
}

}   // END NAMESPACE FT

#endif // _MAP_BASIC_HPP
