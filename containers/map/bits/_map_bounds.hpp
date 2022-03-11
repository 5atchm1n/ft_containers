/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map_bounds.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:29:48 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/11 03:08:08 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAP_BOUNDS_HPP
#define _MAP_BOUNDS_HPP

#include "map.hpp"

namespace ft
{

/**
 * @brief Returns an iterator to the element before the given key
 */

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::iterator
map<_Key, _Tp, _Cmp, _Alloc>::lower_bound(const key_type &key)
{
    value_type val = ft::make_pair(key, mapped_type());
    return tree._lower_bound(val);
}

/**
 * @brief Returns an iterator to the element before the given key
 * @return const specialization
 */

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::const_iterator
map<_Key, _Tp, _Cmp, _Alloc>::lower_bound(const key_type &key) const
{
    value_type val = ft::make_pair(key, mapped_type());
    return tree._lower_bound(val);
}

/**
 * @brief Returns an iterator to the element after the given  key
 */
template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::iterator
map<_Key, _Tp, _Cmp, _Alloc>::upper_bound(const key_type &key)
{
    value_type val = ft::make_pair(key, mapped_type());
    return tree._upper_bound(val);
}

/**
 * @brief Returns an iterator to the element after the given key
 * @return const specialization
 */
template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::const_iterator
map<_Key, _Tp, _Cmp, _Alloc>::upper_bound(const key_type &key) const
{
    value_type val = ft::make_pair(key, mapped_type());
    return tree._upper_bound(val);
}

/**
 * @brief Returns a range of iterators containing the given key
 * @return if key is found upper and lower else range is 0 and
 *      points to next element 
 */
template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::pair_range
map<_Key, _Tp, _Cmp, _Alloc>::equal_range(const key_type &key)
{
    value_type val = ft::make_pair(key, mapped_type());
    return tree._equal_range(val);

}

/**
 * @brief Returns a range of iterators containing the given key
 * @return if key is found upper and lower else range is 0 and
 *      points to next element
 * @return const specialization 
 */
template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::const_pair_range
map<_Key, _Tp, _Cmp, _Alloc>::equal_range(const key_type &key) const
{
    value_type val = ft::make_pair(key, mapped_type());
    return tree._equal_range(val);

}

}   // END NAMESPACE FT

#endif  //_MAP_BOUNDS_HPP