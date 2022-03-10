/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _set_basic.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:19:46 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/10 16:28:13 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SET_BASIC_HPP
#define _SET_BASIC_HPP

#include "set.hpp"

namespace ft
{

template <typename _Key, typename _Cmp, typename _Alloc>
template <typename InputIterator>
set<_Key, _Cmp, _Alloc>::set(InputIterator first, InputIterator last, const _Cmp &comp, const _Alloc &alloc)
{
    while (first != last)
        _tree.insert(*first++);
}

/**
 * @brief Construct a new map object from copy
 */
template <typename _Key, typename _Cmp, typename _Alloc>
set<_Key, _Cmp, _Alloc>::set(const set &copy) : tree(copy.key_comp(), copy.get_allocator())
{
    const_iterator pos = copy.begin();
    while (pos != copy.end())
        tree._insert(*pos++);
}    
/**
 * @brief Assignment operator 
 */
template <typename _Key, typename _Cmp, typename _Alloc>
set<_Key, _Cmp, _Alloc> &
set<_Key, _Cmp, _Alloc>::operator=(const set &val)
{
    tree = val.tree;
    _key_cmp = val._key_cmp;
    return *this;
}
/**
 * @brief find a value that matches key pairing 
 * @return iterator to value
 */
template <typename _Key, typename _Cmp, typename _Alloc>
typename set<_Key, _Cmp, _Alloc>::iterator
set<_Key, _Cmp, _Alloc>::find(const _Key &key)
{
    return iterator(tree._search_tree(key));
}
/**
 * @brief find a value that matches key pairing 
 * @return const iterator to value
 */
template <typename _Key, typename _Cmp, typename _Alloc>
typename set<_Key, _Cmp, _Alloc>::const_iterator
set<_Key, _Cmp, _Alloc>::find(const _Key &key) const
{
    return const_iterator(tree._search_tree(key));
}
/**
 * @brief find a value that matches key pairing 
 * @return 1  or 0  depending on if key is found 
 */
template <typename _Key, typename _Cmp, typename _Alloc>
typename set<_Key, _Cmp, _Alloc>::size_type
set<_Key, _Cmp, _Alloc>::count(const _Key &key) const
{
    const_iterator pos(tree._search_tree(key));
    return pos == end() ? 0 : 1;
}

/**
 * @brief clear tree 
 */
template <typename _Key, typename _Cmp, typename _Alloc>
void
set<_Key, _Cmp, _Alloc>::clear()
{
    tree._clean();
}

}   // END NAMESPACE FT


#endif  // _SET_BASIC_HPP