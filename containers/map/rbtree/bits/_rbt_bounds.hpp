/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _rbt_bounds.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:57:50 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/09 16:33:50 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_red_black_tree.hpp"

#ifndef _RBT_BOUNDS_HPP
#define _RBT_BOUNDS_HPP

namespace ft
{
    
/**
 * @brief find lower bound of given val
 * @return iterator to val or end
 */

template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::iterator
_rbtree<_Tp, _Cmp, _Alloc>::_lower_bound(const value_type &val)
{
    iterator it = _begin();
    iterator ite = _end();
    while (it != ite)
    {
        if (!_key_compare(*it, val))
            return it;
        it++;
    }
    return it;
}

template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::const_iterator
_rbtree<_Tp, _Cmp, _Alloc>::_lower_bound(const value_type &val) const
{
    iterator it = _begin();
    iterator ite = _end();
    while (it != ite)
    {
        if (!_key_compare(*it, val))
            return it;
        it++;
    }
    return it;
}
/**
 * @brief find upper bound of given val
 * @return iterator to value after val or end
 */
template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::iterator
_rbtree<_Tp, _Cmp, _Alloc>::_upper_bound(const value_type &val)
{
    iterator it = _begin();
    iterator ite = _end();
    while (it != ite)
    {
        if (_key_compare(val, *it))
            return it;
        it++;
    }
    return it;
}

template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::const_iterator
_rbtree<_Tp, _Cmp, _Alloc>::_upper_bound(const value_type &val) const
{
    iterator it = _begin();
    iterator ite = _end();
    while (it != ite)
    {
        if (_key_compare(val, *it))
            return it;
        it++;
    }
    return it;
}

template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::pair_range
_rbtree<_Tp, _Cmp, _Alloc>::_equal_range(const value_type &val)
{
    iterator it = _upper_bound(val);
    iterator ite = _lower_bound(val);
    return pair_range(ite, it);
}

template <typename _Tp, typename _Cmp, typename _Alloc>
typename _rbtree<_Tp, _Cmp, _Alloc>::const_pair_range
_rbtree<_Tp, _Cmp, _Alloc>::_equal_range(const value_type &val) const
{
    const_iterator it = _upper_bound(val);
    const_iterator ite = _lower_bound(val);
    return const_pair_range(ite, it);
}
    
}   // END NAMESPACE FT

#endif  //_RBT_BOUNDS_HPP