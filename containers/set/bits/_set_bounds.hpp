/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _set_bounds.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:29:48 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/10 17:13:01 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"

#ifndef _SET_BOUNDS_HPP
#define _SET_BOUNDS_HPP

namespace ft
{

template <typename _Key, typename _Cmp, typename _Alloc>
typename set<_Key, _Cmp, _Alloc>::iterator
set<_Key, _Cmp, _Alloc>::lower_bound(const key_type &key)
{
    return tree._lower_bound(key);
}

template <typename _Key, typename _Cmp, typename _Alloc>
typename set<_Key, _Cmp, _Alloc>::const_iterator
set<_Key, _Cmp, _Alloc>::lower_bound(const key_type &key) const
{
    return tree._lower_bound(key);
}

template <typename _Key, typename _Cmp, typename _Alloc>
typename set<_Key, _Cmp, _Alloc>::iterator
set<_Key, _Cmp, _Alloc>::upper_bound(const key_type &key)
{
    return tree._upper_bound(key);
}

template <typename _Key, typename _Cmp, typename _Alloc>
typename set<_Key, _Cmp, _Alloc>::const_iterator
set<_Key, _Cmp, _Alloc>::upper_bound(const key_type &key) const
{
    return tree._upper_bound(key);
}

template <typename _Key, typename _Cmp, typename _Alloc>
typename set<_Key, _Cmp, _Alloc>::pair_range
set<_Key, _Cmp, _Alloc>::equal_range(const key_type &key)
{
    return tree._equal_range(key);

}

template <typename _Key, typename _Cmp, typename _Alloc>
typename set<_Key, _Cmp, _Alloc>::const_pair_range
set<_Key, _Cmp, _Alloc>::equal_range(const key_type &key) const
{
    return tree._equal_range(key);

}

}   // END NAMESPACE FT

#endif  //_SET_BOUNDS_HPP