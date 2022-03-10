/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _set_basic.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:03:45 by sshakya           #+#    #+#             */
/*   Updated: 2022/03/10 15:22:19 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SET_BASIC_HPP
#define _SET_BASIC_HPP

#include <functional>
#include <memory>
#include "../map/rbtree/_red_black_tree.hpp"

namespace ft
{

template < typename _Key, typename _Cmp = std::less<_Key>, typename _Alloc = std::allocator<_Key> >
class set 
{
    public:
        typedef _Key    key_type;
        typedef _Key    value_type;
        typedef _Cmp    key_compare;
        typedef _Cmp    value_compare;
        typedef _Alloc  allocator_type;
        
    private:
        typedef typename _Alloc::template rebind<_Key>::other  _key_alloc_type;
        typedef _rbtree<key_type, key_compare, allocator_type> _tree_type;
        
        _tree_type _tree;

    public:
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_pointer      const_pointer;
        typedef typename allocator_type::const_reference    const_reference;

        typedef typename _tree_type::const_iterator             iterator;
        typedef typename _tree_type::const_iterator             const_iterator;
        typedef typename _tree_type::const_reverse_iterator     reverse_iterator;
        typedef typename _tree_type::const_reverse_iterator     const_reverse_iterator;
        typedef typename _tree_type::size_type                  size_type;
        typedef typename _tree_type::difference_type            difference_type;

        
        
};

}   // END NAMESPACE FT

#endif  // _SET_BASIC_HPP