/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshakya <sshakya@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:02:15 by sshakya           #+#    #+#             */
/*   Updated: 2022/02/16 17:39:45 by sshakya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/base/_red_black_tree.hpp"
#include "pair.hpp"

namespace ft
{

template <typename _Key, typename _Tp, typename _Cmp = std::less<_Key>, typename _Alloc = std::allocator<ft::pair<const _Key, _Tp> > >
class map
{
    public:
        typedef _Key                                key_type;
        typedef _Tp                                 mapped_type;
        typedef pair<const Key, _Tp>                value_type;
        typedef _Cmp                                key_compare;
        typedef _Alloc                              allocator_type;

        typedef typename _Alloc::reference          reference;
        typedef typename _Alloc::const_reference    const_reference;
    private:
        typedef _Alloc::value_type                  _alloc_value_type;
    
    public:
        class value_compare : public std::binary_functions<value_type, value_type, bool>
        {
            friend class map<_Key, _Tp, _Cmp, _Alloc>;
            protected:
                _Cmp    comp;
                value_compare(_Cmp val) : comp(val) {}
            public:
                bool operator()(const value_type &x, const value_type &y) const
                {
                    return comp(x.first, y.first);
                }
        };

        _rbtree<_Tp, _Cmp, _Alloc>  tree;

};

}   // END NAMESPACE FT