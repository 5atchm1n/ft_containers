/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map_bounds.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:29:48 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/09 16:06:14 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_map_header.hpp"

#ifndef _MAP_BOUNDS_HPP
#define _MAP_BOUNDS_HPP

namespace ft
{

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::iterator
map<_Key, _Tp, _Cmp, _Alloc>::lower_bound(const key_type &key)
{
    value_type val = ft::make_pair(key, mapped_type());
    return tree._lower_bound(val);
}

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::const_iterator
map<_Key, _Tp, _Cmp, _Alloc>::lower_bound(const key_type &key) const
{
    value_type val = ft::make_pair(key, mapped_type());
    return tree._lower_bound(val);
}

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::iterator
map<_Key, _Tp, _Cmp, _Alloc>::upper_bound(const key_type &key)
{
    value_type val = ft::make_pair(key, mapped_type());
    return tree._upper_bound(val);
}

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::const_iterator
map<_Key, _Tp, _Cmp, _Alloc>::upper_bound(const key_type &key) const
{
    value_type val = ft::make_pair(key, mapped_type());
    return tree._upper_bound(val);
}

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::pair_range
map<_Key, _Tp, _Cmp, _Alloc>::equal_range(const key_type &key)
{
    value_type val = ft::make_pair(key, mapped_type());
    return tree._equal_range(val);

}

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::const_pair_range
map<_Key, _Tp, _Cmp, _Alloc>::equal_range(const key_type &key) const
{
    value_type val = ft::make_pair(key, mapped_type());
    return tree._equal_range(val);

}

}   // END NAMESPACE FT

#endif  //_MAP_BOUNDS_HPP