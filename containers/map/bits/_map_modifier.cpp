/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map_modifier.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:19:29 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/23 01:07:53 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../map.hpp"

namespace ft 
{

/**
 * @tparam _Key             key_type 
 * @tparam _Tp              value_type
 * @tparam _Cmp             key_compare
 * @tparam _Alloc           allocator_type
 * @tparam InputIterator    Input iterator type
 *
 * * * *    INSERT METHODS * * * *
 */

/**
 * @brief Insert using iterators 
 */

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
template <typename InputIterator>
void
map<_Key, _Tp, _Cmp, _Alloc>::insert(InputIterator first, InputIterator last)
{
    for (InputIterator tmp = first; tmp != last; tmp++)
    {
        tree._insert_node(*tmp);
    }
}

/**
 * @brief Insert single value
 * @return a pair type with an iterator to the element and bool if insert fails 
 */
template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
ft::pair<typename ft::map<_Key, _Tp, _Cmp, _Alloc>::iterator, bool>
map<_Key, _Tp, _Cmp, _Alloc>::insert(const value_type &value)
{
    bool    is_in = !tree._is_duplicate(value);
    iterator position = (tree._insert_search(value));
    ft::pair<iterator, bool> _value = ft::make_pair(position, is_in);
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
    (void)position;
    return iterator (tree._insert_search(value));
}

template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
void
map<_Key, _Tp, _Cmp, _Alloc>::erase(iterator position)
{
    key_type tmp_key = position->first;
    value_type val = make_pair(tmp_key, mapped_type());
    tree._delete_node(tree._search_tree(val));
}


template <typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
typename map<_Key, _Tp, _Cmp, _Alloc>::size_type
map<_Key, _Tp, _Cmp, _Alloc>::erase(const key_type &key)
{
    value_type val = make_pair(key, mapped_type());
    iterator pos(tree._search_tree(val));
    return pos == end() ? 0 : 1;
    
}

template<typename _Key, typename _Tp, typename _Cmp, typename _Alloc>
void
map<_Key, _Tp, _Cmp, _Alloc>::erase(iterator first, iterator last)
{
    iterator i = first;
    value_type val;

    while (i != last)
    {
        value_type val = make_pair(first->first, mapped_type());
        tree._delete_node(tree._search_tree(val));
        i++;
    }
}

}